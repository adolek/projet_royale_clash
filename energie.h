#ifndef ENERGIE_H_INCLUDED
#define ENERGIE_H_INCLUDED

#include <iostream>
#include "carte.h"


/// Classe Energie héritée de Carte ///


class Energie : public Carte
{
private:


public:
    Energie(){};
    ~Energie(){};

    virtual void afficher()const {Carte::afficher();};

};


/// Différentes cartes de type Energie ///


class BouleDeFeu : public Energie
{
public :
    BouleDeFeu();
    ~BouleDeFeu(){};

    void afficher()const {Energie::afficher();};
};


class Foudre : public Energie
{
public :
    Foudre();
    ~Foudre(){};

    void afficher()const {Energie::afficher();};
};


class Seisme : public Energie
{
public :
    Seisme();
    ~Seisme(){};

    void afficher()const {Energie::afficher();};
};


class Tornade : public Energie
{
public :
    Tornade();
    ~Tornade(){};

    void afficher()const {Energie::afficher();};
};



#endif //ENERGIE_H_INCLUDED

