#include "Tortue.hpp"
using namespace std;


Tortue::Tortue(void){
	this->couleur = "None";
}

Tortue::Tortue(std::string _couleur){
    this->couleur = _couleur;
    this->num_case = 1;
    this->seul = false;
    this->etage = 0;
}

Tortue::Tortue(std::string _couleur, int _case, bool _seul, int _etage){
    this->couleur = _couleur;
    this->num_case = _case;
    this->seul = _seul;
    this->etage = _etage;
}

std::string Tortue::getCouleur() const{
	return this->couleur;
}

int Tortue::getCase() const{
    return this->num_case;
}

bool Tortue::getSeul() const{
    return this->seul;
}

int Tortue::getEtage() const{
    return this->etage;
}

void Tortue::setCase(int _case){
    this->num_case = _case;
}

void Tortue::setSeul(bool _seul){
    this->seul = _seul;
}

void Tortue::setEtage(int _etage){
    this->etage = _etage;
}

void Tortue::setCouleur(std::string color){
    this->couleur = color;
}

std::ostream& operator<<(std::ostream& os, const Tortue& tortle){
	os << "Tortue " << tortle.getCouleur() << std::endl;
    os << "   Case  " << tortle.getCase() << std::endl;
    os << "   Seul  " << tortle.getSeul() << std::endl;
    os << "   Etage " << tortle.getEtage() << std::endl;
	return os;
}