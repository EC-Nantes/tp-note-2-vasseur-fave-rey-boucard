#include "Cartes.hpp"

/* Constructor */

Carte::Carte(string couleur, string valeur){
    this->couleur = couleur;
    this->valeur = valeur;
}

Carte::Carte(const Carte& carte){
    this->couleur = carte.couleur;
    this->valeur = carte.valeur;
}

/*----------------------------------------------------------*/

/* Methods */

string Carte::Effet(){
    
    //check each color and each value to do the right action

    if (this->couleur == "rouge"){
        if (this->valeur == "plusplus"){
            //do something
        }
        else if (this->valeur == "plus"){
            //do something
        }
        else if (this->valeur == "moins"){
            //do something
        }
        else if (this->valeur == "h"){
            //do something
        }
        else if (this->valeur == "hh"){
            //do something
        }
    }

}

/*----------------------------------------------------------*/

/* Getters */

string Carte::getCouleur()const{
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