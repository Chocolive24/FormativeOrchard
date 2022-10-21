#pragma once

#include "../Month/Month.h"
#include "../tree/Tree.h"

#include <string>
#include <vector>

class Game

{
private:

	bool _game = true;

	Month _currentMonth = Month::JANUARY;

	int _harvestNbr = 1;

	// temporary attributes that are update each month.
	int _tmpTotalFruits     = 0;
	int _tmpTotalOfCherries = 0;
	int _tmpTotalOfApples   = 0;
	int _tmpTotalOfPears    = 0;
	double _tmpTotalWeight  = 0.0;

	HarvestState _cherryTreeHarvestState = HarvestState::NOTREADY;
	HarvestState _appleTreeHarvestState  = HarvestState::NOTREADY;
	HarvestState _pearTreeHarvestState   = HarvestState::NOTREADY;

	double _totalFruitsWeight = 0.0;

	int _weightToWin = 2000;

	std::vector<Tree> _trees;

public:

	// Create the trees and add them in the vector _trees.
	void SetUpTrees();

	// Change the current month to the next month.
	void SetMonth(Month newMonth) { _currentMonth = newMonth; }
	Month GoToNextMonth(Month currentMonth);

	// Getters.
	Month GetCurrentMonth() { return _currentMonth; }
	std::string GetCurrentMonthAsString();
	std::string GetHarvestStateAsString(HarvestState harvestState);
	int GetHarvestNbr() { return _harvestNbr; }
	int GetWeightToWin() { return _weightToWin; }

	bool CheckIfHarvestIsPossible() { return _harvestNbr > 0; }

	// Update and display the games information.
	void UpdateTreesInformation();
	void DisplayGameInformation();

	// Do the action in link with the user input.
	void DoTheActions(Month currentMonth, std::vector<Tree>& trees);

	double Harvest(Month currentMonth, std::vector<Tree>& trees);

	// Main loop of the game.
	void PlayGame();

	// Display the report of the year and restart or not the game.
	void DisplayYearReport();
	void Restart();
};