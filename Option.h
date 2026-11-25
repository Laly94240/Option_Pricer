#pragma once

class Option
{
public:
	Option(double expiry);
	virtual ~Option() = default;
	virtual double payoff(double) const = 0;
	double getExpiry() const;
private:
	double _expiry;
};
