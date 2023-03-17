#include <stdio.h>
#include "Joueur.hpp"
#include "Plateau.hpp"
#include "CardGame.hpp"

int main(int argc, char const *argv[]) {
    
    
    Plateau p; //Création du plateau + Placement des 5 tortues aléatoirement sur la case départ
    Cardgame c = Cardgame(&p); //Création du jeu de cartes
    c.Melange("Pioche"); //Mélange de la pioche

    Joueur joueur1(&c, &p); //Création du joueur 1 + pioche de ses 5 cartes de départ
    //Joueur joueur2(&c, &p); //Création du joueur 2 + pioche de ses 5 cartes de départ
    //Joueur joueur3(&c, &p); //Création du joueur 3 + pioche de ses 5 cartes de départ

    std::cout << p;
    std::string exit = "0";
    while (exit != "exit"){
        std::cout << p.whichCanStepback() << std::endl;
        std::cout << p;
        joueur1.jouer();
        std::cout << p;
        cin >> exit;
    }
    /*std::cout << p;
    std::string exit = "0";
    while (exit != "exit"){
        cin >> exit;
        std::cout << "Resultat:" << p.stepbackIsPossible(exit) << std::endl;
        p.updatePlateau("bleu,h");
        std::cout << p;
    }*/


    std::string choiceTortues;
    choiceTortues = p.whichCanStepback();
    std::vector<std::string> output;
    std::stringstream ss(choiceTortues);
    std::string token;
    while (std::getline(ss, token, ',')) {
        output.push_back(token);
    }
    for (auto i : output) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}




