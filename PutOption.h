#pragma once
#include "EuropeanVanillaOption.h"
class PutOption : public EuropeanVanillaOption
{
private:
	optionType getOptionType() override;
};

