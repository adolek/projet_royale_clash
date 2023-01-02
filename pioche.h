#ifndef PIOCHE_H_INCLUDED
#define PIOCHE_H_INCLUDED

#include <iostream>
#include <deque>
#include <string>
#include "carte.h"
#include "creature.h"
#include "energie.h"
#include "speciale.h"


class Pioche
{
private:
    std::deque<Carte*> m_cartes;
    int m_nbCreatures;


public:
    Pioche(){m_nbCreatures=0;};
    ~Pioche(){};

    int getNbCreatures(){return m_nbCreatures;};

    void ajouterCarte(std::string type);
    void premiereCarteAfficher();
    Carte* premiereCarte();
    void popPremiereCarte();
    void afficher()const;


};


#endif //PIOCHE_H_INCLUDED


