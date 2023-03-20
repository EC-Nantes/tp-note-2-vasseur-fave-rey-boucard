#ifndef IA_HPP_
#define IA_HPP_

#include <random>

#include "Joueur.hpp"

/**
 * @brief daughter class of a player, the ia is an algorithmic player 
 * @param 
 * @param 
 */
class IA : public Joueur
{
    protected:


    public:
        /* CONSTRUCTORS */
        /**
         * @brief Construct a new Joueur object
         * 
         * @param deck 
         */
        IA(Cardgame *deck, Plateau *pointeurPlateau) : Joueur (deck, pointeurPlateau){};
        /**
         * @brief Methods to play
         * @param none
         * @return none
         */
        void jouer();

        /**
         * @brief choice of card for IA 
         * @param none
         * @return int 
         */
        int choisirCarte();
};

#endif //IA_HPP_