#ifndef DECK_H_INCLUDED
#define DECK_H_INCLUDED

#include <iostream>
#include <algorithm>
#include <random>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include "carte.h"
#include "creature.h"
#include "energie.h"
#include "speciale.h"


class Deck
{
private:
    std::vector<Carte*> m_cartes;


public:
    Deck(){};
    ~Deck(){};

    std::vector<Carte*> getCartes(){return m_cartes;};

    void ajouterCarte(std::string type);
    void melanger();
    void afficher()const;


};


#endif //DECK_H_INCLUDED
