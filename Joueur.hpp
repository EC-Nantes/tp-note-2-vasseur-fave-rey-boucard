#ifndef Joueur_hpp
#define Joueur_hpp

#include <iostream>
#include <string>
//#include "Carte.hpp" to be done
//#include "CardGame.hpp" to be done

using namespace std;

class Joueur
{
    protected:
    
        //create a pointer on the deck
        //Cardgame *deck;

        string tuile_cachee;
        //Carte cartes[5]; // User have 5 card on hand
                


    public:
        //constructor
        Joueur();

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
};


#endif /* Joueur_hpp */