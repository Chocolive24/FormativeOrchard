#include <iostream>

#include "Game.h"
#include "Utility.h"


int main()
{
    int nbrOfCherryTree;
    std::cout << "How many Cherry Tree do you want ?" << std::endl;
    std::cin >> nbrOfCherryTree;

    int nbrOfAppleTree;
    std::cout << "How many Apple Tree do you want ?" << std::endl;
    std::cin >> nbrOfAppleTree;

    int nbrOfPearTree;
    std::cout << "How many Pear Tree do you want ?" << std::endl;
    std::cin >> nbrOfPearTree;

    std::vector<Tree> trees;

    Game game;

    for (int i = 0; i < nbrOfCherryTree; i++)
    {
        CherryTree cherryTree;
        trees.emplace_back(cherryTree);
    }

    for (int i = 0; i < nbrOfAppleTree; i++)
    {
        AppleTree appleTree;
        trees.emplace_back(appleTree);
    }

    for (int i = 0; i < nbrOfPearTree; i++)
    {
        PearTree pearTree;
        trees.emplace_back(pearTree);
    }

    system("cls");

    //CherryTree cherryTree2;

    //trees.emplace_back(cherryTree2);
    //trees.emplace_back(appleTree);

    

	while (true)
    {
        std::cout << "Current Month : " << game.GetCurrentMonthAsString() << std::endl << std::endl;

        std::cout << "Objective of fruit weight for this year : "
    		      << game.GetWeightToWin() << "kg" << std::endl << std::endl;
        
        int totalFruits = 0;
        int totalOfCherries = 0;
        int totalOfApples = 0;
        int totalOfPears = 0;
        double totalWeight = 0.0;

        for (auto& tree : trees)
        {
            tree.Grow(game.GetCurrentMonth());

            if (tree.GetFruitName() == "cherries")
            {
                totalOfCherries += tree.GetFruitNbr();
            }

            if (tree.GetFruitName() == "apples")
            {
                totalOfApples += tree.GetFruitNbr();
            }

            if (tree.GetFruitName() == "pears")
            {
                totalOfPears += tree.GetFruitNbr();
            }

            totalFruits += tree.GetFruitNbr();
            totalWeight += tree.GetFruitNbr() * (tree.GetFruitWeight() / 1000.0);
        }

        std::cout << std::endl << "Total of cherries : " << totalOfCherries << std::endl;
        std::cout << std::endl << "Total of apples : " << totalOfApples << std::endl;
        std::cout << std::endl << "Total of pears : " << totalOfPears << std::endl;
        std::cout << std::endl << "Total of fruits : " << totalFruits << std::endl;
        std::cout << std::endl << "Total fruits weight : " << totalWeight << "kg " << std::endl;

        std::cout << std::endl << "You can harvest your fruits by typing [1]" << std::endl;

        char keyPressed = Utility::GetKey();

        
        // TODO gotenextmonth devrait juster aller au next month
        // TODO faut gérer le [1] dans une autre méthode
        game.SetMonth(game.GoToNextMonth(game.GetCurrentMonth(), keyPressed, trees));

    }

    
}
