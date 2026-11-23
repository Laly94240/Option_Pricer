#pragma once

class Option
{
public:
	Option(double expiry);
	virtual ~Option() = default;
	//voir pour mettre const vu que ça modif pas l'attribut passée en paramètres
	virtual double payoff(double) const = 0;
	double getExpiry() const;

private:
	double _expiry;
};
