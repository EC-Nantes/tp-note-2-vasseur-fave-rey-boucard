/*
 * CardGame.hpp
 *
 *  Created on: 10 Mar. 2023
 *  Final version : 15 Mars 2023
 *      Author: REY Maxime, BOUCARD Romain, FAVE Jonathan, VASSEUR Francois
 */

#ifndef CARDGAME_HPP_
#define CARDGAME_HPP_

/* Library */
#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>
#include <random>
#include <map>

/* Include */
#include "Cartes.hpp"

using namespace std;

/**
 * @brief Use of the cards  
 * @class Cardgame 
 */
class Cardgame {
protected:
    vector<Carte> Pioche;
    vector<Carte> Defausse;
    vector<string> Tuiles;

public:
    /**
     * @brief Construct a new Cardgame:: Cardgame object
     */
    Cardgame(Plateau*);

    /**
     * @brief check if the pick is empty
     * 
     * @return true if is empty
     * @return false if not
     */
    bool isEmpty();

    /**
     * @brief shuffle the pick (pioche) or the tiles (tuiles)
     * 
     * @param vec ("Pioche" pour mélanger la pioche et "Tuiles" pour les tuiles)
     */
    void Melange(string);
    
    /**
     * @brief recup top carte to pick
     * 
     * @return Top Carte
     */
    Carte getTopCarte();
    
    /**
     * @brief get tuile for player
     * 
     * @return string 
     */
    string getTuile();
    
    /**
     * @brief add card to defausse
     * 
     * @param card to add 
     */
    void addCardDefausse(Carte);
    
    /**
     * @brief when pick is empty, move content of defausse to pick
     * 
     */
    void defausseToPioche();
};

#endif /* CARDGAME_HPP_ */