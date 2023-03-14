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
    Cardgame();

    bool isEmpty();
    void Melange(string);
    Carte getTopCarte();
    void addCardDefausse(Carte);
    void defausseToPioche();
};

#endif /*CARDGAME_H*/