#include <iostream>
#include "speciale.h"




Poison::Poison() : Speciale()
{
    m_nom = "Poison";
    m_description = "je suis un poison";
    m_cycleDeVie = 0;
    m_retour = 0;
}


Rage::Rage() : Speciale()
{
    m_nom = "Rage";
    m_description = "je suis un rage";
    m_cycleDeVie = 0;
    m_retour = 0;
}


Soin::Soin() : Speciale()
{
    m_nom = "Soin";
    m_description = "je suis un soin";
    m_cycleDeVie = 0;
    m_retour = 0;
}


BouleDeNeige::BouleDeNeige() : Speciale()
{
    m_nom = "Boule de neige";
    m_description = "je suis une bdn";
    m_cycleDeVie = 0;
    m_retour = 0;
}


Clonage::Clonage() : Speciale()
{
    m_nom = "Clonage";
    m_description = "je suis un clonage";
    m_cycleDeVie = 1;
    m_retour = 0;
}


Bouclier::Bouclier() : Speciale()
{
    m_nom = "Bouclier";
    m_description = "je suis un bouclier";
    m_cycleDeVie = 1;
    m_retour = 1;
}
