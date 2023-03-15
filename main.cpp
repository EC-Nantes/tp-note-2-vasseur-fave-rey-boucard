#include <stdio.h>
#include <iostream>
#include <sstream>

#include "Plateau.hpp"
#include "CardGame.hpp"
#include "Joueur.hpp"
 
int main()
{
    /*Cardgame jeu_de_cartes;
    jeu_de_cartes.Melange("Pioche");

    if (plateau_jeu.Fin()){
        std::cout << "Fin\n";
    }else{
        std::cout << "Continu\n";
    }*/
    /*std::string derniereTortue;
    derniereTortue = plateau_jeu.checkLastPos();
    std::cout << derniereTortue << std::endl;*/

    //std::string entree = "oui";

    //std::cout << plateau_jeu;
    /*while (strcmp(entree.c_str(), "exit")!=0){
        std:cin >> entree;
        plateau_jeu.updatePlateau(entree);
        std::cout << plateau_jeu;
    }*/
   
    Plateau p;
    Cardgame c = Cardgame(&p);
    Joueur joueur1(&c);

    joueur1.jouer();

 
    return 0;
}




