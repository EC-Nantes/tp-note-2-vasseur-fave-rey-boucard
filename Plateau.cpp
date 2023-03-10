#include "Plateau.hpp"
using namespace std;


Plateau::Plateau(void){
    //init des 5 tortues
    for (int i = 0; i<10; i++){
        this->Nb_tortues[i] = 0;
    }
    tortues[0] = Tortue("Rouge");
    tortues[1] = Tortue("Bleu");
    tortues[2] = Tortue("Jaune");
    tortues[3] = Tortue("Vert");
    tortues[4] = Tortue("Violet");
}

void Plateau::PlacementTortues(){
    vector<std::shared_ptr<Tortue>> melange_tortues = { std::make_shared<Tortue>("Rouge"), std::make_shared<Tortue>("Bleu"), std::make_shared<Tortue>("Jaune"), std::make_shared<Tortue>("Vert"), std::make_shared<Tortue>("Violet"), };
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    shuffle (melange_tortues.begin(), melange_tortues.end(), std::default_random_engine(seed));
    for (int i = 0; i<5; i++){
        plateau[0][i] = *melange_tortues[i];
    }
    this->Nb_tortues[0] = 5;
}

bool Plateau::Fin(){
    if (Nb_tortues[9] != 0){
        return true;
    }
    return false;
}

void Plateau::updatePlateau(std::string deplacement){

}

bool Plateau::checkLastPos(std::string couleur){
    
}

void Plateau::updatePlateau(std::string deplacement){

}

