#include <iostream>
#include "carte.h"


void Carte::afficher()const
{
    std::cout << "nom : " << m_nom << " / description : " << m_description << " / domaine : " << m_domaine << std::endl;
}
