#pragma once
#include <random>

#include "Month.h"

class Tree
{
protected:

	std::string _fruitName;
	int _fruitNbr;
	double _fruitWeight;
	int _minNbrOfFruits;
	int _maxNbrOfFruits;
	Month _startHarvestMonth;
	Month _endHarvestMonth;

	int _maxCurrentFruits;


public:

	Tree(std::string fruitName, int fruitNbr, double fruitWeight, 
		int minNbrOfFruits, int maxNbrOfFruits, 
		Month startHarvestMonth, Month endHarvestMonth);

	std::string GetFruitName() { return _fruitName; }
	int GetFruitNbr() { return _fruitNbr; }
	double GetFruitWeight() { return _fruitWeight; }


	//Month GetMonth() { return _growingMonth; }

	int SetFruitNbr(int minFruit, int maxFruit);
	void Grow(Month currentMonth);
	double Harvest();


};

class CherryTree : public Tree
{
public:
	CherryTree() : Tree("cherries", 0, 5, 
						45000, 60000, 
						Month::MAY, Month::JUNE){}
};

class AppleTree : public Tree
{
public:
	AppleTree() : Tree("apples", 0, 150,
					   600, 850,
					   Month::SEPTEMBER, Month::NOVEMBER){}
};

class PearTree : public Tree
{
public:
	PearTree() : Tree("pears", 0, 90,
					  1600, 2500,
					  Month::OCTOBER, Month::NOVEMBER){}
};