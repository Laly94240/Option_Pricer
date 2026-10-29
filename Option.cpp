#include "Option.h"
#include <iostream>

Option::Option(double expiry)
{
	_expiry = expiry;
}

double Option::getExpiry()
{
	return _expiry;
}
