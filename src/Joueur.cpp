#include "Joueur.hpp"
using namespace std;

Joueur::Joueur(Cardgame *deck)
{
    this->tuile_cachee = "A";
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

    int carte_choisie;

    carte_choisie = choisirCarte();
    cout << "Carte choisie : " << carte_choisie << endl;
    this->main_joueur[carte_choisie].Effet();
    cout << "Carte jouée" << endl;
    defausser(carte_choisie);
    cout << "Carte défaussée" << endl;
    piocher();

    cout << "Jouer" << endl;
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
    cout << "Choisir carte : 1, 2, 3, 4, 5" << endl;
    cin >> carte_choisie;
    return carte_choisie-1;
    
}

