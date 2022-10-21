# FormativeOrchard


This is a formative exercise of the Sae institute Geneva.  
The aim of the exercise was to create an orchard.  

Each month, something happen to the trees.  
You have to harvest the fruits from the trees at the right month to have the maximum fruit weight possible.

Basics element requiered in the program :  
* Créer un programme permettant de gérer votre verger :
  * Il y a dans ce verger 3 types d’arbre : Pommier, Poirier, Cerisier.
  * | tree name | Nb fruits | fruits weight (g)| winter | flowering | harvest | descent (autumn) |
    | --- | --- | --- | --- | --- | --- | --- |
    | cherry tree | 45.000 - 60.000 | 5 | January - March | April | May - June | July - December |
    | apple tree | 600 - 850 | 150 | January - March | April - August | September - November | July - December |
    | pear tree | 250 - 350 | 90 | January - March | April - September | October - November | July - December |


    Chaque arbre passe par différentes phases :
        La floraison : aucun fruit n’est disponible, il y a 5% de chances de perdre la récolte;
        La pousse : les fruits poussent progressivement et mûrissent, chaque mois entre 3% et 10% des fruits disparaissent, dus aux oiseaux et autres parasites.
        La “descente” :  les fruits pourrissent petit à petit si ils ne sont pas récoltés. A la fin de cette période, toute la récolte est foutue.
        L’hiver (Janvier Mars) : L’arbre est en sommeil, rien ne pousse, mais rien n’arrive de problématique.
    Lors de la récolte pour sa coopérative, le paysan s’est engagé à fournir à chaque récolte 2000 kg de fruits, malheureusement il ne peut se permettre qu’une seule période de récolte pour laquelle ils disposent des moyens pour embaucher des saisonniers.

 

    Les données fournies sont-elles équilibrées ? 
        Faites les calculs nécessaires pour déterminer le nombre d’arbres à implanter pour que le verger fonctionne correctement.
        Déterminez si une période optimale est possible
    Créer un programme permettant les récoltes à l’aide :
        une hiérarchie de classes permettant la distinction des différents arbres
        les classes pourront implémenter une méthode permettant
             “la pousse des fruits” ( = initier la quantité; on ignorera les problématiques de saison en estimant les fruits immédiatement disponibles)
            la récolte en vérifiant la quantité disponible sur chaque arbre
        le programme principal permettra au paysan le contenu de chaque récolte. 
    Progressez par étapes :
        Un type d’arbre sur une année
        Implémenter les 3 types d’arbres
        Implémenter les aléas


Learning objectives :  
* Explain characteristics of algorithms.
* Produce stable code using object-oriented programming.
* Create algorithms for specific tasks. 
