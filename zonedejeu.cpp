#include <iostream>
#include "zonedejeu.h"


void ZoneDeJeu::ajouterCarte(std::string type)
{
    if(type == "geant")
    {
        m_creature = new Geant();
        m_creatureActive = true;
    }
    if(type == "electrosorcier")
    {
        m_creature = new ElectroSorcier();
        m_creatureActive = true;
    }
    if(type == "dragon")
    {
        m_creature = new Dragon();
        m_creatureActive = true;
    }
    if(type == "pekka")
    {
        m_creature = new Pekka();
        m_creatureActive = true;
    }
    if(type == "ballon")
    {
        m_creature = new Ballon();
        m_creatureActive = true;
    }
    if(type == "Boule de feu")
    {
        m_energies.push_back(new BouleDeFeu());
        m_nbEnergieFeu++;
    }
    if(type == "Foudre")
    {
        m_energies.push_back(new Foudre());
        m_nbEnergieElectricite++;
    }
    if(type == "Seisme")
    {
        m_energies.push_back(new Seisme());
        m_nbEnergieTerrestre++;
    }
    if(type == "Tornade")
    {
        m_energies.push_back(new Tornade());
        m_nbEnergieAerien++;
    }
    if(type == "Poison")
    {
        m_speciale = new Poison();
        m_specialeActive = true;
    }
    if(type == "Rage")
    {
        m_speciale = new Rage();
        m_specialeActive = true;
    }
    if(type == "Soin")
    {
        m_speciale = new Soin();
        m_specialeActive = true;
    }
    if(type == "Boule de neige")
    {
        m_speciale = new BouleDeNeige();
        m_specialeActive = true;
    }
    if(type == "Clonage")
    {
        m_speciale = new Clonage();
        m_specialeActive = true;
    }
    if(type == "Bouclier")
    {
        m_speciale = new Bouclier();
        m_specialeActive = true;
    }

}


int ZoneDeJeu::pvCreature()
{
    return m_creature->getPointsVie();
}


bool ZoneDeJeu::checkEtatCreatureActive()   /// check les pdv de la creature de la zone pour savoir si elle est morte -> push cimetiere, si creature meurt on decremente pdv du joueur
{
    if(this->getCreatureActive())
    {
        if(this->pvCreature() <= 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }
}


std::string ZoneDeJeu::getNomCreature()
{
    return m_creature->getNom();
}

std::string ZoneDeJeu::getNomSpeciale()
{
    return m_speciale->getNom();
}

void ZoneDeJeu::supprimerCreature()
{
    delete m_creature;
    m_creatureActive = false;
}

void ZoneDeJeu::supprimerSpeciale()
{
    delete m_speciale;
    m_specialeActive = false;
}


void ZoneDeJeu::afficherPtsEnergie()
{
    std::cout << "Vos points d'energie : ";

    if(m_energies.empty())
    {
        std::cout << "aucun" << std::endl;
    }
    else
    {
        std::cout << std::endl;
        for(const auto& elem : m_energies)
        {
            elem->afficher();
        }
    }

}

void ZoneDeJeu::afficherCreature()
{
    if(m_creatureActive)
    {
        m_creature->afficher();
    }

    std::cout << std::endl;

}


void ZoneDeJeu::afficherSpeciale()
{
    if(m_specialeActive)
    {
        m_speciale->afficher();
    }

    std::cout << std::endl;

}


void ZoneDeJeu::afficher()const
{
    if(m_creatureActive)
    {
        m_creature->afficher();
    }
    if(m_specialeActive)
    {
        m_speciale->afficher();
    }
    else if(!m_energies.empty())
    {
        for(const auto& elem : m_energies)
        {
            elem->afficher();
        }
    }

    std::cout << std::endl;

}



void ZoneDeJeu::suppressionEnergies(int energiesFeu, int energiesElectricite, int energiesTerrestre, int energiesAerien)
{
    if(energiesFeu != 0)
    {
        do
        {
            for(unsigned int i=0; i<m_energies.size(); i++)
            {
                if(m_energies[i]->getDomaine() == "feu")
                {
                    m_energies.erase(m_energies.begin() + i);
                    m_nbEnergieFeu--;
                    energiesFeu--;
                }
            }

        }
        while(energiesFeu != 0);
    }

    if(energiesElectricite != 0)
    {
        do
        {
            for(unsigned int i=0; i<m_energies.size(); i++)
            {
                if(m_energies[i]->getDomaine() == "electricite")
                {
                    m_energies.erase(m_energies.begin() + i);
                    m_nbEnergieElectricite--;
                    energiesElectricite--;
                }
            }

        }
        while(energiesElectricite != 0);

    }

    if(energiesTerrestre != 0)
    {
        do
        {
            for(unsigned int i=0; i<m_energies.size(); i++)
            {
                if(m_energies[i]->getDomaine() == "terrestre")
                {
                    m_energies.erase(m_energies.begin() + i);
                    m_nbEnergieTerrestre--;
                    energiesTerrestre--;
                }
            }

        }
        while(energiesTerrestre != 0);

    }

    if(energiesAerien != 0)
    {
        do
        {
            for(unsigned int i=0; i<m_energies.size(); i++)
            {
                if(m_energies[i]->getDomaine() == "aerien")
                {
                    m_energies.erase(m_energies.begin() + i);
                    m_nbEnergieAerien--;
                    energiesAerien--;
                }
            }

        }
        while(energiesAerien != 0);

    }

}

