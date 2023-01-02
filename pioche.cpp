#include <iostream>
#include "pioche.h"


void Pioche::ajouterCarte(std::string type)
{
    if(type == "geant")
    {
        m_cartes.push_back(new Geant());
        m_nbCreatures++;
    }
    if(type == "electrosorcier")
    {
        m_cartes.push_back(new ElectroSorcier());
        m_nbCreatures++;
    }
    if(type == "dragon")
    {
        m_cartes.push_back(new Dragon());
        m_nbCreatures++;
    }
    if(type == "pekka")
    {
        m_cartes.push_back(new Pekka());
        m_nbCreatures++;
    }
    if(type == "ballon")
    {
        m_cartes.push_back(new Ballon());
        m_nbCreatures++;

    }
    if(type == "Boule de feu")
    {
        m_cartes.push_back(new BouleDeFeu());
    }
    if(type == "Foudre")
    {
        m_cartes.push_back(new Foudre());
    }
    if(type == "Seisme")
    {
        m_cartes.push_back(new Seisme());
    }
    if(type == "Tornade")
    {
        m_cartes.push_back(new Tornade());
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


void Pioche::premiereCarteAfficher()
{
    if (!m_cartes.empty()) {
        std::cout << "La premiere carte de votre pioche est :" << std::endl;
        m_cartes.front()->afficher();
    }
}

Carte* Pioche::premiereCarte()
{
    return m_cartes.front();

}

void Pioche::popPremiereCarte()
{
    m_cartes.pop_front();

}


void Pioche::afficher()const
{
    for(const auto& elem : m_cartes)
    {
       elem->afficher();
    }
    std::cout << std::endl;

}
