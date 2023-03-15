/*
 * CardGame.hpp
 *
 *  Created on: 10 Mar. 2023
 *      Author: VASSEUR Francois
 */

#ifndef CARDGAME_H
#define CARDGAME_H

#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>
#include <random>
#include <map>

#include "Cartes.hpp"

using namespace std;

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

#endif /*CARDGAME_H*/