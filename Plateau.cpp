#include "Plateau.hpp"

#include <sstream>

using namespace std;


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

void Plateau::PlacementTortues(){
    std::string couleurs[5] = {"rouge", "bleu", "vert", "jaune", "violet"};
    int ordre_couleurs[5] = {0, 1, 2, 3, 4};
    int n = sizeof(ordre_couleurs) / sizeof(ordre_couleurs[0]);
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::shuffle (ordre_couleurs, ordre_couleurs+n, std::default_random_engine(seed));
    for (int i=0; i<5; i++){
        this->ordre[i] = couleurs[ordre_couleurs[i]];
        this->tortues[i] = new Tortue(this->ordre[i], 1, false, i);
        this->plateau[0][i] = this->tortues[i];
        std::cout << *this->tortues[i];
    }
    this->Nb_tortues[0] = 5;
}

bool Plateau::Fin(){
    if (Nb_tortues[9] != 0){
        return true;
    }
    return false;
}

int Plateau::getNbtortues(int _case) const{
    return this->Nb_tortues[_case];
}

std::string Plateau::getCaseCouleur(int _case, int _etage) const{
    return this->plateau[_case][_etage]->getCouleur();
}

void Plateau::updatePlateau(std::string deplacement){
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
    solo = this->tortues[pos]->getSeul();
    moveSelected = this->moveSelect(move);
    if (solo == true){
        this->moveAlone(pos, moveSelected);
    }else{
        this->moveOthers(pos, moveSelected);
    }

}

int Plateau::whichTortue(std::string color){
    int index;
    auto it = find(begin(this->ordre), end(this->ordre), color);
    if (it == end(this->ordre)){
        std::cout << "Error : Couleur choisi fausse\n";
        index = -1;
    }else{
        index = std::distance(this->ordre, it);
    }
    return index;
}

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

void Plateau::moveAlone(int pos, int move){
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
}

void Plateau::moveOthers(int pos, int move){
    int new_pos;
    int etage = this->tortues[pos]->getEtage();
    int num_case = this->tortues[pos]->getCase();
    int nb_tortue = this->Nb_tortues[num_case-1];
    if (etage < nb_tortue-1){
        while (etage < nb_tortue){
            new_pos = this->whichTortue(this->plateau[num_case-1][etage]->getCouleur());
            this->moveAlone(new_pos, move);
            etage++;
        }
    }else{
        this->moveAlone(pos, move);
    }
}

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
