#include "CallOption.h"
#include <algorithm>
using namespace std;

double CallOption::payoff(double z)
{
	return std::max(z - _strike, 0.0);
}

optionType CallOption::getOptionType() const
{
	return Call;
}

CallOption::CallOption(double expiry, double strike) : EuropeanVanillaOption(expiry, strike) {}

double CallOption::payoff(double spotPrice) const
{
	return max(spotPrice - getStrike(), 0.0);
}