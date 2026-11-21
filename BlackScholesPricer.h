#pragma once
#include "EuropeanVanillaOption.h"

class BlackScholesPricer
{
private:
	EuropeanVanillaOption* _option;
	double _asset_price;
	double _interest_rate;
	double _volatility;

	double normalCDF(double x) const;

public:
	BlackScholesPricer(EuropeanVanillaOption* option, double asset_price, double interest_rate, double volatility);
	double operator()();
	double delta();
};