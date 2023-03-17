#include "Plateau.hpp"

#include <sstream>

using namespace std;

/**
 * @brief Construct a new Plateau object
 * 
 */
Plateau::Plateau(void){
    //Init des 5 tortues
    for (int i = 0; i<10; i++){
        this->Nb_tortues[i] = 0;
    }
    for (int j=0; j<10; j++){
        for (int k=0; k<5; k++){
            this->plateau[j][k] = nullptr;
        }
    }
    this->PlacementTortues();
}

/**
 * @brief place turtles in plateau
 * 
 */
void Plateau::PlacementTortues(){
    std::string couleurs[5] = {"rouge", "bleu", "vert", "jaune", "violet"};
    int ordre_couleurs[5] = {0, 1, 2, 3, 4};
    int n = sizeof(ordre_couleurs) / sizeof(ordre_couleurs[0]);
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::shuffle (ordre_couleurs, ordre_couleurs+n, std::default_random_engine(seed));
    for (int i=0; i<5; i++){
        this->ordre.push_back(couleurs[ordre_couleurs[i]]);
        this->tortues[i] = new Tortue(this->ordre[i], 1, false, i);
        this->plateau[0][i] = this->tortues[i];
    }
    this->Nb_tortues[0] = 5;
}

/**
 * @brief check if a turtle is in end of plateau
 * 
 * @return true 
 * @return false 
 */
bool Plateau::Fin(){
    if (Nb_tortues[9] != 0){
        return true;
    }
    return false;
}

/**
 * @brief Get the Nbtortues object in one case
 * 
 * @param _case 
 * @return int 
 */
int Plateau::getNbtortues(int _case) const{
    return this->Nb_tortues[_case];
}

/**
 * @brief Get the color of turtle in case
 * 
 * @param _case 
 * @param _etage 
 * @return std::string 
 */
std::string Plateau::getCaseCouleur(int _case, int _etage) const{
    return this->plateau[_case][_etage]->getCouleur();
}

/**
 * @brief update position of turtles in the plateau
 * 
 * @param deplacement
 * @return int
 */
int Plateau::updatePlateau(std::string deplacement){
    int ret = 0;
    //Exemple string : "Couleur,move"
    //Etages de 0 à 4
    //Seul vaut 1 quand tortue seul sur la case
    std::istringstream parse_chaine(deplacement);
    std::string couleur;
    std::string move;
    int moveSelected;
    int pos;
    int solo;

    std::getline(parse_chaine, couleur, ',');
    parse_chaine >> move;
    
    pos = this->whichTortue(couleur);
    if (pos == -1){
        return -1;
    }
    solo = this->tortues[pos]->getSeul();
    
    moveSelected = this->moveSelect(move);
    if (moveSelected == 0){
        return -1;
    }
    if (solo == true){
        ret = this->moveAlone(pos, moveSelected);
    }else{
        ret = this->moveOthers(pos, moveSelected);
    }
    return ret;
}

/**
 * @brief which turtle in case
 * 
 * @param color 
 * @return int 
 */
int Plateau::whichTortue(std::string color){ //TODO check for error
    int index;
    int i = 0;
    
    for (i = 0; i < 5; i++) {
        if (strcmp(this->ordre[i].c_str(), color.c_str())==0) {
            break;
        }
    }
    if (i == 5){
        std::cout << "Error : Couleur choisie fausse\n";
        index = -1;
    }else{
        index = i;
    }
    return index;
}

/**
 * @brief chose which turtle to move
 * 
 * @param move 
 * @return int 
 */
int Plateau::moveSelect(std::string move){
    if (strcmp(move.c_str(), "plusplus")==0 || strcmp(move.c_str(), "hh")==0){
        return 2;
    }
    if (strcmp(move.c_str(), "plus")==0 || strcmp(move.c_str(), "h")==0){
        return 1;
    }
    if (strcmp(move.c_str(), "moins")==0){
        return -1;
    }
    std::cout << "Error : Déplacement impossible\n";
    return 0;
}

/**
 * @brief move a turtle in the plateau
 * 
 * @param pos 
 * @param move 
 * @return int 
 */
