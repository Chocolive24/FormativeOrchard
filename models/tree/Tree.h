#pragma once
#include <random>

#include "../month/Month.h"

class Tree
{
private:

	std::string _fruitName;
	int _fruitNbr;
	double _fruitWeight;
	int _minNbrOfFruits;
	int _maxNbrOfFruits;
	Month _startHarvestMonth;
	Month _endHarvestMonth;

	int _maxCurrentFruits;

	bool _readyToBeHarvested = false;
	std::string _harvestState;

public:

	// ------------------------------------------------------------------------------------------------------------------

	Tree(std::string fruitName, int fruitNbr, double fruitWeight, 
		int minNbrOfFruits, int maxNbrOfFruits, 
		Month startHarvestMonth, Month endHarvestMonth);

	// ------------------------------------------------------------------------------------------------------------------

	std::string GetFruitName() { return _fruitName; }
	int GetFruitNbr() { return _fruitNbr; }
	double GetFruitWeight() { return _fruitWeight; }
	std::string GetHarvestState() { return _harvestState; }

	void CheckHarvestState(Month currentMonth);
	std::string SetHarvestState();

	int SetFruitNbr(int minFruit, int maxFruit);
	void Grow(Month currentMonth);
	double Harvest(Month currentMonth);
	// ------------------------------------------------------------------------------------------------------------------

};

class CherryTree : public Tree
{
public:

	CherryTree() : Tree("cherries", 0, 5, 
						45000, 60000, 
						Month::MAY, Month::JUNE){}
};

// ----------------------------------------------------------------------------------------------------------------------

class AppleTree : public Tree
{
public:

	AppleTree() : Tree("apples", 0, 150,
					   600, 850,
					   Month::SEPTEMBER, Month::NOVEMBER){}
};

// ----------------------------------------------------------------------------------------------------------------------

class PearTree : public Tree
{
public:

	PearTree() : Tree("pears", 0, 90,
					  1600, 2500,
					  Month::OCTOBER, Month::NOVEMBER){}
};

// ----------------------------------------------------------------------------------------------------------------------