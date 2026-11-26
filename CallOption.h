#pragma once
#include "EuropeanVanillaOption.h"

class CallOption : public EuropeanVanillaOption
{
public:
	CallOption(double expiry, double strike);
	optionType getOptionType() const override;
	double payoff(double) const override;
};
