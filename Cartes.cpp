#include "Cartes.hpp"

/* Constructor */

Carte::Carte(string couleur, string valeur, Plateau *pointeurPlateau){
    this->pointeurPlateau = pointeurPlateau;
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

    //TODO, si la valeur de la carte est h, hh
    //récupérer la liste des tortues au fond du plateau
    //Si il n'y en a qu'une, résoudre son effet
    //Si il y en a plusieurs, demander au joueur de choisir
    //verifier si la tortue est bien la derniere si valeur = h ou hh
    
    string tempColor = this->couleur;

    if (tempColor == "neutre"){
        //neutre is joker, it means that the player can choose the color

        if(this->valeur == "h"){
            //get the last tortue in the list by using the method getLastTortue() from the class Plateau
            //if there is only one tortue in the list, it means that the tortue is the last one
            //so we can resolve the effect of the card
            //if there is more than one tortue in the list, we have to ask the player to choose the tortue
            //and then we can resolve the effect of the card
        }

        else if(this->valeur == "hh"){
            //get the last tortue in the list by using the method getLastTortue() from the class Plateau
            //if there is only one tortue in the list, it means that the tortue is the last one
            //so we can resolve the effect of the card
            //if there is more than one tortue in the list, we have to ask the player to choose the tortue
            //and then we can resolve the effect of the card
        }
        else {
            cout << "Choisissez la couleur de la tortue de votre choix, 1: rouge, 2: bleu, 3: vert, 4: jaune, 5: violet" << endl;
            cin >> tempColor;
            if (tempColor == "1"){
                tempColor = "rouge";
            }
            else if (tempColor == "2"){
                tempColor = "bleu";
            }
            else if (tempColor == "3"){
                tempColor = "vert";
            }
            else if (tempColor == "4"){
                tempColor = "jaune";
            }
            else if (tempColor == "5"){
                tempColor = "violet";
            }
        }
    }  
    
    //check each color and each value to do the right action

    if (tempColor == "rouge"){
        if (this->valeur == "plusplus"){
            this->pointeurPlateau->updatePlateau("rouge;plusplus");
        }
        else if (this->valeur == "plus"){
            this->pointeurPlateau->updatePlateau("rouge;plus");
        }
        else if (this->valeur == "moins"){
            this->pointeurPlateau->updatePlateau("rouge;moins");
        }
        else if (this->valeur == "h"){
            this->pointeurPlateau->updatePlateau("rouge;h");
        }
        else if (this->valeur == "hh"){
            this->pointeurPlateau->updatePlateau("rouge;hh");
        }
        
    }
    else if (tempColor == "bleu"){
        if (this->valeur == "plusplus"){
            this->pointeurPlateau->updatePlateau("bleu;plusplus");
        }
        else if (this->valeur == "plus"){
            this->pointeurPlateau->updatePlateau("bleu;plus");
        }
        else if (this->valeur == "moins"){
            this->pointeurPlateau->updatePlateau("bleu;moins");
        }
    }
    else if (tempColor == "vert"){
        if (this->valeur == "plusplus"){
            this->pointeurPlateau->updatePlateau("vert;plusplus");
        }
        else if (this->valeur == "plus"){
            this->pointeurPlateau->updatePlateau("vert;plus");
        }
        else if (this->valeur == "moins"){
            this->pointeurPlateau->updatePlateau("vert;moins");
        }
    }
    else if (tempColor == "jaune"){
        if (this->valeur == "plusplus"){
            this->pointeurPlateau->updatePlateau("jaune;plusplus");
        }
        else if (this->valeur == "plus"){
            this->pointeurPlateau->updatePlateau("jaune;plus");
        }
        else if (this->valeur == "moins"){
            this->pointeurPlateau->updatePlateau("jaune;moins");
        }
    }
    else if (tempColor == "violet"){
        if (this->valeur == "plusplus"){
            this->pointeurPlateau->updatePlateau("violet;plusplus");
        }
        else if (this->valeur == "plus"){
            this->pointeurPlateau->updatePlateau("violet;plus");
        }
        else if (this->valeur == "moins"){
            this->pointeurPlateau->updatePlateau("violet;moins");
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