#include "Cartes.hpp"

/* Constructor */

Carte::Carte(string couleur, string valeur, Plateau *pointeurPlateau){
    this->pointeurPlateau = pointeurPlateau;
    this->couleur = couleur;
    this->valeur = valeur;
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
                if (tempColor == "1"){
                    tempColor = couleurTab[0];
                }
                else if (tempColor == "2"){
                    tempColor = couleurTab[1];
                }
                else if (tempColor == "3"){
                    tempColor = couleurTab[2];
                }
                else if (tempColor == "4"){
                    tempColor = couleurTab[3];
                }
                else if (tempColor == "5"){
                    tempColor = couleurTab[4];
                }
            }



        }

        else {
            if (this->valeur == "moins"){
                std::string choiceTortues;
                choiceTortues = this->pointeurPlateau->whichCanStepback();
                std::vector<std::string> output;
                std::stringstream ss(choiceTortues);
                std::string token;
                while (std::getline(ss, token, ',')) {
                    output.push_back(token);
                }
                cout << "Selectionnez la couleur de la tortue de votre choix";
                for (int i=0; i<std::stoi(output[0]); i++){
                    cout << ", " << i+1 << ": " << output[i+1];
                }
                std::cout << std::endl;
                int choiceColor;
                cin >> choiceColor;
                tempColor = output[choiceColor];

            }else{
                cout << "Selectionnez la couleur de la tortue de votre choix, 1: rouge, 2: bleu, 3: vert, 4: jaune, 5: violet" << endl;
                int choiceTempColor;
                cin >> choiceTempColor;     

                //exception si le nombre de tortue est supérieur à 5
                try {
                    if (choiceTempColor > 5) {
                        throw runtime_error("Erreur : choix doit etre inferieur ou egale a 5");
                    }
                    if (cin.fail()) {
                        throw runtime_error("Erreur : saisie non numerique");
                    }
                } catch (runtime_error& e) {
                    std::cout << e.what() << std::endl;
                    //return 1;
                    }

                if (choiceTempColor == 1){
                    tempColor = "rouge";
                }
                else if (choiceTempColor == 2){
                    tempColor = "bleu";
                }
                else if (choiceTempColor == 3){
                    tempColor = "vert";
                }
                else if (choiceTempColor == 4){
                    tempColor = "jaune";
                }
                else if (choiceTempColor == 5){
                    tempColor = "violet";
                }
            }
        }
    }  
    
    //check each color and each value to do the right action
    string stringToSend = "";

    stringToSend = tempColor + "," + this->valeur;
    this->pointeurPlateau->updatePlateau(stringToSend);

    std::cout << "La carte jouee est la suivante : " << stringToSend << endl;
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