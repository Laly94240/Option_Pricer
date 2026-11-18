#include "BlackScholesPricer.h"
#include <cmath>
#include <stdexcept>

using namespace std;

BlackScholesPricer::BlackScholesPricer(EuropeanVanillaOption* option, double asset_price, double interest_rate, double volatility)
    : _option(option), _asset_price(asset_price), _interest_rate(interest_rate), _volatility(volatility)
{
    if (_option == nullptr || asset_price < 0 || volatility < 0)
    {
        throw invalid_argument("Option cannot be null, and asset price and volatility must be non negative");
    }
}

double BlackScholesPricer::normalCDF(double x) const
{
    return 0.5 * erfc(-x / sqrt(2.0));
}

double BlackScholesPricer::operator()()
{
    double expiry = _option->getExpiry();
    double strike = _option->_strike;

    double d1 = (log(_asset_price / strike) + (_interest_rate + 0.5 * _volatility * _volatility) * expiry) / (_volatility * sqrt(expiry));
    double d2 = d1 - _volatility * sqrt(expiry);

    if (_option->getOptionType() == optionType::Call)
    {
        return _asset_price * normalCDF(d1) - strike * exp(-_interest_rate * expiry) * normalCDF(d2);
    }
    else
    {
        return strike * exp(-_interest_rate * expiry) * normalCDF(-d2) - _asset_price * normalCDF(-d1);
    }
}

double BlackScholesPricer::delta()
{
    double expiry = _option->getExpiry();
    double strike = _option->_strike;

    double d1 = (log(_asset_price / strike) + (_interest_rate + 0.5 * _volatility * _volatility) * expiry) / (_volatility * sqrt(expiry));

    if (_option->getOptionType() == optionType::Call)
    {
        return normalCDF(d1);
    }
    else
    {
        return normalCDF(d1) - 1.0;
    }
}