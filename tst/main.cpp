#include "gtest/gtest.h"
#include "../src/CardGame.hpp"
#include "../src/Joueur.hpp"
#include "../src/Plateau.hpp"
#include "../src/Tortue.hpp"

Plateau *pointeurPlateau = new Plateau();
Cardgame *deck = new Cardgame(pointeurPlateau);
Joueur *joueur = new Joueur(deck, pointeurPlateau);

//initial test to check if the test is working
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

//check ig the constructor is working
TEST(Joueur, constructor) {
    EXPECT_EQ(joueur->getTuileCachee(), "A");
}

//check if "piocher" add a new card to the hand
TEST(Joueur, piocher) {
    
    int size = joueur->getMainJoueur().size();
    joueur->piocher();    
    EXPECT_EQ(joueur->getMainJoueur().size(), size+1);
}

//check if "defausser" remove a card from the hand
TEST(Joueur, defausser){
    int size = joueur->getMainJoueur().size();
    joueur->defausser(0);
    EXPECT_EQ(joueur->getMainJoueur().size(), size-1);
}


//check if at the begining of the game, the turtles are on the start tile
TEST(Plateau, getNbtortues){
    EXPECT_EQ(pointeurPlateau->getNbtortues(0), 5);
}


//check if the turtle can move backwards
TEST(Plateau, stepbackIsPossible){
    EXPECT_EQ(pointeurPlateau->stepbackIsPossible("bleu"), 0);
}


