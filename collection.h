#ifndef COLLECTION_H_INCLUDED
#define COLLECTION_H_INCLUDED

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include "carte.h"
#include "creature.h"
#include "energie.h"
#include "speciale.h"


class Collection
{
private:
    std::vector<Carte*> m_cartes;
    unsigned int m_nbGeants, m_nbSorciers, m_nbDragons, m_nbBallons, m_nbPekkas, m_nbBDF, m_nbFoudre, m_nbSeisme, m_nbTornade, m_nbPoison, m_nbRage, m_nbSoin, m_nbBDN, m_nbClonage, m_nbBouclier;


public:
    Collection();
    ~Collection(){};

    void setNbGeants(int nb){m_nbGeants = nb;};
    int getNbGeants(){return m_nbGeants;};
    void setNbSorciers(int nb){m_nbSorciers = nb;};
    int getNbSorciers(){return m_nbSorciers;};
    void setNbDragons(int nb){m_nbDragons= nb;};
    int getNbDragons(){return m_nbDragons;};
    void setNbBallons(int nb){m_nbBallons = nb;};
    int getNbBallons(){return m_nbBallons;};
    void setNbPekkas(int nb){m_nbPekkas = nb;};
    int getNbPekkas(){return m_nbPekkas;};
    void setNbBDF(int nb){m_nbBDF = nb;};
    int getNbBDF(){return m_nbBDF;};
    void setNbFoudre(int nb){m_nbFoudre = nb;};
    int getNbFoudre(){return m_nbFoudre;};
    void setNbSeisme(int nb){m_nbSeisme = nb;};
    int getNbSeisme(){return m_nbSeisme;};
    void setNbTornade(int nb){m_nbTornade = nb;};
    int getNbTornade(){return m_nbTornade;};
    void setNbPoison(int nb){m_nbPoison = nb;};
    int getNbPoison(){return m_nbPoison;};
    void setNbRage(int nb){m_nbRage = nb;};
    int getNbRage(){return m_nbRage;};
    void setNbSoin(int nb){m_nbSoin = nb;};
    int getNbSoin(){return m_nbSoin;};
    void setNbBDN(int nb){m_nbBDN = nb;};
    int getNbBDN(){return m_nbBDN;};
    void setNbClonage(int nb){m_nbClonage = nb;};
    int getNbClonage(){return m_nbClonage;};
    void setNbBouclier(int nb){m_nbBouclier= nb;};
    int getNbBouclier(){return m_nbBouclier;};


    void ajouterCarte(std::string type);
    void retirerCarte(std::string type);
    void afficher()const;

    void enregistrer(const std::string& path);
    void charger(const std::string& path);


};


#endif //COLLECTION_H_INCLUDED

