#include "Joueur.hpp"
using namespace std;

Joueur::Joueur(/*Cardgame *deck */)
{
    this->tuile_cachee = "A";
    //this->deck = deck;

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

void Joueur::jouer()
{
    //select a card by using choisirCarte()
    //do the action of the card
    //remove the card from the hand
    //draw a new card

    //int carte_choisie;

    //carte_choisie = choisirCarte();
    //cartes[carte_choisie]->effet();
    //defausser(carte_choisie);
    //piocher();

    cout << "Jouer" << endl;
}

void Joueur::piocher()
{
    //add the card to the hand from "jeudecarte.hpp"
    //check if slot is empty
    //if not, ask raise an error

    //for (int i = 0; i < 5; i++)
    //{
    //    if (this->cartes[i] == NULL)
    //    {
    //        this->cartes[i] = this->deck->getPioche();
    //        break;
    //    }
    //    else if (i == 4)
    //    {
    //        cout << "Erreur : main pleine" << endl;
    //    }
    //}
    cout << "Piocher" << endl;
}

void Joueur::defausser(int carte_a_defausser)
{
    //add the card to the discard pile from "jeudecarte.hpp"
    //remove carte_a_defausser from the hand

    //this->deck->addDefausse(this->cartes[carte_a_defausser]);
    //this->cartes[carte_a_defausser] = NULL;
    cout << "Defausser" << endl;
}

int Joueur::choisirCarte() 
{
    //print each card
    //ask user to choose a card
    //return the card

    //for (int i = 0; i < 5; i++)
    //{
    //    cout << "Carte " << i << " : " << cartes[i] << endl;
    //}
    //cout << "Choisir carte : 1, 2, 3, 4, 5" << endl;
    //cin >> carte_choisie;
    //return carte_choisie;

    cout << "Choisir carte" << endl;

}

