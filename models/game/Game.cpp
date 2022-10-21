#include "Game.h"
#include "../utility/Utility.h"

#include <iostream>


// ----------------------------------------------------------------------------------------------------------------------

void Game::SetUpTrees()
{
	// ----------------------------------------------------------------------------------------------

	// Ask the user how many types of trees he wants.
	// There is no limit because the program is more like a simulation than a game.
	std::cout << "How many Cherry Tree do you want ?" << std::endl;
	int nbrOfCherryTree = std::stoi(Utility::GetNumberTyped());

	std::cout << "How many Apple Tree do you want ?" << std::endl;
	int nbrOfAppleTree = std::stoi(Utility::GetNumberTyped());

	std::cout << "How many Pear Tree do you want ?" << std::endl;
	int nbrOfPearTree = std::stoi(Utility::GetNumberTyped());

	system("cls");

	// ----------------------------------------------------------------------------------------------

	// Add the trees in the vector _trees.
	for (int i = 0; i < nbrOfCherryTree; i++)
	{
		CherryTree cherryTree;
		_trees.emplace_back(cherryTree);
	}

	for (int i = 0; i < nbrOfAppleTree; i++)
	{
		AppleTree appleTree;
		_trees.emplace_back(appleTree);
	}

	for (int i = 0; i < nbrOfPearTree; i++)
	{
		PearTree pearTree;
		_trees.emplace_back(pearTree);
	}
}

// ----------------------------------------------------------------------------------------------------------------------

Month Game::GoToNextMonth(Month currentMonth)
{
	int value = (int)currentMonth;
	value++;
	currentMonth = static_cast<Month>(value);

	return currentMonth;
}

// ----------------------------------------------------------------------------------------------------------------------

std::string Game::GetCurrentMonthAsString()
{
	switch (_currentMonth)
	{
	case Month::JANUARY:
		return "January";
	case Month::FEBRUARY:
		return "February";
	case Month::MARCH:
		return "March";
	case Month::APRIL:
		return "April";
	case Month::MAY:
		return "May";
	case Month::JUNE:
		return "June";
	case Month::JULY:
		return "July";
	case Month::AUGUST:
		return "August";
	case Month::SEPTEMBER:
		return "September";
	case Month::OCTOBER:
		return "October";
	case Month::NOVEMBER:
		return "November";
	case Month::DECEMBER:
		return "December";
	}
}

// ----------------------------------------------------------------------------------------------------------------------

std::string Game::GetHarvestStateAsString(HarvestState harvestState)
{
	switch (harvestState)
	{
	case HarvestState::READY:
		return "READY";
	case HarvestState::NOTREADY:
		return "NOT READY";
	case HarvestState::HARVESTED:
		return "HARVESTED";
	}
}

// ----------------------------------------------------------------------------------------------------------------------

// Update the information about the tree each month.
void Game::UpdateTreesInformation()
{
	// reset the temporary trees information.
	_tmpTotalFruits		= 0;
	_tmpTotalOfCherries = 0;
	_tmpTotalOfApples	= 0;
	_tmpTotalOfPears	= 0;
	_tmpTotalWeight		= 0.0;

	for (auto& tree : _trees)
	{
		// The tree grows and actions are happening or not in relation to the current month.
		tree.Grow(GetCurrentMonth());

		// ----------------------------------------------------------------------------------------

		// Checks which tree type is being updated with its fruit name.
		// Do the correct updates to the correct tree.
		if (tree.GetFruitName() == FruitName::CHERRY)
		{
			_tmpTotalOfCherries += tree.GetFruitNbr();
			_cherryTreeHarvestState = tree.GetHarvestState();
		}

		else if (tree.GetFruitName() == FruitName::APPLE)
		{
			_tmpTotalOfApples += tree.GetFruitNbr();
			_appleTreeHarvestState = tree.GetHarvestState();
		}

		else if (tree.GetFruitName() == FruitName::PEAR)
		{
			_tmpTotalOfPears += tree.GetFruitNbr();
			_pearTreeHarvestState = tree.GetHarvestState();
		}

		// ----------------------------------------------------------------------------------------

		// If the tree is ready to be harvested, update the temporary total of fruits and fruits weight.
		if (tree.GetHarvestState() == HarvestState::READY)
		{
			_tmpTotalFruits += tree.GetFruitNbr();
			_tmpTotalWeight += tree.GetFruitNbr() * (tree.GetFruitWeight() / 1000.0);
		}
	}
}

// ----------------------------------------------------------------------------------------------------------------------

