#include "AppleTree.h"

#include <conio.h>
#include <iostream>

//int AppleTree::SetFruitNbr(int minFruit, int maxFruit)
//{
//	return Tree::SetFruitNbr(minFruit, maxFruit);
//}
//
//void AppleTree::Grow()
//{
//		std::cout << "Current Month : " << GetMonthAsString() << std::endl << std::endl;
//
//		if (_growingMonth == Month::SEPTEMBER)
//		{
//			// 5% chance of loss. 
//			int harvestLoss = GetRandomInt(1, 20);
//
//			if (harvestLoss != 1)
//			{
//				SetFruitNbr(600, 850);
//			}
//
//			else
//			{
//				std::cout << "Sadly your cherry tree didn't survived..." << std::endl;
//			}
//
//		}
//
//		std::cout << "Nbr of Apples : " << GetFruitNbr() << std::endl;
//
//		if (_growingMonth >= Month::SEPTEMBER)
//		{
//			std::cout << "You can harvest your apples by typing [1]" << std::endl;
//		}
//		
//		if (_growingMonth > Month::SEPTEMBER)
//		{
//			_fruitNbr -= GetRandomInt(_fruitNbr * 0.03, _fruitNbr * 0.10);
//		}
//
//		if (_growingMonth == Month::DECEMBER)
//		{
//			_fruitNbr = 0;
//			_growingMonth = Month::MONTHSTART;
//		}
//}
//
//int AppleTree::Harvest()
//{
//	std::cout << _fruitNbr * 0.150 << "kg";
//	return _fruitNbr * (_fruitWeight / 1000);
//}
