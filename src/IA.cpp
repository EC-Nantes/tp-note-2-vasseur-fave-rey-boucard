#include "IA.hpp"

void IA::jouer(){
    int carte_choisie;

    cout << "L'IA est en train de choisir sa carte..." << endl;
    carte_choisie = choisirCarte(); //aléatoire entre 0 et 4
    cout << "L'IA a choisit sa carte" << endl;
    this->main_joueur[carte_choisie].Effet();
    cout << "Carte jouée" << endl;
    defausser(carte_choisie);
    cout << "Carte défaussée" << endl;
    piocher();
    cout << "L'IA vient de piocher la dernière carte de la piohe" << endl;

}

int IA::choisirCarte(){
    int carte_choisie;

    /* Génération d'un nombre aléatoire */
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(0, 4);
    
    int random_number = dis(gen);
    /* Attribution d'une carte aléatoire à l'IA */
    carte_choisie = random_number;

    return carte_choisie;

}

