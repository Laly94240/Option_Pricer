#include "PutOption.h"
#include <algorithm>

double PutOption::payoff(double z)
{
	return std::max(_strike - z, 0.0);
}

optionType PutOption::getOptionType() const
{
	return Put;
}