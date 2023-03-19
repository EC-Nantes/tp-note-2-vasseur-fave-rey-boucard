#include "Joueur.hpp"
using namespace std;

Joueur::Joueur(Cardgame *deck, Plateau *pointeurPlateau)
{
    this->pointeurPlateau = pointeurPlateau;
    this->tuile_cachee = deck->getTuile();
    std::cout << "Ta couleur de tortue est " << this->tuile_cachee << std::endl;
    this->deck = deck;
    //draw card from the deck
    for (int i = 0; i < 5; i++)
    {
        this->main_joueur.push_back(this->deck->getTopCarte());
    }

}

//getter
string Joueur::getTuileCachee()
{
    return this->tuile_cachee;
}

vector<Carte> Joueur::getMainJoueur()
{
    return this->main_joueur;
}

//setter
void Joueur::setTuileCachee(string tuile_cachee)
{
    this->tuile_cachee = tuile_cachee;
}

//method
//TODO Test unitaires 
void Joueur::jouer()
{
    //select a card by using choisirCarte()
    //do the action of the card
    //remove the card from the hand
    //draw a new card
    int exit = 1;
    int move_possible;
    int carte_choisie;

    while (exit == 1){
        carte_choisie = choisirCarte();
        //cout << "Carte choisie : " << carte_choisie << endl;
        if (strcmp(this->main_joueur[carte_choisie].getValeur().c_str(), "moins") == 0){
            //Demander si on peut reculer une carte du plateau
            move_possible = this->pointeurPlateau->stepbackIsPossible(this->main_joueur[carte_choisie].getCouleur());
            if (move_possible){
                exit = 0;
            }else{
                cout << "La carte choisie ne peut pas être jouée, veuillez jouer une autre carte" << endl;
            }
        }else{ //Autres cartes
            exit = 0;
        }
    }
    
    this->main_joueur[carte_choisie].Effet();
    cout << "Carte jouee" << endl;
    defausser(carte_choisie);
    cout << "Carte defaussee" << endl;
    piocher();

    //cout << "Jouer" << endl;
}

void Joueur::piocher()
{
    //add the card to the hand from "jeudecarte.hpp"
    //check if slot is empty
    //if not, ask raise an error

    this->main_joueur.push_back(this->deck->getTopCarte());
}

void Joueur::defausser(int carte_a_defausser)
{
    //add the card to the discard pile from "jeudecarte.hpp"
    //remove carte_a_defausser from the hand

    this->deck->addCardDefausse(this->main_joueur[carte_a_defausser]);

    //remove the vector element from the hand
    this->main_joueur.erase(this->main_joueur.begin() + carte_a_defausser);
}

int Joueur::choisirCarte() 
{
    //print each card
    //ask user to choose a card
    //return the card

    int carte_choisie;

    for (int i = 0; i < 5; i++)
    {
       cout << "Carte " << i+1 << " : " << this->main_joueur[i].getValeur() << " " << this->main_joueur[i].getCouleur() << endl;
    }
    cout << "Choisir une carte : 1, 2, 3, 4, 5" << endl;
    cin >> carte_choisie;
    return carte_choisie-1;
    
}

