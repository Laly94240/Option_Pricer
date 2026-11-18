#include "PutOption.h"
#include <algorithm>
using namespace std;

optionType PutOption::getOptionType()
{
	return Put;
}

PutOption::PutOption(double expiry, double strike) : EuropeanVanillaOption(expiry, strike) {}

double PutOption::payoff(double spotPrice) const
{
	return max(getStrike() - spotPrice, 0.0);
}