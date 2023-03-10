#include "CardGame.hpp"

Cardgame::Cardgame(){
    for(int i = 0; i < 5; i++){
        this->Pioche.push_back(Carte(Couleur+i, plusplus));
        for(int j = 0; j < 5; j++){
            this->Pioche.push_back(Carte(Couleur+i, plus));
        }
        for(int k = 0; k < 5; k++){
            this->Pioche.push_back(Carte(Couleur+i, moins));
        }
    }
    for(int i = 0; i < 2; i++){
        this->Pioche.push_back(Carte(neutre, hh));
        this->Pioche.push_back(Carte(neutre, moins));
    }
    for(int i = 0; i < 5; i++){
        this->Pioche.push_back(Carte(neutre, plus));
    }
    for(int i = 0; i < 3; i++){
        this->Pioche.push_back(Carte(neutre, h));
    }
}

bool Cardgame::isEmpty(){
    if(this->Pioche.empty()){
        std::cout << "La pioche est vide." << std::endl;
        return true;
    }
    else return false;
}

void Cardgame::Melange(string vec){
    /*Créer un générateur de nombres aléatoires*/
    std::random_device rd;
    std::mt19937 gen(rd());

    if(vec == "Pioche"){
        /*Mélanger les éléments du vecteur*/
        std::shuffle(this->Pioche.begin(), this->Pioche.end(), gen);
    }
    else(vec == "Tuiles"){
        /*Mélanger les éléments du vecteur*/
        std::shuffle(this->Tuiles.begin(), this->Tuiles.end(), gen);
    }
}

Carte Cardgame::getTopCarte(){
    /*Récupère le dernier élément de la pioche*/
    Carte topCard(this->Pioche.back());
    
    /*Supprime le dernier élément de la Pioche*/
    this->Pioche.pop_back();

    return topCard;
}

void Cardgame::addCardDefausse(Carte card){
    this->Defausse.push_back(Card);
}

void Cardgame::defausseToPioche(){
    this->Pioche = std::move(this->Defausse);
    if(!(this->isEmpty())){
        std::cout << "La pioche a été remplie." <<std::endl;
    }
    else{
        std::cout << "La pioche n'a pas pu être remplie." << std::endl;
    }
}