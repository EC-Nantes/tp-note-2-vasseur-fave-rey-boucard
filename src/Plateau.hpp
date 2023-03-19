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
#include <vector>
#include "Tortue.hpp"

using namespace std;


class Plateau;


class Plateau {
protected:
    Tortue* tortues[5];
    Tortue* plateau[10][5];
    int Nb_tortues[10];
    vector <std::string> ordre;

public:
    /**
     * @brief Construct a new Plateau object
     * 
     */
	Plateau(void);

    /**
     * @brief place turtles in plateau
     * 
     */
    void PlacementTortues();

    /**
     * @brief check if a turtle is in end of plateau
     * 
     * @return true 
     * @return false 
     */
    bool Fin();

    /**
     * @brief update position of turtles in the plateau
     * 
     * @param deplacement
     * @return int
     */
    int updatePlateau(std::string deplacement);

    /**
     * @brief check which turtle is in the last position
     * 
     * @return std::string 
     */
    std::string checkLastPos();

    /**
     * @brief Get the Nbtortues object in one case
     * 
     * @param _case 
     * @return int 
     */
    int getNbtortues(int _case) const;

    /**
     * @brief Get the color of turtle in case
     * 
     * @param _case 
     * @param _etage 
     * @return std::string 
     */
    std::string getCaseCouleur(int _case, int _etage) const;

    /**
     * @brief move a turtle in the plateau
     * 
     * @param pos 
     * @param move 
     * @return int 
     */
    int moveAlone(int pos, int move);

    /**
     * @brief move many turtles in the plateau
     * 
     * @param pos 
     * @param move 
     * @return int 
     */
    int moveOthers(int pos, int move);

    /**
     * @brief which turtle in case
     * 
     * @param color 
     * @return int 
     */
    int whichTortue(std::string color);

    /**
     * @brief chose which turtle to move
     * 
     * @param move 
     * @return int 
     */
    int moveSelect(std::string move);
	
    /**
     * @brief Display the order of the colors
     * 
     */
    void getOrdre(void);

    /**
     * @brief Check if one tortle can step back
     * 
     * @param color 
     * @return int 
     */
    int stepbackIsPossible(std::string color);

    /**
     * @brief Ask which tortle can stepback
     * 
     * @return string 
     */
    std::string whichCanStepback();

    /**
     * @brief Get the order of tortle at the end of the game
     * 
     * @return string 
     */
    std::string ordreFin();

    /**
     * @brief to print plateau
     * 
     * @param os 
     * @param plat 
     * @return std::ostream& 
     */
    friend std::ostream& operator<< (std::ostream& os, const Plateau& plat);
};



#endif /*PLATEAU_H*/