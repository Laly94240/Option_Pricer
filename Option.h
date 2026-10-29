#pragma once

class Option
{
public :
	Option(double expiry);
	//voir pour mettre const vu que ça modif pas l'attribut passée en paramètres
	virtual double payoff(double) = 0;
private:
	double _expiry;
	double getExpiry();

};