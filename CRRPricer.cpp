#include "CRRPricer.h"
#include <cmath>
#include <stdexcept>

using namespace std;

CRRPricer::CRRPricer(Option* option, int depth, double asset_price, double up, double down, double interest_rate)
	: _option(option), _depth(depth), _asset_price(asset_price), _up(up), _down(down), _interest_rate(interest_rate), _computed(false)
{
	// Here we check for the basic conditions 
	if (_option == nullptr)
		throw invalid_argument("Option cannot be null");
	if (depth < 0)
		throw invalid_argument("Depth must be nonnegative");
	if (asset_price <= 0)
		throw invalid_argument("Asset price must be positive");
	if (down <= -1.0)
		throw invalid_argument("Down factor D must be greater than -1");

	// Condition to see if there is arbitrage: D < R < U 
	// If R >= U the option is never worth more than the risk free rate
	// If R <= D the option is always worth more than the risk free rate
	if (!(down < interest_rate && interest_rate < up))
		throw invalid_argument("Arbitrage detected: the condition D < R < U is not satisfied");

	_q = (interest_rate - down) / (up - down);

	_tree.setDepth(depth);
}

double CRRPricer::stockPrice(int n, int i) const
{
	return _asset_price * pow(1.0 + _up, i) * pow(1.0 + _down, n - i);
}

void CRRPricer::compute()
{
	// Payoffs at maturity: H(N, i) = h(S(N, i))
	for (int i = 0; i <= _depth; ++i)
		_tree.setNode(_depth, i, _option->payoff(stockPrice(_depth, i)));

	// Backward induction: H(n, i) = (q H(n+1, i+1) + (1-q) H(n+1, i)) / (1+R)
	for (int n = _depth - 1; n >= 0; --n)
	{
		for (int i = 0; i <= n; ++i)
		{
			double value = (_q * _tree.getNode(n + 1, i + 1) + (1.0 - _q) * _tree.getNode(n + 1, i))
				/ (1.0 + _interest_rate);
			_tree.setNode(n, i, value);
		}
	}
	_computed = true;
}

double CRRPricer::get(int n, int i)
{
	if (n < 0 || n > _depth || i < 0 || i > n)
		throw out_of_range("Invalid node (n, i): need 0 <= n <= N and 0 <= i <= n");

	if (!_computed)
		compute();
	return _tree.getNode(n, i);
}

double CRRPricer::operator()(bool closed_form)
{
	if (!closed_form)
	{
		if (!_computed)
			compute();
		return _tree.getNode(0, 0);
	}

	// H(0,0) = 1/(1+R)^N * sum_i N!/(i!(N-i)!) q^i (1-q)^(N-i) h(S(N,i))
	// The binomial coefficient is computed via lgamma to avoid overflow.
	double sum = 0.0;
	for (int i = 0; i <= _depth; ++i)
	{
		double logCoeff = lgamma(_depth + 1.0) - lgamma(i + 1.0) - lgamma(_depth - i + 1.0);
		double weight = exp(logCoeff + i * log(_q) + (_depth - i) * log(1.0 - _q));
		sum += weight * _option->payoff(stockPrice(_depth, i));
	}
	return sum / pow(1.0 + _interest_rate, _depth);
}
