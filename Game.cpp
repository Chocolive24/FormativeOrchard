#include "Game.h"

#include <iostream>

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

bool Game::CheckHarvestMonth(Month currentMonth)
{
	if (_harvestNbr > 0)
	{
		_harvestNbr -= 0;
		return true;
	}

	return false;
}


Month Game::GoToNextMonth(Month currentMonth, char key, std::vector<Tree>& trees)
{
	if (currentMonth == Month::DECEMBER)
	{
		currentMonth = Month::NEWYEAR;
	}

	if (key == 13)
	{
		int value = (int)currentMonth;
		value++;
		currentMonth = static_cast<Month>(value);
		system("cls");

	}

	else if (key == '1' && CheckHarvestMonth(currentMonth))
	{
		double totalFruitsWeight = Harvest(trees);
		std::cout << totalFruitsWeight << "kg" << std::endl;
	}

	return currentMonth;
}

double Game::Harvest(std::vector<Tree>& trees)
{
	double totalFruitsWeight = 0.0;

	for (auto& tree : trees)
	{
		totalFruitsWeight += tree.Harvest();
	}

	return totalFruitsWeight;
}
