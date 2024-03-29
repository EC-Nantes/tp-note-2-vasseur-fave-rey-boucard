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
    
        //create a pointer on the deck
        Cardgame *deck;
        string tuile_cachee;
        // User have 5 card on hand //TODO Check if it's possible to use a vector instead of an array
        vector <Carte> main_joueur;
        Plateau *pointeurPlateau;   /* Include pointer to plateau */
                
    public:
        /* CONSTRUCTORS */
        /**
         * @brief Construct a new Joueur object
         * 
         * @param deck 
         */
        Joueur(Cardgame *deck, Plateau *pointeurPlateau);

        /*GETTERS */
        /**
         * @brief Get the Tuile Cachee object
         * @return string 
         * @param none
         */
        string getTuileCachee();

        /**
         * @brief Get the Main Joueur object
         * @return vector<Carte> 
         * @param none
         */
        vector<Carte> getMainJoueur();

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

};


#endif /* _JOUEUR_HPP_ */