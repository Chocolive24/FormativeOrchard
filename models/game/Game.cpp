#include "Game.h"

#include <iostream>
#include "../utility/Utility.h"

void Game::SetUpTrees()
{
	int nbrOfCherryTree;
	std::cout << "How many Cherry Tree do you want ?" << std::endl;
	std::cin >> nbrOfCherryTree;

	int nbrOfAppleTree;
	std::cout << "How many Apple Tree do you want ?" << std::endl;
	std::cin >> nbrOfAppleTree;

	int nbrOfPearTree;
	std::cout << "How many Pear Tree do you want ?" << std::endl;
	std::cin >> nbrOfPearTree;

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

	system("cls");
}

void Game::SetMonth(Month newMonth)
{
	_currentMonth = newMonth;
}


std::string Game::GetCurrentMonthAsString()
{
	switch (_currentMonth)
	{
	case Month::NEWYEAR:
		return "Happy New Year !!!";
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

void Game::DisplayInformations()
{
	system("cls");

	std::cout << "Current Month : " << GetCurrentMonthAsString() << std::endl << std::endl;

	std::cout << "Objective of fruit weight for this year : "
		<< GetWeightToWin() << "kg" << std::endl << std::endl;

	std::cout << "Total of cherries : " << _tmpTotalOfCherries << " " << _cherryTreeHarvestState << std::endl;
	std::cout << "Total of apples   : " << _tmpTotalOfApples << " " << _appleTreeHarvestState << std::endl;
	std::cout << "Total of pears    : " << _tmpTotalOfPears << " " << _pearTreeHarvestState << std::endl;
	std::cout << std::endl << "Total of fruits ready to be harvested: " << _tmpTotalFruits << std::endl;
	std::cout << std::endl << "Total fruits weight if fruits are harvested now : " << _tmpTotalWeight << "kg"
		<< " / " << GetWeightToWin() << "kg" << std::endl;

	std::cout << std::endl << "Nbr of harvest : " << GetHarvestNbr() << std::endl;
	std::cout << "Your harvest weight : " << _totalFruitsWeight << "kg" << std::endl << std::endl;

	std::cout << "You can harvest your fruits by typing [1]" << std::endl;
	std::cout << "Tap enter to go to the next month." << std::endl;
}

void Game::UpdateTreesInformations()
{
	_tmpTotalFruits = 0;
	_tmpTotalOfCherries = 0;
	_tmpTotalOfApples = 0;
	_tmpTotalOfPears = 0;
	_tmpTotalWeight = 0.0;

	for (auto& tree : _trees)
	{
		tree.Grow(GetCurrentMonth());

		tree.CheckHarvestState(GetCurrentMonth());

		if (tree.GetFruitName() == "cherries")
		{
			_tmpTotalOfCherries += tree.GetFruitNbr();

			//if (tree.GetFruitNbr() == 0)
			//{
			//	_tmpTotalOfCherries = 0;
			//	//_cherryTreeHarvestState = "HARVESTED";
			//}

			_cherryTreeHarvestState = tree.SetHarvestState();
		}

		if (tree.GetFruitName() == "apples")
		{
			_tmpTotalOfApples += tree.GetFruitNbr();

			/*if (tree.GetFruitNbr() == 0)
			{
				_tmpTotalOfApples = 0;
			}*/

			_appleTreeHarvestState = tree.SetHarvestState();
		}

		if (tree.GetFruitName() == "pears")
		{
			_tmpTotalOfPears += tree.GetFruitNbr();

			/*if (tree.GetFruitNbr() == 0)
			{
				_tmpTotalOfPears = 0;
			}*/

			_pearTreeHarvestState = tree.SetHarvestState();
		}

		if (tree.GetHarvestState() == "READY")
		{
			_tmpTotalFruits += tree.GetFruitNbr();
			_tmpTotalWeight += tree.GetFruitNbr() * (tree.GetFruitWeight() / 1000.0);
		}

	}
}

void Game::PlayGame()
{
	SetUpTrees();

	while (_game)
	{
		UpdateTreesInformations();

		DisplayInformations();

		ShowAndDoTheActions(GetCurrentMonth(), _trees);

		DisplayYearReport();
	}
}

void Game::ShowAndDoTheActions(Month currentMonth, std::vector<Tree>& trees)
{
	char keyPressed;

	do
	{
		keyPressed = Utility::GetKey();

		if (keyPressed == 13)
		{
			SetMonth(GoToNextMonth(currentMonth));
		}

		if (keyPressed == '1' && CheckIfHarvestIsPossible())
		{
			Harvest(currentMonth, trees);
			
			UpdateTreesInformations();
			DisplayInformations();
		}

		else if (keyPressed == '1' && !CheckIfHarvestIsPossible())
		{
			std::cout << "You can't harvest anymore." << std::endl;
		}

	} while (keyPressed != 13);
}


Month Game::GoToNextMonth(Month currentMonth)
{
	int value = (int)currentMonth;
	value++;
	currentMonth = static_cast<Month>(value);
	
	return currentMonth;
}

double Game::Harvest(Month currentMonth, std::vector<Tree>& trees)
{
	if (CheckIfHarvestIsPossible())
	{

		for (auto& tree : trees)
		{
			_totalFruitsWeight += tree.Harvest(currentMonth);
		}

		_harvestNbr = 0;
	}

	return _totalFruitsWeight;
}

void Game::DisplayYearReport()
{
	if (GetCurrentMonth() == Month::ENDYEAR)
	{
		system("cls");
		std::cout << "Report of the year :" << std::endl << std::endl;

		if (_totalFruitsWeight >= _weightToWin)
		{
			std::cout << "You Win !!! Objective achieved !!!" << std::endl;
			std::cout << _totalFruitsWeight << "kg"
				<< " / " << GetWeightToWin() << "kg" << std::endl << std::endl;
		}

		else
		{
			std::cout << "You lost... Objective not achieved..." << std::endl;
			std::cout << _totalFruitsWeight << "kg"
				<< " / " << GetWeightToWin() << "kg" << std::endl << std::endl;
		}

		Restart();
	}
}

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
