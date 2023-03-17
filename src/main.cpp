#include <stdio.h>
#include "Joueur.hpp"
#include "Plateau.hpp"
#include "CardGame.hpp"

int main(int argc, char const *argv[]) {
    
    
    Plateau p;
    Cardgame c = Cardgame(&p);
    Joueur joueur1(&c);

    joueur1.jouer();

    
}




