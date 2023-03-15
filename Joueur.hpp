#ifndef Joueur_hpp
#define Joueur_hpp

#include <iostream>
#include <string>

#include "Cartes.hpp" 
#include "CardGame.hpp" 

using namespace std;

class Joueur
{
    protected:
    
        //create a pointer on the deck
        Cardgame *deck;
        string tuile_cachee;
        // User have 5 card on hand //TODO Check if it's possible to use a vector instead of an array
        vector <Carte> main;
                


    public:
        //constructor
        Joueur(Cardgame *deck);

        //getter
        string getTuileCachee();

        //setter
        void setTuileCachee(string tuile_cachee);

        //method

        /*
        * @brief: draw a card from the deck
        * @return: none
        * @param: none
        */
        void piocher();

        /*
        * @brief: play a turn
        * @return: none
        * @param: none
        */
        void jouer();

        /*
        * @brief: discard a card
        * @return: none
        * @param: the card to discard
        */
        void defausser(int carte_a_defausser);

        /*
        * @brief: ask user to choose a card to play
        * @return: the card chosen
        * @param: none
        */
        int choisirCarte();

        //Ajouter une fonction pour créer le deck de 5 cartes : appel de la fonction piocher 5 fois
};


#endif /* Joueur_hpp */