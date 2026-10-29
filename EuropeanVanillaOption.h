#pragma once
#include "Option.h"

enum optionType{Call,Put};

class EuropeanVanillaOption : public Option
{
public:
	EuropeanVanillaOption(double expiry, double strike);
	virtual optionType getOptionType() = 0;
private:
	double _strike;
};