#pragma once
#include "../tree/Tree.h"
#include "../Month/Month.h"

class Game

{
private:

	Month _currentMonth = Month::JANUARY;
	int _harvestNbr = 12;
	int _weightToWin = 2000;

	std::vector<Tree> _trees;

public:

	void SetUpTrees();

	void SetMonth(Month newMonth);

	Month GetCurrentMonth() { return _currentMonth; }
	std::string GetCurrentMonthAsString();
	int GetHarvestNbr() { return _harvestNbr; }
	int GetWeightToWin() { return _weightToWin; }

	void PlayGame();

	bool CheckIfHarvestIsPossible();

	void ShowAndDoTheActions(Month currentMonth, std::vector<Tree>& trees);

	Month GoToNextMonth(Month currentMonth);

	double Harvest(Month currentMonth, std::vector<Tree>& trees);

};

