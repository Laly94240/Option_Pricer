#pragma once
#include "Option.h"

using namespace std;

class CRRPricer
{
public:
	CRRPricer(Option* option, int depth, double asset_price, double up, double down, double interest_rate);
};

