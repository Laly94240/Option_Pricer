#pragma once
#include "EuropeanVanillaOption.h"

class CallOption : public EuropeanVanillaOption
{
public:
	CallOption(double expiry, double strike);
	optionType getOptionType() override;
	double payoff(double) const override;
};

