#pragma once
#include "Option.h"
#include <vector>

class AsianOption : public Option {
public:
	AsianOption(vector<double> TimeSteps);
	vector<double> getTimeSteps();
	double payoffPath(std::vector<double> path) override;
	bool isAsianOption() override;
private:
	vector<double> TimeSteps;
};

