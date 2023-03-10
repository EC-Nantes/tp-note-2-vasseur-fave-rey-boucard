#include "Cartes.hpp"

/* Constructor */

Carte::Carte(string couleur, string valeur){
    this->couleur = couleur;
    this->valeur = valeur;
}

/*----------------------------------------------------------*/

/* Methods */

string Carte::Effet(){

}

/*----------------------------------------------------------*/

/* Getters */

string Carte::getCouleur() const{
    return this->couleur;
}

string Carte::getValeur() const{
    return this->valeur;
}

/*----------------------------------------------------------*/

/* Setters */

string Carte::setCouleur(string couleur){
    this->couleur = couleur;
}


string Carte::setValeur(string valeur){
    this->valeur = valeur;
}