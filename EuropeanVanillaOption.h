#pragma once
#include "Option.h"

enum optionType { Call, Put };

class EuropeanVanillaOption : public Option
{
	friend class BlackScholesPricer;

public:
	EuropeanVanillaOption(double expiry, double strike);
	virtual optionType getOptionType() = 0;
	double getStrike() const;
private:
	double _strike;
};