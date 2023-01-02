#include <iostream>
#include "cimetiere.h"


void Cimetiere::ajouterCarte(std::string type)
{
    if(type == "geant")
    {
        m_cartes.push_back(new Geant());
    }
    if(type == "electrosorcier")
    {
        m_cartes.push_back(new ElectroSorcier());
    }
    if(type == "dragon")
    {
        m_cartes.push_back(new Dragon());
    }
    if(type == "pekka")
    {
        m_cartes.push_back(new Pekka());
    }
    if(type == "ballon")
    {
        m_cartes.push_back(new Ballon());
    }
    if(type == "Boule de feu")
    {
        m_cartes.push_back(new BouleDeFeu());
    }
    if(type == "Foudre")
    {
        m_cartes.push_back(new Foudre());
    }
    if(type == "Poison")
    {
        m_cartes.push_back(new Poison());
    }
    if(type == "Rage")
    {
        m_cartes.push_back(new Rage());
    }
    if(type == "Soin")
    {
        m_cartes.push_back(new Soin());
    }
    if(type == "Boule de neige")
    {
        m_cartes.push_back(new BouleDeNeige());
    }
    if(type == "Clonage")
    {
        m_cartes.push_back(new Clonage());
    }
    if(type == "Bouclier")
    {
        m_cartes.push_back(new Bouclier());
    }
}



void Cimetiere::afficher()const
{

    for(const auto& elem : m_cartes)
    {
       elem->afficher();
    }
    std::cout << std::endl;

}
