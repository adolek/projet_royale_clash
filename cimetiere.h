#ifndef CIMETIERE_H_INCLUDED
#define CIMETIERE_H_INCLUDED

#include <iostream>
#include <vector>
#include <string>
#include "carte.h"
#include "creature.h"
#include "energie.h"
#include "speciale.h"


class Cimetiere
{
private:
    std::vector<Carte*> m_cartes;


public:
    Cimetiere(){};
    ~Cimetiere(){};

    void ajouterCarte(std::string type);
    void afficher()const;


};


#endif //CIMETIERE_H_INCLUDED

