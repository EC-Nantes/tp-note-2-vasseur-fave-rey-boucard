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


class Plateau {
protected:
    Tortue* tortues[5];
    Tortue* plateau[10][5];
    int Nb_tortues[10];
    std::string ordre[5];

public:
	Plateau(void);

    void PlacementTortues();
    bool Fin();
    void updatePlateau(std::string deplacement);
    std::string checkLastPos();

    int getNbtortues(int _case) const;
    std::string getCaseCouleur(int _case, int _etage) const;

    void moveAlone(int pos, int move);
    void moveOthers(int pos, int move);
    int whichTortue(std::string color);
    int moveSelect(std::string move);
	friend std::ostream& operator<< (std::ostream& os, const Plateau& plat);
};



#endif /*PLATEAU_H*/