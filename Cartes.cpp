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

/*Function*/
string parseString(string str, string &couleurTab){

}



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
                cout << "Selectionnez la tortue de votre choix :" << endl;
                for(int i=0; i<stoi(nombre); i++){
                    cout << i+1 << " : " << couleurTab[i] << endl;
                }
                cin >> tempColor;
            }
        }

        else {
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
        return "0";
    }  
    
    //check each color and each value to do the right action
    string stringToSend = "";

    stringToSend = tempColor + "," + this->valeur;
    this->pointeurPlateau->updatePlateau(stringToSend);
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