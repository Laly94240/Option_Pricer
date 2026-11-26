#pragma once
#include "Option.h"
#include "BinaryTree.h"

class CRRPricer
{
private:
	Option* _option;
	// N
	int _depth; 
	// S0
	double _asset_price;  
	// U
	double _up;       
	// D
	double _down;    
	// R
	double _interest_rate; 
	// used in the compute method = (R - D) / (U - D)
	double _q;             

	BinaryTree<double> _tree; // _tree(n, i) = H(n, i)
	// To see if the tree is already computed, false by defaut
	bool _computed;

	double stockPrice(int n, int i) const; // S(n, i) = S0 (1+U)^i (1+D)^(n-i)

public:
	CRRPricer(Option* option, int depth, double asset_price, double up, double down, double interest_rate);

	void compute();
	double get(int, int);
	double operator()(bool closed_form = false);
};
