#include "Tree.h"
#include "../utility/Utility.h"

#include <iostream>

// ------------------------------------------------------------------------------------------------------------------

Tree::Tree(std::string fruitName, int fruitNbr, double fruitWeight, int minNbrOfFruits, int maxNbrOfFruits, 
		   Month startHarvestMonth, Month endHarvestMonth)
	: _fruitName(fruitName),
	_fruitNbr(fruitNbr),
	_fruitWeight(fruitWeight),
	_minNbrOfFruits(minNbrOfFruits),
	_maxNbrOfFruits(maxNbrOfFruits),
	_startHarvestMonth(startHarvestMonth),
	_endHarvestMonth(endHarvestMonth) {}

// ------------------------------------------------------------------------------------------------------------------

void Tree::CheckHarvestState(Month currentMonth)
{
	if (_startHarvestMonth == currentMonth)
	{
		_readyToBeHarvested = true;
	}

	if (currentMonth == Month::DECEMBER)
	{
		_readyToBeHarvested = false;
	}
}

std::string Tree::SetHarvestState()
{
	if (!_isDead)
	{
		if (_readyToBeHarvested == true && GetFruitNbr() != 0)
		{
			_harvestState = "READY";
		}

		else if (_readyToBeHarvested == true && GetFruitNbr() == 0)
		{
			_harvestState = "HARVESTED";
		}

		else
		{
			_harvestState = "NOT READY";
		}

		return _harvestState;
	}

	
	if (_readyToBeHarvested)
	{
		_harvestState = "READY";
	}
	
	return _harvestState;
	
}

// ------------------------------------------------------------------------------------------------------------------

int Tree::SetFruitNbr(int minFruit, int maxFruit)
{
	return _fruitNbr = Utility::GetRandomInt(minFruit, maxFruit);
}

// ------------------------------------------------------------------------------------------------------------------

void Tree::Grow(Month currentMonth)
{
	if (currentMonth == Month::APRIL)
	{
		// 5% chance of loss. 
		int harvestLoss = Utility::GetRandomInt(1, 20);

		if (harvestLoss != 1)
		{
			_maxCurrentFruits = SetFruitNbr(_minNbrOfFruits, _maxNbrOfFruits);
		}

		else
		{
			SetTreeToDead(true);
		}
	}

	if(currentMonth > _startHarvestMonth && currentMonth <= _endHarvestMonth)
	{
		if (_fruitNbr > 0)
		{
			_fruitNbr += - (Utility::GetRandomInt(_maxCurrentFruits * 0.03, _maxCurrentFruits * 0.10));
		}
	}

	if (currentMonth == _endHarvestMonth)
	{
		_maxCurrentFruits = _fruitNbr;
	}

	if (currentMonth > _endHarvestMonth)
	{

	if (_fruitNbr > 0)
	{
		const int fruitLoss = _maxCurrentFruits / ((int)Month::DECEMBER - ((int)_endHarvestMonth));
		_fruitNbr += -(fruitLoss);
	}
	}

	if (currentMonth == Month::DECEMBER)
	{
		_fruitNbr = 0;
	}

	//std::cout << "Nbr of " << GetFruitName() << " : " << GetFruitNbr() << std::endl;
}

// ------------------------------------------------------------------------------------------------------------------

// Checks the current month and harvests the trees that are ready for harvest
double Tree::Harvest(Month currentMonth)
{
	double totalFruitsWeight = 0.0;

	if (_readyToBeHarvested == true)
	{
		totalFruitsWeight += static_cast<double>(_fruitNbr) * (_fruitWeight / 1000.0);
		_fruitNbr = 0;
	}

	//totalFruitsWeight += tree.Harvest(currentMonth);
	

	return totalFruitsWeight;
}

// ------------------------------------------------------------------------------------------------------------------