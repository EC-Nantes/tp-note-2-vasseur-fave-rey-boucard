/*
 * Tortue.hpp
 *
 *  Created on: 10 mars 2023
 *      Author: REY Maxime, BOUCARD Romain, FAVE Jonathan, VASSEUR Francois
 */

#ifndef TORTUE_H
#define TORTUE_H

#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;


class Tortue;


std::ostream& operator<<(std::ostream &, Tortue const&);


class Tortue {
protected:
    std::string couleur;
public:
	Tortue(void);
	Tortue(std::string);

	std::string getCouleur();
	//friend std::ostream& operator<< (std::ostream& os, Tortue const &R);
};


/*std::ostream& operator<<(std::ostream& os, Tortue const &Tortue){
	os << "Affichage";
	return os;
}*/

#endif /*TORTUE_H*/