void Game::DisplayGameInformation()
{
	system("cls");

	// ------------------------------------------------------------------------------------------------------

	// The current month.
	std::cout << "Current Month : " << GetCurrentMonthAsString() << std::endl << std::endl;

	// The objective of fruit weight of the year.
	std::cout << "Objective of fruit weight for this year : "
		<< GetWeightToWin() << "kg" << std::endl << std::endl;

	// ------------------------------------------------------------------------------------------------------

	// Total number of each fruit.
	std::cout << "Total of cherries : " << _tmpTotalOfCherries << " "
			  << GetHarvestStateAsString(_cherryTreeHarvestState) << std::endl;

	std::cout << "Total of apples   : " << _tmpTotalOfApples   << " "
			  << GetHarvestStateAsString(_appleTreeHarvestState) << std::endl;

	std::cout << "Total of pears    : " << _tmpTotalOfPears    << " "
			  << GetHarvestStateAsString(_pearTreeHarvestState) << std::endl;

	// ------------------------------------------------------------------------------------------------------

	// Total of fruit ready to be harvested.
	std::cout << std::endl << "Total of fruits ready to be harvested: " << _tmpTotalFruits << std::endl;

	// Total weight if those fruits are harvested.
	std::cout << std::endl << "Total fruits weight if fruits are harvested now : "
			  << _tmpTotalWeight << "kg" << " / " << GetWeightToWin() << "kg" << std::endl << std::endl;

	// ------------------------------------------------------------------------------------------------------

	// Number of harvest and the current fruits weight the player has harvested.
	std::cout << "Nbr of harvest : "	  << GetHarvestNbr() << std::endl;
	std::cout << "Your harvest weight : " << _totalFruitsWeight << "kg" << std::endl << std::endl;

	// ------------------------------------------------------------------------------------------------------

	// Display the possible actions that the player can do.
	std::cout << "You can harvest your fruits by typing [1]" << std::endl;
	std::cout << "Tap enter to go to the next month."	     << std::endl;
}

// ----------------------------------------------------------------------------------------------------------------------

void Game::DoTheActions(Month currentMonth, std::vector<Tree>& trees)
{
	char keyPressed;

	do
	{
		keyPressed = Utility::GetKey();

		// If the key pressed is "enter".
		if (keyPressed == 13)
		{
			SetMonth(GoToNextMonth(currentMonth));
		}

		if (keyPressed == '1' && CheckIfHarvestIsPossible())
		{
			Harvest(currentMonth, trees);
			
			UpdateTreesInformation();
			DisplayGameInformation();
		}

		else if (keyPressed == '1' && !CheckIfHarvestIsPossible())
		{
			std::cout << "You can't harvest anymore." << std::endl;
		}

	} while (keyPressed != 13);
}

// ----------------------------------------------------------------------------------------------------------------------

double Game::Harvest(Month currentMonth, std::vector<Tree>& trees)
{
	if (CheckIfHarvestIsPossible())
	{
		// For each tree, harvest it's fruits and add them to the total of fruits weight.
		for (auto& tree : trees)
		{
			_totalFruitsWeight += tree.Harvest(currentMonth);
		}

		_harvestNbr = 0;
	}

	return _totalFruitsWeight;
}

// ----------------------------------------------------------------------------------------------------------------------

// Game loop.
void Game::PlayGame()
{
	SetUpTrees();

	while (_game)
	{
		UpdateTreesInformation();

		DisplayGameInformation();

		DoTheActions(GetCurrentMonth(), _trees);

		DisplayYearReport();
	}
}

// ----------------------------------------------------------------------------------------------------------------------

void Game::DisplayYearReport()
{
	if (GetCurrentMonth() == Month::ENDYEAR)
	{
		system("cls");

		std::cout << "Report of the year :" << std::endl << std::endl;

		_totalFruitsWeight >= _weightToWin ?
			std::cout << "You Win !!! Objective achieved !!!   " << std::endl
			:
			std::cout << "You lost... Objective not achieved..." << std::endl;

		std::cout << _totalFruitsWeight << "kg"
				  << " / " << GetWeightToWin() << "kg" << std::endl << std::endl;

		Restart();
	}
}

// ----------------------------------------------------------------------------------------------------------------------

void Game::Restart()
{
	std::cout << "===Restart?=== " << std::endl;
	std::cout << "[1] yes.       " << std::endl;
	std::cout << "[2] no.        " << std::endl;
	std::cout << "===============" << std::endl;

	char key = Utility::GetKey();

	if (key == '1')
	{
		_trees.clear();
		SetUpTrees();
		_harvestNbr = 1;
		_currentMonth = Month::JANUARY;
		_totalFruitsWeight = 0;
	}

	else
	{
		_game = false;
	}
}

// ----------------------------------------------------------------------------------------------------------------------