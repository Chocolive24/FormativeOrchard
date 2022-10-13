#include <iostream>

#include "Game.h"
#include "Utility.h"


int main()
{
    Game game;
    CherryTree cherryTree;
    CherryTree cherryTree2;

    std::vector<Tree> trees;

    trees.emplace_back(cherryTree);
    trees.emplace_back(cherryTree2);
    //trees.emplace_back(appleTree);

	while (true)
    {
        std::cout << "Current Month : " << game.GetCurrentMonthAsString() << std::endl << std::endl;

        std::cout << "Objective of fruit weight for this year : "
    		      << game.GetWeightToWin() << "kg" << std::endl << std::endl;

        if (game.GetCurrentMonth() >= Month::MAY)
        {
            std::cout << "You can harvest your cherries by typing [1]" << std::endl;
        }

        for (auto& tree : trees)
        {
            tree.Grow(game.GetCurrentMonth());
        }
        
        char keyPressed = Utility::GetKey();

        game.SetMonth(game.GoToNextMonth(game.GetCurrentMonth(), keyPressed, trees));

    }

    
}
