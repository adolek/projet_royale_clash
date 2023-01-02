#ifndef ZONEDEJEU_H_INCLUDED
#define ZONEDEJEU_H_INCLUDED

#include <iostream>
#include <vector>
#include <string>
#include "carte.h"
#include "creature.h"
#include "energie.h"
#include "speciale.h"


class ZoneDeJeu
{
private:
    std::vector<Energie*> m_energies;
    int m_nbEnergieFeu;
    int m_nbEnergieElectricite;
    int m_nbEnergieTerrestre;
    int m_nbEnergieAerien;

    Creature* m_creature;
    Speciale* m_speciale;

    bool m_creatureActive;
    bool m_specialeActive;


public:
    ZoneDeJeu(){m_creatureActive=false; m_specialeActive=false;};
    ~ZoneDeJeu(){};

    Creature* getCreature(){return m_creature;};
    Speciale* getSpeciale(){return m_speciale;};
    int getNbEnergieFeu(){return m_nbEnergieFeu;};
    int getNbEnergieElectricite(){return m_nbEnergieElectricite;};
    int getNbEnergieTerrestre(){return m_nbEnergieTerrestre;};
    int getNbEnergieAerien(){return m_nbEnergieAerien;};
    bool getCreatureActive(){return m_creatureActive;};
    bool getSpecialeActive(){return m_specialeActive;};

    int pvCreature();
    bool checkEtatCreatureActive();
    std::string getNomCreature();
    std::string getNomSpeciale();
    void supprimerCreature();
    void supprimerSpeciale();

    void ajouterCarte(std::string type);
    void afficherCreature();
    void afficherSpeciale();
    void afficherPtsEnergie();
    void suppressionEnergies(int energiesFeu, int energiesElectricite, int energiesTerrestre, int energiesAerien);
    void afficher()const;


};


#endif //ZONEDEJEU_H_INCLUDED



