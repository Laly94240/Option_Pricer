#include "EuropeanVanillaOption.h"
#include "Option.h"
#include <iostream>
#include <stdexcept>

using namespace std;

EuropeanVanillaOption::EuropeanVanillaOption(double expiry, double strike) : Option(expiry), _strike(strike)
{
    if (expiry < 0 || strike < 0)
    {
        throw invalid_argument("Expiry and strike must be nonnegative");
    }
}