#include "PutOption.h"
#include <algorithm>
using namespace std;

PutOption::PutOption(double expiry, double strike) : EuropeanVanillaOption(expiry, strike) {}

optionType PutOption::getOptionType() const
{
	return Put;
}

double PutOption::payoff(double spotPrice) const
{
	return max(getStrike() - spotPrice, 0.0);
}
