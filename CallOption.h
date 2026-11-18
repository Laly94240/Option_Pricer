#pragma once
#include "EuropeanVanillaOption.h"

class CallOption : public EuropeanVanillaOption
{
private :
	using EuropeanVanillaOption::EuropeanVanillaOption;
	double payoff(double z) override;
	optionType getOptionType() const override;
};

