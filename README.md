# FormativeOrchard


This is a formative exercise of the Sae institute Geneva.  
The aim of the exercise was to create an orchard.  

Each month, something happen to the trees.  
You have to harvest the fruits from the trees at the right month to have the maximum fruit weight possible.

# Basics element requiered in the program :  
* Créer un programme permettant de gérer votre verger :
  * Il y a dans ce verger 3 types d’arbre : Pommier, Poirier, Cerisier.
  * | tree name | Nb fruits | fruits weight (g)| winter | flowering | harvest | descent (autumn) |
    | --- | --- | --- | --- | --- | --- | --- |
    | cherry tree | 45.000 - 60.000 | 5 | January - March | April | May - June | July - December |
    | apple tree | 600 - 850 | 150 | January - March | April - August | September - November | July - December |
    | pear tree | 250 - 350 | 90 | January - March | April - September | October - November | July - December |

  * Each tree goes through different phases:
    * Flowering: no fruit is available, there is a 5% chance of losing the crop;  
    * Growth: the fruit gradually grows and ripens, each month between 3% and 10% of the fruit disappears, due to birds and other pests.  
    * The "descent": the fruits rot gradually if they are not harvested. At the end of this period, the whole crop is gone.  
    * Winter (January - March): The tree is dormant, nothing grows, but nothing problematic happens.  
  * When harvesting for his cooperative, the farmer has committed to providing 2000 kg of fruit at each harvest, unfortunately he can only afford one harvest period for        which they have the means to hire seasonal workers.  

  * 1. Do the data provided balance out?  
       * Make the necessary calculations to determine the number of trees that need to be planted for the orchard to function properly.  
       * Determine if an optimal period is possible  
  * 2. Create a program to allow harvesting using :  
       * a hierarchy of classes to distinguish the different trees  
       * the classes can implement a method for  
            * the "growing of the fruits" (= initiating the quantity; we will ignore the problems of season by estimating the fruits immediately available)
            * harvesting by checking the quantity available on each tree  
       * the main program will allow the farmer the content of each harvest. 
  * 3. Progress in stages:
       * One tree type in one year
       * Implement the 3 tree types
       * Implement the hazards


# Learning objectives :  
* Point out computer game related mathematics
* Create a stable code base using object-oriented programming
* Design algorithms for specific tasks
* Apply relevant mathematics concepts to computer game code
