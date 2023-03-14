#include "CardGame.hpp"

/**
 * @brief Construct a new Cardgame:: Cardgame object
 */
Cardgame::Cardgame(){
    std::map<int, std::string> Couleur_map;
    std::map<int, std::string> Valeur_map;

    Couleur_map[0] = "rouge";
    Couleur_map[1] = "bleu";
    Couleur_map[2] = "vert";
    Couleur_map[3] = "jaune";
    Couleur_map[4] = "violet";
    Couleur_map[5] = "neutre";


    Couleur_map[0] = "plusplus";
    Couleur_map[1] = "plus";
    Couleur_map[2] = "moins";
    Couleur_map[3] = "h";
    Couleur_map[4] = "hh";

    Carte card("rouge", "++", nullptr);
    
    /*Pour ajouter les cartes de couleur*/
    for(int i = 0; i < 5; i++){
        card.setCouleur(Couleur_map[i]);
        /*Valeur plusplus pour chaque couleur*/
        card.setValeur(Valeur_map[plusplus]);
        this->Pioche.push_back(card);
        card.setValeur(Valeur_map[pluss]);
        for(int j = 0; j < 5; j++){
            /*Chaque couleur *5 cartes plus*/
            this->Pioche.push_back(card);
        }
        card.setValeur(Valeur_map[moins]);
        for(int k = 0; k < 2; k++){
            /*Chaque couleur *2 cartes moins*/
            this->Pioche.push_back(card);
        }
    }
    /*Pour les cartes neutres*/
    card.setCouleur(Couleur_map[neutre]);
    for(int i = 0; i < 2; i++){
        card.setValeur(Valeur_map[hh]);
        this->Pioche.push_back(card);
        card.setValeur(Valeur_map[moins]);
        this->Pioche.push_back(card);
    }
    card.setValeur(Valeur_map[pluss]);
    for(int i = 0; i < 5; i++){
        this->Pioche.push_back(card);
    }
    card.setValeur(Valeur_map[h]);
    for(int i = 0; i < 3; i++){
        this->Pioche.push_back(card);
    }
    this->Melange("Pioche");
}

/**
 * @brief check if the pick is empty
 * 
 * @return true if is empty
 * @return false if not
 */
bool Cardgame::isEmpty(){
    if(this->Pioche.empty()){
        std::cout << "La pioche est vide." << std::endl;
        return true;
    }
    else return false;
}

/**
 * @brief shuffle the pick (pioche) or the tiles (tuiles)
 * 
 * @param vec ("Pioche" pour mélanger la pioche et "Tuiles" pour les tuiles)
 */
void Cardgame::Melange(string vec){
    /*Créer un générateur de nombres aléatoires*/
    std::random_device rd;
    std::mt19937 gen(rd());

    if(vec == "Pioche"){
        /*Mélanger les éléments du vecteur*/
        std::shuffle(this->Pioche.begin(), this->Pioche.end(), gen);
    }
    else if(vec == "Tuiles"){
        /*Mélanger les éléments du vecteur*/
        std::shuffle(this->Tuiles.begin(), this->Tuiles.end(), gen);
    }
}

/**
 * @brief recup top carte to pick
 * 
 * @return Top Carte
 */
Carte Cardgame::getTopCarte(){
    /*Récupère le dernier élément de la pioche*/
    Carte topCard(this->Pioche.back());
    
    /*Supprime le dernier élément de la Pioche*/
    this->Pioche.pop_back();

    return topCard;
}

/**
 * @brief add card to defausse
 * 
 * @param card to add 
 */
void Cardgame::addCardDefausse(Carte card){
    this->Defausse.push_back(card);
}

/**
 * @brief when pick is empty, move content of defausse to pick
 * 
 */
void Cardgame::defausseToPioche(){
    this->Pioche = std::move(this->Defausse);
    if(!(this->isEmpty())){
        std::cout << "La pioche a été remplie." <<std::endl;
    }
    else{
        std::cout << "La pioche n'a pas pu être remplie." << std::endl;
    }
}