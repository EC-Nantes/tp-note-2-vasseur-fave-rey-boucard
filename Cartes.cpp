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
    
    string tempColor = this->couleur;

    if (tempColor == "neutre"){

        string lastTortue = "";

        if(this->valeur == "h" || this->valeur == "hh"){

            lastTortue = this->pointeurPlateau->checkLastPos();
            istringstream ss(lastTortue);
            string nombre;

            getline(ss, nombre, ',');

            string couleurTab[stoi(nombre)];
            for(int i=0; i<stoi(nombre); i++){
                getline(ss, couleurTab[i], ',');
            }

            if(stoi(nombre)== 1){
                tempColor = couleurTab[0];
            }
            else{
                cout << "Les tortues suivantes sont au fond du plateau : " << endl;
                for(int i=0; i<stoi(nombre); i++){
                    cout << i+1 << " : " << couleurTab[i] << endl;
                }
                cin >> tempColor;
            }
        }

        else {
            //TODO : ajouter une exception si le nombre de tortue est supérieur à 5
            cout << "Selectionnez la couleur de la tortue de votre choix, 1: rouge, 2: bleu, 3: vert, 4: jaune, 5: violet" << endl;
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
    string stringToSend = "";

    stringToSend = tempColor + "," + this->valeur;
    this->pointeurPlateau->updatePlateau(stringToSend);

    cout << "La carte jouee est la suivante : " << stringToSend << endl;
    return "0";
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

void Carte::setCouleur(string couleur){
    this->couleur = couleur;
}


void Carte::setValeur(string valeur){
    this->valeur = valeur;
}