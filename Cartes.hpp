/*
 * Cartes.hpp
 *
 *  Created on: 10 Mar. 2023
 *      Author: REY Maxime, BOUCARD Romain, VASSEUR François, FAVE Jonathan
 */

#ifndef CARTES_HPP_
#define CARTES_HPP_

#include <iostream>
#include <cstring>
#include <sstream>

#include "Plateau.hpp"


using namespace std;

enum Couleur {rouge, bleu, vert, jaune, violet, neutre};
enum Valeur {plusplus, plus, moins, h, hh};


class Carte
{
protected:

    //include pointer to plateau 
    Plateau *pointeurPlateau;

    string couleur; // peut être rouge, bleu, vert, jaune, violet, neutre
    string valeur;  // Peut être ++, +, -, ↑↑, ↑
    

public:

    /* Constructor */
    Carte(string couleur, string valeur, Plateau *pointeurPlateau);
    Carte(const Carte&);

    /* Methods */
    string Effet();
    //std::ostream& operator<< (std::ostream &);

    /* Getters */
    string getCouleur() const;
    string getValeur() const;

    /* Setters */
    void setCouleur(string couleur);
    void setValeur(string valeur);

};


#endif //CARTES_HPP_