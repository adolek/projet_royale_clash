#ifndef PARTIE_H_INCLUDED
#define PARTIE_H_INCLUDED
#include <iostream>
#include <vector>
#include <string>
#include "joueur.h"
#include "carte.h"
#include "deck.h"


class Partie
{
private:
    std::vector<Joueur*> m_joueurs;

public:
    Partie(){};
    ~Partie(){};

    void lancer();
    void creerJoueur();
    void initCollection();
    void initDecks();
    void melangerDecks();
    void sauvegarder();
    void charger();
    void boutique();

    std::vector<Joueur*> getJoueurs(){return m_joueurs;};


};




#endif //PARTIE_H_INCLUDED
