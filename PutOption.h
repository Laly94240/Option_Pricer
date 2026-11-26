#pragma once
#include "EuropeanVanillaOption.h"

class PutOption : public EuropeanVanillaOption
{
public:
	PutOption(double expiry, double strike);
	optionType getOptionType() const override;
	double payoff(double) const override;
};
