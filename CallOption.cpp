#include "CallOption.h"
#include <algorithm>
using namespace std;

CallOption::CallOption(double expiry, double strike) : EuropeanVanillaOption(expiry, strike) {}

optionType CallOption::getOptionType() const
{
	return Call;
}

double CallOption::payoff(double spotPrice) const
{
	return max(spotPrice - getStrike(), 0.0);
}
