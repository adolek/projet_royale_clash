#ifndef JOUEUR_H_INCLUDED
#define JOUEUR_H_INCLUDED

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "deck.h"
#include "collection.h"
#include "enjeu.h"
#include "cimetiere.h"
#include "pioche.h"
#include "zonedejeu.h"


class Joueur
{
private:
    std::string m_nom;
    int m_pieces;
    int m_pointsVie;
    int m_nbCreatures;

    Deck m_deck;
    Collection m_collection;
    Pioche m_pioche;
    Enjeu m_enjeu;
    Cimetiere m_cimetiere;
    ZoneDeJeu m_zone;


public:
    Joueur(){m_pieces=0; m_pointsVie=25;};
    Joueur(std::string nom){m_nom = nom; m_pieces=0; m_pointsVie=25;};
    ~Joueur(){};

    std::string getNom(){return m_nom;};
    void setNom(std::string nom){m_nom = nom;};
    int getPieces(){return m_pieces;};
    void setPieces(int pieces){m_pieces = pieces;};
    int getPointsVie(){return m_pointsVie;};
    void setPointsVie(int points){m_pointsVie = points;};
    int getNbCreatures(){return m_nbCreatures;};
    void setNbCreatures();
    Pioche getPioche(){return m_pioche;};
    Enjeu getEnjeu(){return m_enjeu;};
    ZoneDeJeu getZone(){return m_zone;};
    Cimetiere getCimetiere(){return m_cimetiere;};

    void ajoutCarteCollection(std::string type);
    void retraitCarteCollection(std::string type);
    void creerCollection();
    void afficherCollection()const;
    void enregistrerCollection();
    void chargerCollection();

    void ajoutCarteDeck(std::string type);
    void creerDeck();
    void melangerDeck();
    void afficherDeck()const;

    void afficherPioche();
    void retourCarteDansPioche();
    void jouerLaCarte();
    void afficherZoneDeJeu()const;
    void afficherPointsEnergie();
    void afficherCreature();
    void checkEtatCreatureActive();

    void analyseAttaques(std::string creature, int energiesFeu, int energiesElectricite, int energiesTerrestre, int energiesAerien);
    bool decisionAttaques(int noAttaque, std::string creature, int energiesFeu, int energiesElectricite, int energiesTerrestre, int energiesAerien);
    void supprimerEnergies(std::string creature, int noAttaque);

    void supprimerSpeciale(Joueur& adversaire);
    void actionsSpeciales(Joueur& adversaire);

    void afficher()const;

};



#endif //JOUEUR_H_INCLUDED
