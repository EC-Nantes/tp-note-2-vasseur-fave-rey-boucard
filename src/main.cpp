#include <stdio.h>
#include <time.h>
#include "Joueur.hpp"
#include "Plateau.hpp"
#include "CardGame.hpp"
#include "IA.hpp"

int main(int argc, char const *argv[]) {
    
    
    Plateau p; //Création du plateau + Placement des 5 tortues aléatoirement sur la case départ
    Cardgame c = Cardgame(&p); //Création du jeu de cartes
    c.Melange("Pioche"); //Mélange de la pioche


    //Création des joueurs
    /*std::string fin_joueurs = "o";
    while (strcmp(fin_joueurs.c_str(), "n") != 0 && strcmp(fin_joueurs.c_str(), "N") != 0){
        std::cout << "Souhaitez vous créer un nouveau joueur ? Oui : 'o' ou 'O', Non : 'n' ou 'N' " << std::endl;
        std::cin >> fin_joueurs;
        std::cout << std::endl;

    }
    std::cout << "Fin joueurs" << std::endl;*/
    std::cout << "   Joueur 1" << std::endl;
    Joueur joueur1(&c, &p); //Création du joueur 1 + pioche de ses 5 cartes de départ + pioche tuile
    std::cout << "   Joueur 2" << std::endl;
    Joueur joueur2(&c, &p); //Création du joueur 2 + pioche de ses 5 cartes de départ + pioche tuile
    std::cout << "   Joueur 3" << std::endl;
    Joueur joueur3(&c, &p); //Création du joueur 3 + pioche de ses 5 cartes de départ + pioche tuile
    IA ia1(&c, &p);

    std::string exit = "0";
    std::string pret = "0";
    //screen clear
    while (exit != "exit"){
        std::cout << p;
        std::cout << "   Joueur 1 pret ? 'o' ou 'O' puis entree pour valider" << std::endl;
        std::cin >> pret;
        joueur1.jouer();
        //screen clear
        std::cout << p;
        if (p.Fin()){
            std::cout << "Partie terminee..." << std::endl;
            break;
        }
        std::cout << "   Joueur 2 pret ? 'o' ou 'O' puis entree pour valider" << std::endl;
        std::cin >> pret;
        joueur2.jouer();
        //screen clear
        std::cout << p;
        if (p.Fin()){
            std::cout << "Partie terminee..." << std::endl;
            break;
        }
        std::cout << "   Joueur 3 pret ? 'o' ou 'O' puis entree pour valider" << std::endl;
        std::cin >> pret;
        joueur3.jouer();
        //screen clear
        std::cout << p;
        if (p.Fin()){
            std::cout << "Partie terminee..." << std::endl;
            break;
        }
    }
    std::string ordre_tortues = "";
    ordre_tortues = p.ordreFin();

    std::vector<std::string> output;
    std::stringstream ss(ordre_tortues);
    std::string token;
    while (std::getline(ss, token, ',')) {
        output.push_back(token);
    }

    exit = "";
    int i=0;
    while (exit != "exit"){
        if (strcmp(output[i].c_str(), joueur1.getTuileCachee().c_str()) == 0){
            std::cout << "Joueur 1 a gagne !" << std::endl;
            break;
        }
        if (strcmp(output[i].c_str(), joueur2.getTuileCachee().c_str()) == 0){
            std::cout << "Joueur 2 a gagne !" << std::endl;
            break;
        }
        if (strcmp(output[i].c_str(), joueur3.getTuileCachee().c_str()) == 0){
            std::cout << "Joueur 3 a gagne !" << std::endl;
            break;
        }
        i++;
    }

}




