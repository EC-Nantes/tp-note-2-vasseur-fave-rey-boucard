/*
 * Cartes.hpp
 *
 *  Created on: 10 Mar. 2023
 *      Author: REY Maxime, BOUCARD Romain, VASSEUR François, FAVE Jonathan
 */

#ifndef _CARTES_HPP_
#define _CARTES_HPP_

/* Bibliotheques */
#include <iostream>
#include <cstring>
#include <sstream>

/* Inclusion */
#include "Plateau.hpp"

using namespace std;

/**
 * @enum Give a number for each color 
 * 
 */
enum Couleur {rouge, bleu, vert, jaune, violet, neutre};

/**
 * @enum Give a number for each effect 
 * 
 */
enum Valeur {plusplus, pluss, moins, h, hh};


/**
 * @class Carte
 * @brief Card class that will allow us to represent the cards of the game
 * 
 */
class Carte
{
    protected:
        Plateau *pointeurPlateau;   /* Include pointer to plateau */
        string couleur;             /* Will be red, blue, green, yellow, purple, neutral */ 
        string valeur;              /* Will be ++, +, -, ↑↑, ↑ */ 
        

    public:

    //CONSTRUCTEUR
        /**
         * @brief Construct a new Carte object
         * 
         * @param couleur 
         * @param valeur 
         * @param pointeurPlateau 
         */
        Carte(string couleur, string valeur, Plateau *pointeurPlateau);
        /**
         * @brief Construct a new Carte object
         * @param Carte
         */
        Carte(const Carte&);

    //METHODS

        /**
         * @brief Methods that define the effects of each card
         * 
         * @return string 
         */
        string Effet();

    //GETTERS

        /**
         * @brief Getter that get the Couleur object
         * 
         * @return string 
         */
        string getCouleur() const;

        /**
         * @brief Getter that get the Value of object
         * 
         * @return string 
         */
        string getValeur() const;

    //SETTERS

        /**
         * @brief Setter that set the Couleur object
         * 
         * @param couleur 
         */
        void setCouleur(string couleur);

        /**
         * @brief Setter that set the Value object
         * 
         * @param couleur 
         */
        void setValeur(string valeur);

};


#endif /* _CARTES_HPP_ */