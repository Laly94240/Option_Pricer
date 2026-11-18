#include "CallOption.h"
#include <algorithm>
using namespace std;

optionType CallOption::getOptionType()
{
	return Call;
}

CallOption::CallOption(double expiry, double strike) : EuropeanVanillaOption(expiry, strike) {}

double CallOption::payoff(double spotPrice) const
{
	return max(spotPrice - getStrike(), 0.0);
}