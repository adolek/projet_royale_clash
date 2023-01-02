#include <iostream>
#include "energie.h"



BouleDeFeu::BouleDeFeu() : Energie()
{
    m_nom = "Boule de feu";
    m_description = "je suis une bdf";
    m_domaine = "feu";
}


Foudre::Foudre() : Energie()
{
    m_nom = "Foudre";
    m_description = "je suis une foudre";
    m_domaine = "electricite";
}


Seisme::Seisme() : Energie()
{
    m_nom = "Seisme";
    m_description = "je suis un seisme";
    m_domaine = "terrestre";
}


Tornade::Tornade() : Energie()
{
    m_nom = "Tornade";
    m_description = "je suis une tornade";
    m_domaine = "aerien";
}
