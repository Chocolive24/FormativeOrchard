#pragma once

#include "../month/Month.h"

enum class FruitName
{
	CHERRY,
	APPLE,
	PEAR,
};

enum class HarvestState
{
	READY,
	NOTREADY,
	HARVESTED,
};

class Tree
{
private:

	FruitName _fruitName;
	int _fruitNbr;
	double _fruitWeight;
	int _minNbrOfFruits;
	int _maxNbrOfFruits;

	Month _startHarvestMonth;
	Month _endHarvestMonth;

	int _maxCurrentFruits;

	HarvestState _harvestState = HarvestState::NOTREADY;

	bool _isDead = false;

public:

	// --------------------------------------------------------------------------------------------------

	Tree(FruitName fruitName, int fruitNbr, double fruitWeight, 
		int minNbrOfFruits, int maxNbrOfFruits, 
		Month startHarvestMonth, Month endHarvestMonth);

	// --------------------------------------------------------------------------------------------------

	// Getter and setters.
	FruitName GetFruitName() { return _fruitName; }

	int GetFruitNbr() { return _fruitNbr; }
	int SetFruitNbr(int minFruit, int maxFruit);

	double GetFruitWeight() { return _fruitWeight; }

	HarvestState GetHarvestState() { return _harvestState; }
	HarvestState SetHarvestState(HarvestState harvestState) { return _harvestState = harvestState; }

	// --------------------------------------------------------------------------------------------------

	// Methods for growing trees and harvest their fruits.
	void Grow(Month currentMonth);
	double Harvest(Month currentMonth);
};

// ----------------------------------------------------------------------------------------------------------------------

class CherryTree : public Tree
{
public:

	CherryTree() : Tree(FruitName::CHERRY, 0, 5, 
						45000, 60000, 
						Month::MAY, Month::JUNE){}
};

// ----------------------------------------------------------------------------------------------------------------------

class AppleTree : public Tree
{
public:

	AppleTree() : Tree(FruitName::APPLE, 0, 150,
					   600, 850,
					   Month::SEPTEMBER, Month::NOVEMBER){}
};

// ----------------------------------------------------------------------------------------------------------------------

class PearTree : public Tree
{
public:

	PearTree() : Tree(FruitName::PEAR, 0, 90,
					  1600, 2500,
					  Month::OCTOBER, Month::NOVEMBER){}
};

// ----------------------------------------------------------------------------------------------------------------------