/*
 * Plateau.hpp
 *
 *  Created on: 10 mars 2023
 *      Author: REY Maxime, BOUCARD Romain, FAVE Jonathan, VASSEUR Francois
 */

#ifndef PLATEAU_H
#define PLATEAU_H

#include <iostream>
#include <fstream>
#include <string.h>

#include <vector>
#include <algorithm>
#include <random>
#include <chrono>
#include <memory>

#include "Tortue.hpp"

using namespace std;


class Plateau;

std::ostream& operator<<(std::ostream &, Plateau const&);


class Plateau {
protected:
    Tortue tortues[5];
    Tortue plateau[10][5];
    int Nb_tortues[10];

public:
	Plateau(void);

    void PlacementTortues();
    bool Fin();
    void updatePlateau(std::string deplacement);
    std::string checkLastPos();

    //void Afficher();
	//friend std::ostream& operator<< (std::ostream& os, Plateau const &R);
};



/*std::ostream& operator<<(std::ostream& os, Plateau const &Plateau){
	os << "Affichage";
	return os;
}*/

#endif /*PLATEAU_H*/