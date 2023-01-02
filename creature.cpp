#include <iostream>
#include "creature.h"


Creature::Creature() : Carte()
{
    m_pointsVie = 100;
}


void Creature::afficher()const
{
    Carte::afficher();
    std::cout << "pv : " << m_pointsVie << std::endl;

}


Geant::Geant() : Creature()
{
    m_nom = "geant";
    m_description = "je suis un geant";
    m_domaine = "terrestre";
    m_pointsDegatsAttaque1 = 30;
    m_pointsDegatsAttaque2 = 60;
}


void Geant::attaque1(Creature&a)
{
    std::cout << "ATTAQUE!" << std::endl;
    std::cout << std::endl;
    a.setPointsVie(a.getPointsVie()- m_pointsDegatsAttaque1);

}

void Geant::attaque2(Creature&a)
{
    std::cout << "ATTAQUE!" << std::endl;
    std::cout << std::endl;
    a.setPointsVie(a.getPointsVie()- m_pointsDegatsAttaque2);

}

ElectroSorcier::ElectroSorcier() : Creature()
{
    m_nom = "electrosorcier";
    m_description = "je suis un electro sorcier";
    m_domaine = "electricite";
    m_pointsDegatsAttaque1 = 30;
    m_pointsDegatsAttaque2 = 60;
}

void ElectroSorcier::attaque1(Creature&a)
{
    std::cout << "ATTAQUE!" << std::endl;
    std::cout << std::endl;
    a.setPointsVie(a.getPointsVie()- m_pointsDegatsAttaque1);

}

void ElectroSorcier::attaque2(Creature&a)
{
    std::cout << "ATTAQUE!" << std::endl;
    std::cout << std::endl;
    a.setPointsVie(a.getPointsVie()- m_pointsDegatsAttaque2);

}

Dragon::Dragon() : Creature()
{
    m_nom = "dragon";
    m_description = "je suis un dragon";
    m_domaine = "feu";
    m_pointsDegatsAttaque1 = 30;
    m_pointsDegatsAttaque2 = 60;
}

void Dragon::attaque1(Creature&a)
{
    std::cout << "ATTAQUE!" << std::endl;
    std::cout << std::endl;
    a.setPointsVie(a.getPointsVie()- m_pointsDegatsAttaque1);

}

void Dragon::attaque2(Creature&a)
{
    std::cout << "ATTAQUE!" << std::endl;
    std::cout << std::endl;
    a.setPointsVie(a.getPointsVie()- m_pointsDegatsAttaque2);

}

Pekka::Pekka() : Creature()
{
    m_nom = "pekka";
    m_description = "je suis un pekka";
    m_domaine = "terrestre";
    m_pointsDegatsAttaque1 = 30;
    m_pointsDegatsAttaque2 = 60;

}

void Pekka::attaque1(Creature&a)
{
    std::cout << "ATTAQUE!" << std::endl;
    std::cout << std::endl;
    a.setPointsVie(a.getPointsVie()- m_pointsDegatsAttaque1);

}

void Pekka::attaque2(Creature&a)
{
    std::cout << "ATTAQUE!" << std::endl;
    std::cout << std::endl;
    a.setPointsVie(a.getPointsVie()- m_pointsDegatsAttaque2);

}

Ballon::Ballon() : Creature()
{
    m_nom = "ballon";
    m_description = "je suis un ballon";
    m_domaine = "aerien";
    m_pointsDegatsAttaque1 = 30;
    m_pointsDegatsAttaque1 = 60;

}

void Ballon::attaque1(Creature&a)
{
    std::cout << "ATTAQUE!" << std::endl;
    std::cout << std::endl;
    a.setPointsVie(a.getPointsVie()- m_pointsDegatsAttaque1);

}

void Ballon::attaque2(Creature&a)
{
    std::cout << "ATTAQUE!" << std::endl;
    std::cout << std::endl;
    a.setPointsVie(a.getPointsVie()- m_pointsDegatsAttaque2);

}
