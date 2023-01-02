#include <iostream>
#include "enjeu.h"


void Enjeu::ajouterCarte(std::string type)
{
    if(type == "geant")
    {
        m_carte = new Geant();
        //m_cartes.push_back(new Geant());
    }
    else if(type == "electrosorcier")
    {
        m_carte = new ElectroSorcier();
        //m_cartes.push_back(new ElectroSorcier());
    }
    else if(type == "dragon")
    {
        m_carte = new Dragon();
      //  m_cartes.push_back(new Dragon());
    }
    else if(type == "pekka")
    {
        m_carte = new Pekka();
       // m_cartes.push_back(new Pekka());
    }
    else if(type == "ballon")
    {
        m_carte = new Ballon();
      //  m_cartes.push_back(new Ballon());
    }
    else if(type == "Boule de feu")
    {
        m_carte = new BouleDeFeu();
        //m_cartes.push_back(new BouleDeFeu());
    }
    else if(type == "Foudre")
    {
        m_carte = new Foudre();
       // m_cartes.push_back(new Foudre());
    }
    else if(type == "Poison")
    {
        m_carte = new Poison();
    }
    else if(type == "Rage")
    {
        m_carte = new Rage();
    }
    else if(type == "Soin")
    {
        m_carte = new Soin();
    }
    else if(type == "Boule de neige")
    {
        m_carte = new BouleDeNeige();
    }
    else if(type == "Clonage")
    {
        m_carte = new Clonage();
    }
    else if(type == "Bouclier")
    {
        m_carte = new Bouclier();
    }
}


std::string Enjeu::nomCarteEnjeu()
{
    return m_carte->getNom();
    //return m_cartes[0]->getNom();
}


void Enjeu::afficher()const
{
    m_carte->afficher();
   /* for(const auto& elem : m_cartes)
    {
       elem->afficher();
    }*/
    std::cout << std::endl;

}
