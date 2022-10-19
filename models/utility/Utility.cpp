#include "Utility.h"

#include <conio.h>
#include <iostream>
#include <random>


namespace Utility
{
	int GetRandomInt(int min, int max)
	{
		std::random_device os_seed;
		uint_least32_t seed = os_seed();

		std::mt19937 generator(seed);
		std::uniform_int_distribution<uint_least32_t> distribute(min, max);

		return (int)distribute(generator);
	}

	char GetKey()
	{
		char key;

		do
		{
			key = _getch();

			if (key == 13 || key == '1' || key == '2')
			{
				break;
			}

		} while (true);
				
		return key;
	}
}

