#include "CallOption.h"
#include <algorithm> 

double CallOption::payoff(double z)
{
	return std::max(z - _strike, 0.0);
}

optionType CallOption::getOptionType() const
{
	return Call;
}