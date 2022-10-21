#include "Tree.h"
#include "../utility/Utility.h"

// ------------------------------------------------------------------------------------------------------------------

int Tree::SetFruitNbr(int minFruit, int maxFruit)
{
	return _fruitNbr = Utility::GetRandomInt(minFruit, maxFruit);
}

// ------------------------------------------------------------------------------------------------------------------

Tree::Tree(FruitName fruitName, int fruitNbr, double fruitWeight, int minNbrOfFruits, int maxNbrOfFruits, 
		   Month startHarvestMonth, Month endHarvestMonth)
	: _fruitName(fruitName),
	_fruitNbr(fruitNbr),
	_fruitWeight(fruitWeight),
	_minNbrOfFruits(minNbrOfFruits),
	_maxNbrOfFruits(maxNbrOfFruits),
	_startHarvestMonth(startHarvestMonth),
	_endHarvestMonth(endHarvestMonth) {}

// ------------------------------------------------------------------------------------------------------------------

void Tree::Grow(Month currentMonth)
{
	if (currentMonth == Month::APRIL)
	{
		// 5% chance of losing all the fruits from the tree. 
		int harvestLoss = Utility::GetRandomInt(1, 20);

		// Create a random number of fruits for the tree.
		if (harvestLoss != 1)
		{
			// New variable that save the current number of fruits on the tree
			// to apply the same percentage of loss during the flowering phase.
			_maxCurrentFruits = SetFruitNbr(_minNbrOfFruits, _maxNbrOfFruits);
		}

		else
		{
			_isDead = true;
		}
	}

	// The tree can be harvested if the current month is the start harvest month of the tree.
	// The harvest state is "READY" only if the tree isn't "HARVESTED" or if it is dead.
	// If we don't put the dead trees in "READY" it will cause display problems if the last tree is dead.
	if (_startHarvestMonth == currentMonth && (GetFruitNbr() != 0 || _isDead))
	{
		SetHarvestState(HarvestState::READY);
	}

	// During the harvest phase, the tree may lose 3 to 10% of its harvest
	if(currentMonth > _startHarvestMonth && currentMonth <= _endHarvestMonth)
	{
		// If the tree didn't lose his fruits in April.
		if (_fruitNbr > 0)
		{
			_fruitNbr += - (Utility::GetRandomInt(_maxCurrentFruits * 0.03, _maxCurrentFruits * 0.10));
		}
	}

	// If it's the end of the harvest phase,
	// update the max current fruits of the tree to its real fruit number.
	if (currentMonth == _endHarvestMonth)
	{
		_maxCurrentFruits = _fruitNbr;
	}

	// If the harvest phase is finished, the descent phase begin.
	if (currentMonth > _endHarvestMonth && _fruitNbr > 0)
	{
		// In this phase, the tree loses its fruits little by little
		// until it loses them all in december
		const int fruitLoss = _maxCurrentFruits / ((int)Month::DECEMBER - ((int)_endHarvestMonth));
		_fruitNbr += -(fruitLoss);
		
	}

	// The winter begin, the tree has no more fruits but nothing happen to it.
	if (currentMonth == Month::DECEMBER)
	{
		_fruitNbr = 0;
		SetHarvestState(HarvestState::NOTREADY);
	}
}

// ------------------------------------------------------------------------------------------------------------------

// Checks the current month and harvests the trees that are ready for harvest
double Tree::Harvest(Month currentMonth)
{
	double totalFruitsWeight = 0.0;

	if (_harvestState == HarvestState::READY)
	{
		totalFruitsWeight += static_cast<double>(_fruitNbr) * (_fruitWeight / 1000.0);
		_fruitNbr = 0;
		SetHarvestState(HarvestState::HARVESTED);
	}

	return totalFruitsWeight;
}

// ------------------------------------------------------------------------------------------------------------------