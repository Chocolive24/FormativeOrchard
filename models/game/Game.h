#pragma once
#include "../tree/Tree.h"
#include "../Month/Month.h"

class Game

{
private:

	bool _game = true;

	Month _currentMonth = Month::JANUARY;
	int _harvestNbr = 1;

	int _tmpTotalFruits = 0;
	int _tmpTotalOfCherries = 0;
	int _tmpTotalOfApples = 0;
	int _tmpTotalOfPears = 0;
	double _tmpTotalWeight = 0.0;

	std::string _cherryTreeHarvestState;
	std::string _appleTreeHarvestState;
	std::string _pearTreeHarvestState;

	double _totalFruitsWeight = 0.0;

	int _weightToWin = 2000;

	std::vector<Tree> _trees;

public:

	void SetUpTrees();

	void SetMonth(Month newMonth);

	Month GetCurrentMonth() { return _currentMonth; }
	std::string GetCurrentMonthAsString();
	int GetHarvestNbr() { return _harvestNbr; }
	int GetWeightToWin() { return _weightToWin; }

	

	void UpdateTreesInformations();
	void DisplayInformations();

	void PlayGame();

	bool CheckIfHarvestIsPossible() { return _harvestNbr > 0; }

	void ShowAndDoTheActions(Month currentMonth, std::vector<Tree>& trees);

	Month GoToNextMonth(Month currentMonth);

	double Harvest(Month currentMonth, std::vector<Tree>& trees);

	void DisplayYearReport();
	void Restart();

};