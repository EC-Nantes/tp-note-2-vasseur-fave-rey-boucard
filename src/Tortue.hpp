/*
 * Tortue.hpp
 *
 *  Created on: 10 mars 2023
 *      Author: REY Maxime, BOUCARD Romain, FAVE Jonathan, VASSEUR Francois
 */

#ifndef _TORTUE_HPP_
#define _TORTUE_HPP_

/* Bibliotheques */
#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

class Tortue;

/**
 * @class Tortue 
 * @brief Turtle class representing the 5 turtles of the game 
 */
class Tortue {
protected:
    string couleur;		/* Colour of the turtle */
	int num_case;		/* Number of the box where the turtle is located */
	bool seul;			/* Is used to know if the turtle is alone on its square or not */
	int etage;			/* Is used to identify the floor where the turtle is located */
public:
	/* CONSTRUCTORS */
	/**
	 * @brief Construct a new Tortue object
	 * 
	 */
	Tortue(void);
	/**
	 * @brief Construct a new Tortue object
	 * 
	 * @param _couleur 
	 */
	Tortue(std::string _couleur);
	/**
	 * @brief Construct a new Tortue object
	 * 
	 * @param _couleur 
	 * @param _case 
	 * @param _seul 
	 * @param _etage 
	 */
	Tortue(std::string _couleur, int _case, bool _seul, int _etage);

	/* GETTERS */ 
	/**
	 * @brief Getter that get the Case object
	 * 
	 * @return int 
	 */
	int getCase() const;
	/**
	 * @brief Getter that get the Couleur object
	 * 
	 * @return string 
	 */
	string getCouleur() const;
	/**
	 * @brief Getter that get the Seul object
	 * 
	 * @return true 
	 * @return false 
	 */
	bool getSeul() const;
	/**
	 * @brief Getter that get the Etage object
	 * 
	 * @return int 
	 */
	int getEtage() const;

	/* SETTERS */ 

	/**
	 * @brief Setter that set the Couleur object
	 * 
	 * @param color 
	 */
	void setCouleur(std::string color);
	/**
	 * @brief Setter that set the Case object
	 * 
	 * @param _case 
	 */
	void setCase(int _case);
	/**
	 * @brief Setter that set the Seul object
	 * 
	 * @param _seul 
	 */
	void setSeul(bool _seul);
	/**
	 * @brief Setter that set the Etage object
	 * 
	 * @param _etage 
	 */
	void setEtage(int _etage);
	/**
	 * @brief Display operator overload
	 * 
	 * @param os 
	 * @param R 
	 * @return std::ostream& 
	 */
	friend std::ostream& operator<< (std::ostream& os, const Tortue& R);
};


/*std::ostream& operator<<(std::ostream& os, Tortue const &Tortue){
	os << "Affichage";
	return os;
}*/

#endif /* _TORTUE_HPP_ */