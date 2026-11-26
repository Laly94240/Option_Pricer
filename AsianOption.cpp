#include "AsianOption.h"
#include <iostream>
#include <vector> 
#include <string>

AsianOption::AsianOption(vector<double> TimeSteps):Option(TimeSteps.back()) {
	this->TimeSteps = TimeSteps;
}
vector<double> AsianOption:: getTimeSteps() {
	return TimeSteps;
}

double AsianOption:: payoffPath(std::vector<double> path) {
	double sum = 0;
	int n = path.size();
	for(int i=0; i<n; i++) {
		sum += path[i];
	}
	double moyenne = sum / n;
	return payoff(moyenne);
}



