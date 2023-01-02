#ifndef ENJEU_H_INCLUDED
#define ENJEU_H_INCLUDED

#include <iostream>
#include <vector>
#include <string>
#include "carte.h"
#include "creature.h"
#include "energie.h"
#include "speciale.h"


class Enjeu
{
private:
    Carte* m_carte;
    //std::vector<Carte*> m_cartes;


public:
    Enjeu(){};
    ~Enjeu(){};

    Carte* getCarte(){return m_carte;};
   //std::vector<Carte*> getCarte(){return m_cartes;};

    void ajouterCarte(std::string type);
    void afficher()const;
    std::string nomCarteEnjeu();


};


#endif //ENJEU_H_INCLUDED


