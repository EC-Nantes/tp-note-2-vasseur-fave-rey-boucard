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

class Tortue {
protected:
    std::string couleur;
	int num_case;
	bool seul;
	int etage;
public:
	Tortue(void);
	Tortue(std::string _couleur);
	Tortue(std::string _couleur, int _case, bool _seul, int _etage);

	int getCase() const;
	std::string getCouleur() const;
	bool getSeul() const;
	int getEtage() const;

	void setCouleur(std::string color);
	void setCase(int _case);
	void setSeul(bool _seul);
	void setEtage(int _etage);
	friend std::ostream& operator<< (std::ostream& os, const Tortue& R);
};


/*std::ostream& operator<<(std::ostream& os, Tortue const &Tortue){
	os << "Affichage";
	return os;
}*/

#endif /*TORTUE_H*/