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

using namespace std;

class Carte
{
private:
    string couleur;
    string valeur;

public:

    /* Constructor */
    Carte();
    Carte(const Carte&);

    /* Methods */
    string Effet();
    //std::ostream& operator<< (std::ostream &);

    /* Getters */
    string getCouleur() const;
    string getValeur() const;

    /* Setters */
    string setCouleur();
    string setValeur();

};


#endif //CARTES_HPP_