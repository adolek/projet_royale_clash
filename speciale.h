#ifndef SPECIALE_H_INCLUDED
#define SPECIALE_H_INCLUDED

#include <iostream>
#include "carte.h"


/// Classe Speciale héritée de Carte ///


class Speciale : public Carte
{
protected:
    bool m_cycleDeVie;
    bool m_retour;


public:
    Speciale(){m_domaine = "speciale";};
    ~Speciale(){};

    virtual bool getCycleDeVie(){return m_cycleDeVie;};
    virtual void setCycleDeVie(bool cycle){m_cycleDeVie = cycle;};
    virtual bool getRetour(){return m_retour;};
    virtual void setRetour(bool retour){m_retour = retour;};

    void afficher()const {Carte::afficher();};

};


/// Différentes cartes de type Speciale ///


class Poison : public Speciale
{
public :
    Poison();
    ~Poison(){};

    void afficher()const {Speciale::afficher();};
};


class Rage : public Speciale
{
public :
    Rage();
    ~Rage(){};

    void afficher()const {Speciale::afficher();};
};


class Soin : public Speciale
{
public :
    Soin();
    ~Soin(){};

    void afficher()const {Speciale::afficher();};
};


class BouleDeNeige : public Speciale
{
public :
    BouleDeNeige();
    ~BouleDeNeige(){};

    void afficher()const {Speciale::afficher();};
};


class Clonage : public Speciale
{
public :
    Clonage();
    ~Clonage(){};

    void afficher()const {Speciale::afficher();};
};


class Bouclier : public Speciale
{
public :
    Bouclier();
    ~Bouclier(){};

    void afficher()const {Speciale::afficher();};
};



#endif //SPECIALE_H_INCLUDED


