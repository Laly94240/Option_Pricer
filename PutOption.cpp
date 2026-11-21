#include "PutOption.h"
#include <algorithm>
using namespace std;

double PutOption::payoff(double z)
{
	return max(_strike - z, 0.0);
}

optionType PutOption::getOptionType() const
{
	return Put;
}

PutOption::PutOption(double expiry, double strike) : EuropeanVanillaOption(expiry, strike) {}

double PutOption::payoff(double spotPrice) const
{
	return max(getStrike() - spotPrice, 0.0);
}