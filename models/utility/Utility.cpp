#include <conio.h>
#include "Utility.h"

#include <iostream>
#include <random>


namespace Utility
{
	// ----------------------------------------------------------------------------------------------------------------------

	int GetRandomInt(int min, int max)
	{
		std::random_device os_seed;
		uint_least32_t seed = os_seed();

		std::mt19937 generator(seed);
		std::uniform_int_distribution<uint_least32_t> distribute(min, max);

		return (int)distribute(generator);
	}

	// ----------------------------------------------------------------------------------------------------------------------

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

	// --------------------------------------------------------------------------------------------------------------

	std::string GetNumberTyped()
	{
		std::cout << "-> ";

		std::string numberTyped;

		// ----------------------------------------------------------------------------------------------------

		do
		{
			char key = _getch();

			// Let the user type only keys that are between 1 and 9.
			if (key >= '0' && key <= '9')
			{
				numberTyped += key;
				std::cout << key;
			}

			// If the key pressed is "delete".
			if (key == 8)
			{
				// If the input is not empty.
				if (!numberTyped.empty())
				{
					// Delete the last character and put the cursor back from 1 character in the console.
					numberTyped.pop_back();
					std::cout << "\b \b";
				}
			}

			// If the key pressed is "enter".
			if (key == 13)
			{
				if (numberTyped.empty())
				{
					// The input is empty, so ask the user to type something again.
					std::cout << std::endl << "No value entered. Please enter a valid one" << std::endl;
					std::cout << "-> ";
				}

				else
				{
					break;
				}
			}

		} while (true);

		// ----------------------------------------------------------------------------------------------------

		std::cout << std::endl;

		return numberTyped;
	}

	// --------------------------------------------------------------------------------------------------------------
}