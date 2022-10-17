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

void Game::PlayGame()
{
	SetUpTrees();

	while (true)
	{
		std::cout << "Current Month : " << GetCurrentMonthAsString() << std::endl << std::endl;

		std::cout << "Objective of fruit weight for this year : "
			<< GetWeightToWin() << "kg" << std::endl << std::endl;

		int totalFruits = 0;
		int totalOfCherries = 0;
		int totalOfApples = 0;
		int totalOfPears = 0;
		double totalWeight = 0.0;

		std::string cherryTreeHarvestState;
		std::string appleTreeHarvestState;
		std::string pearTreeHarvestState;

		for (auto& tree : _trees)
		{
			tree.Grow(GetCurrentMonth());

			tree.CheckHarvestState(GetCurrentMonth());

			if (tree.GetFruitName() == "cherries")
			{
				totalOfCherries += tree.GetFruitNbr();
				cherryTreeHarvestState = tree.SetHarvestState();
			}

			if (tree.GetFruitName() == "apples")
			{
				totalOfApples += tree.GetFruitNbr();
				appleTreeHarvestState = tree.SetHarvestState();
			}

			if (tree.GetFruitName() == "pears")
			{
				totalOfPears += tree.GetFruitNbr();
				pearTreeHarvestState = tree.SetHarvestState();
			}

			if (tree.GetHarvestState() == "READY")
			{
				totalFruits += tree.GetFruitNbr();
				totalWeight += tree.GetFruitNbr() * (tree.GetFruitWeight() / 1000.0);
			}

		}

		std::cout << "Total of cherries : " << totalOfCherries << " " << cherryTreeHarvestState << std::endl;
		std::cout << "Total of apples   : " << totalOfApples << " " << appleTreeHarvestState << std::endl;
		std::cout << "Total of pears    : " << totalOfPears << " " << pearTreeHarvestState << std::endl;
		std::cout << std::endl << "Total of fruits ready to be harvested: " << totalFruits << std::endl;
		std::cout << std::endl << "Total fruits weight if fruits are harvested now : " << totalWeight << "kg"
			<< " / " << GetWeightToWin() << "kg" << std::endl;

		std::cout << std::endl << "Nbr of harvest : " << GetHarvestNbr();

		ShowAndDoTheActions(GetCurrentMonth(), _trees);
	}
}

bool Game::CheckIfHarvestIsPossible()
{
	if (_harvestNbr > 0)
	{
		return true;
	}

	return false;
}

void Game::ShowAndDoTheActions(Month currentMonth, std::vector<Tree>& trees)
{
	std::cout << std::endl << "You can harvest your fruits by typing [1]" << std::endl;
	std::cout << "Tap enter to go to the next month." << std::endl;

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
		}

		else if (keyPressed == '1' && !CheckIfHarvestIsPossible())
		{
			std::cout << "You can't harvest anymore." << std::endl;
		}

	} while (keyPressed != 13);
	

}


Month Game::GoToNextMonth(Month currentMonth)
{
	if (currentMonth == Month::DECEMBER)
	{
		_harvestNbr += 1;
		currentMonth = Month::NEWYEAR;
	}

	int value = (int)currentMonth;
	value++;
	currentMonth = static_cast<Month>(value);
	system("cls");

	
	return currentMonth;
}

double Game::Harvest(Month currentMonth, std::vector<Tree>& trees)
{
	// char keyPressed = Utility::GetKey();

	double totalFruitsWeight = 0.0;

	if (CheckIfHarvestIsPossible())
	{

		for (auto& tree : trees)
		{
			totalFruitsWeight += tree.Harvest(currentMonth);

			//totalFruitsWeight = Harvest(currentMonth, trees);
		}

		std::cout << "Your harvest weight : " << totalFruitsWeight << "kg" << std::endl;
		_harvestNbr -= 1;
	}

	return totalFruitsWeight;
}
