#pragma once
#include "Tree.h"

class Game

{
private:

	Month _currentMonth = Month::JANUARY;
	int _harvestNbr = 1;
	int _weightToWin = 2000;

public:

	void SetMonth(Month newMonth);

	Month GetCurrentMonth() { return _currentMonth; }
	std::string GetCurrentMonthAsString();
	int GetWeightToWin() { return _weightToWin; }

	bool CheckHarvestMonth(Month currentMonth);

	Month GoToNextMonth(Month currentMonth, char key, std::vector<Tree>& trees);

	double Harvest(std::vector<Tree>& trees);

};

