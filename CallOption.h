#pragma once
#include "EuropeanVanillaOption.h"
class CallOption : public EuropeanVanillaOption
{
private :
	optionType getOptionType() override;
};

