#ifndef _JOUEUR_HPP_
#define _JOUEUR_HPP_

#include <iostream>
#include <string>

#include "Cartes.hpp" 
#include "CardGame.hpp" 

using namespace std;

class Joueur
{
    protected:
        Cardgame *deck;         /* Create a pointer on the deck */
        string tuile_cachee;    /* Colour of the turtle */
        //TODO Check if it's possible to use a vector instead of an array
        vector <Carte> main;    /* User have 5 card on hand */ 
                
    public:
        /* CONSTRUCTORS */
        /**
         * @brief Construct a new Joueur object
         * 
         * @param deck 
         */
        Joueur(Cardgame *deck);

        /*GETTERS */
        /**
         * @brief Get the Tuile Cachee object
         * @return string 
         * @param none
         */
        string getTuileCachee();

        /* SETTERS */
        /**
         * @brief Set the Tuile Cachee object
         * @return none
         * @param tuile_cachee 
         */
        void setTuileCachee(string tuile_cachee);

        /* METHODS */

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


#endif /* _JOUEUR_HPP_ */