#pragma once
#include "EuropeanVanillaOption.h"

class PutOption : public EuropeanVanillaOption
{
public:
	using EuropeanVanillaOption::EuropeanVanillaOption;
	double payoff(double z) override;
	optionType getOptionType() const override;
};
