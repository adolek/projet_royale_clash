#ifndef CARTE_H_INCLUDED
#define CARTE_H_INCLUDED

#include <iostream>
#include <string>


/// classe de base ///

class Carte
{
protected:
    std::string m_nom;
    std::string m_description;
    std::string m_domaine;


public:
    Carte(){};
    virtual ~Carte(){};

    std::string getNom(){return m_nom;};
    void setNom(std::string nom){m_nom = nom;};
    std::string getDomaine(){return m_domaine;};

    virtual void afficher()const;


};



#endif //CARTE_H_INCLUDED