int Plateau::moveAlone(int pos, int move){
    if (pos<0 || pos >4){
        std::cout << "Error : numéro de tortue erronné\n";
        return -1;
    }
    if (move != -1 && move != 1 && move != 2){
        std::cout << "Error moveAlone: déplacement impossible\n";
        return -1;
    }
    
    //Déplacer la tortue d'une case

    //Récupérer nombre tortues sur la case suivante
    int num_case = this->tortues[pos]->getCase()-1;
    int etage = this->tortues[pos]->getEtage();
    int tortues_case = this->Nb_tortues[num_case + move];

    //Déplacer le pointeur
    this->plateau[num_case+move][tortues_case] = this->tortues[pos];
    this->plateau[num_case][etage] = nullptr;

    //Incrémenter le nombre de tortues sur cette nouvelle case
    this->Nb_tortues[num_case] -= 1;
    this->Nb_tortues[num_case+move] += 1;

    //Changer valeur de la case dans la classe Tortue
    this->tortues[pos]->setCase(num_case+move+1);

    //Changer la valeur de la variable seul de la classe Tortue si besoin
    if (this->Nb_tortues[num_case+move] > 1){
        //this->tortues[pos]->setSeul(false);
        for (int i=0; i<this->Nb_tortues[num_case+move]; i++){
            this->plateau[num_case+move][i]->setSeul(false);
        }
    }else{
        this->tortues[pos]->setSeul(true);
    }

    //Changer l'étage de la tortue
    this->tortues[pos]->setEtage(tortues_case);
    return 0;
}

/**
 * @brief move many turtles in the plateau
 * 
 * @param pos 
 * @param move 
 * @return int 
 */
int Plateau::moveOthers(int pos, int move){
    if (pos<0 || pos >4){
        std::cout << "Error : numéro de tortue erronné\n";
        return -1;
    }
    if (move != -1 && move != 1 && move != 2){
        std::cout << "Error moveOthers: déplacement impossible\n";
        return -1;
    }
    int ret = 0;
    int new_pos;
    int etage = this->tortues[pos]->getEtage();
    int num_case = this->tortues[pos]->getCase();
    int nb_tortue = this->Nb_tortues[num_case-1];
    if (etage < nb_tortue-1){
        while (etage < nb_tortue){
            new_pos = this->whichTortue(this->plateau[num_case-1][etage]->getCouleur());
            if (new_pos == -1){
                return ret;
            }
            ret = this->moveAlone(new_pos, move);
            if (ret == -1){
                return ret;
            }
            etage++;
        }
    }else{
        ret = this->moveAlone(pos, move);
        if (ret == -1){
            return ret;
        }
    }
    return ret;
}

/**
 * @brief check which turtle is in the last position
 * 
 * @return std::string 
 */
std::string Plateau::checkLastPos(){
    int i=0;
    std::string LastTortues;
    while(Nb_tortues[i] ==0){
        i++;
        if (i>9){
            std::cout << "Error : Aucune tortue présente sur le plateau de jeu\n";
        }
    }
    LastTortues = to_string(Nb_tortues[i]);
    for (int j=0; j<Nb_tortues[i]; j++){
        LastTortues = LastTortues + "," + plateau[i][j]->getCouleur();
    }
    return LastTortues;
}

/**
 * @brief to print plateau
 * 
 * @param os 
 * @param plat 
 * @return std::ostream& 
 */
std::ostream& operator<<(std::ostream& os, const Plateau& plat){
	for (int i=0; i<10; i++){
        os << "Case " << i+1 << " : ";
        if (plat.getNbtortues(i) != 0){
            for (int j=0; j<plat.getNbtortues(i); j++){
                os << plat.getCaseCouleur(i, j) << " ";
            }
        }
        os << std::endl;
    }
	return os;
}


void Plateau::getOrdre(){
    for (int i=0; i<5; i++){
        std::cout << i << " : " << this->ordre[i] << std::endl;
    }
}

int Plateau::stepbackIsPossible(std::string color){
    int pos;
    int _case;
    int possible = 0;

    if (strcmp(color.c_str(), "neutre") == 0){
        for (int i=0; i<5; i++){
            _case = this->tortues[i]->getCase();
            if (_case != 1){
                possible = 1;
                break;
            }
        }
    }else {
        pos = whichTortue(color);
        _case = this->tortues[pos]->getCase();
        if (_case == 1){
            possible = 0;
        }else {
            possible = 1;
        }
    }
    return possible;
}

std::string Plateau::whichCanStepback(){
    std::string ret = "";
    int _case;
    int nb_stepback = 0;
    for (int i=0; i<5; i++){
        _case = this->tortues[i]->getCase();
        if (_case != 1){
            ret = ret + this->tortues[i]->getCouleur() + ",";
            nb_stepback++;
        }
    }
    ret = to_string(nb_stepback) + "," + ret;
    return ret;
}

std::string Plateau::ordreFin(){
    std::string ordre = "";
    int nb;
    for (int i=9; i>=0; i--){
        if (this->Nb_tortues[i] != 0){
            nb = this->Nb_tortues[i];
            for (nb; nb>0; nb--){
                ordre = ordre + this->plateau[i][nb-1]->getCouleur() + ",";
            }
        }
    }
    return ordre;
}