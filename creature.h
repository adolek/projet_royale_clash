#ifndef CREATURE_H_INCLUDED
#define CREATURE_H_INCLUDED

#include <iostream>
#include "carte.h"


/// Classe Creature héritée de Carte ///


class Creature : public Carte
{
protected:
    int m_pointsVie;
    int m_pointsDegatsAttaque1;
    int m_pointsDegatsAttaque2;


public:
    Creature();
    virtual ~Creature(){};

    virtual int getPointsVie(){return m_pointsVie;};
    virtual void setPointsVie(int points){m_pointsVie = points;};
    int getPointsDegatsAttaque1(){return m_pointsDegatsAttaque1;};
    int getPointsDegatsAttaque2(){return m_pointsDegatsAttaque2;};
    void setPointsDegatsAttaque1(int points){m_pointsDegatsAttaque1 = points;};
    void setPointsDegatsAttaque2(int points){m_pointsDegatsAttaque2 = points;};

    virtual void attaque1(Creature&a)=0;
    virtual void attaque2(Creature&a)=0;
    virtual void afficher()const;

};


/// Différentes cartes de type Creature ///


class Geant : public Creature
{
public :
    Geant();
    virtual ~Geant(){};

    void attaque1(Creature&a);
    void attaque2(Creature&a);
};


class Pekka : public Creature
{
public :
    Pekka();
    virtual ~Pekka(){};

    void attaque1(Creature&a);
    void attaque2(Creature&a);
};


class ElectroSorcier : public Creature
{
public :
    ElectroSorcier();
    virtual ~ElectroSorcier(){};

    void attaque1(Creature&a);
    void attaque2(Creature&a);
};


class Dragon : public Creature
{
public :
    Dragon();
    virtual ~Dragon(){};

    void attaque1(Creature&a);
    void attaque2(Creature&a);
};


class Ballon : public Creature
{
public :
    Ballon();
    virtual ~Ballon(){};

    void attaque1(Creature&a);
    void attaque2(Creature&a);
};




#endif //CREATURE_H_INCLUDED
