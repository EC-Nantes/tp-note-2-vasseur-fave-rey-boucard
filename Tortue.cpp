#include "Tortue.hpp"
using namespace std;


Tortue::Tortue(void){
	this->couleur = "None";
}

Tortue::Tortue(std::string _couleur){
    this->couleur = _couleur;
}

std::string Tortue::getCouleur(){
	return this->couleur;
}