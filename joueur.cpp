#include <iostream>
#include "joueur.h"


void Joueur::afficher()const
{
    std::cout << "nom : " << m_nom << " / pieces : " << m_pieces << std::endl;
}

void Joueur::setNbCreatures()
{
    int nb = m_pioche.getNbCreatures();
    m_nbCreatures = nb;
}

void Joueur::ajoutCarteCollection(std::string type)
{
    m_collection.ajouterCarte(type);
}

void Joueur::retraitCarteCollection(std::string type)
{

    if(type == "geant")
    {
         m_collection.setNbGeants(m_collection.getNbGeants()-1);
    }
    if(type == "electrosorcier")
    {
         m_collection.setNbSorciers(m_collection.getNbSorciers()-1);
    }
    if(type == "dragon")
    {
         m_collection.setNbDragons(m_collection.getNbDragons()-1);
    }
    if(type == "pekka")
    {
         m_collection.setNbPekkas(m_collection.getNbPekkas()-1);
    }
    if(type == "ballon")
    {
         m_collection.setNbBallons(m_collection.getNbBallons()-1);
    }
    if(type == "Boule de feu")
    {
         m_collection.setNbBDF(m_collection.getNbBDF()-1);
    }
    if(type == "Foudre")
    {
         m_collection.setNbFoudre(m_collection.getNbFoudre()-1);
    }
    if(type == "Seisme")
    {
         m_collection.setNbSeisme(m_collection.getNbSeisme()-1);
    }
    if(type == "Tornade")
    {
         m_collection.setNbTornade(m_collection.getNbTornade()-1);
    }
    if(type == "Poison")
    {
         m_collection.setNbPoison(m_collection.getNbPoison()-1);
    }
    if(type == "Rage")
    {
         m_collection.setNbRage(m_collection.getNbRage()-1);
    }
    if(type == "Soin")
    {
         m_collection.setNbSoin(m_collection.getNbSoin()-1);
    }
    if(type == "Boule de neige")
    {
         m_collection.setNbBDN(m_collection.getNbBDN()-1);
    }
    if(type == "Clonage")
    {
         m_collection.setNbClonage(m_collection.getNbClonage()-1);
    }
    if(type == "Bouclier")
    {
         m_collection.setNbBouclier(m_collection.getNbBouclier()-1);
    }


    m_collection.retirerCarte(type);
}



void Joueur::ajoutCarteDeck(std::string type)
{
    m_deck.ajouterCarte(type);
}

void Joueur::afficherCollection()const
{
    std::cout << "Collection de " << m_nom << " :" << std::endl;
    m_collection.afficher();
}

void Joueur::afficherDeck()const
{
    std::cout << "Deck de " << m_nom << " :" << std::endl;
    m_deck.afficher();
}

void Joueur::afficherZoneDeJeu()const
{
    std::cout << "Zone de jeu de " << m_nom << " :" << std::endl;
    m_zone.afficher();
}

void Joueur::afficherPointsEnergie()
{
    m_zone.afficherPtsEnergie();
    std::cout << std::endl;
}

void Joueur::afficherCreature()
{
    std::cout << "Creature active de " << m_nom << " :" << std::endl;
    m_zone.afficherCreature();
}


void Joueur::enregistrerCollection()
{
    std::string extension = ".txt";
    std::string nomFichier = m_nom + extension;
    std::ofstream ofs(nomFichier, std::ios::out);
    if (ofs)
    {
        ofs << m_nom << std::endl;
        ofs << m_pieces << std::endl;

        ofs.close(); // fermeture du flux
    }
    m_collection.enregistrer(nomFichier);
}

void Joueur::chargerCollection()
{
    std::string extension = ".txt";
    std::string nomFichier = m_nom + extension;
    std::ifstream fichier;
    fichier.open(nomFichier);
    int pieces;
    std::string nom;

    fichier >> nom;
    fichier >> pieces;
    m_pieces = pieces;
    m_nom = nom;

    fichier.close();

    m_collection.charger(nomFichier);

}


void Joueur::creerDeck()
{
    unsigned int geants=0, sorciers=0, dragons=0, ballons=0, pekkas=0, bdf=0, foudre=0, seisme=0, tornade=0, poison=0, rage=0, soin=0, bdn=0, clonage=0, bouclier=0;
    std::cout << "Creation du deck de " << m_nom << std::endl;
    std::cout << "Indiquez le nombre de cartes que vous voulez ajouter a votre deck dans l'ordre suivant :" << std::endl;
    std::cout << "Geant ElectroSorcier Dragon Ballon Pekka BouleDeFeu Foudre Seisme Tornade Poison Rage Soin BouleDeNeige Clonage Bouclier" << std::endl;
    std::cin >> geants >> sorciers >> dragons >> ballons >> pekkas >> bdf >> foudre >> seisme >> tornade >> poison >> rage >> soin >> bdn >> clonage >> bouclier;

    for(unsigned int i=0; i<geants; ++i)
    {
        this->ajoutCarteDeck("geant");
    }
    for(unsigned int i=0; i<sorciers; ++i)
    {
        this->ajoutCarteDeck("electrosorcier");
    }
    for(unsigned int i=0; i<dragons; ++i)
    {
        this->ajoutCarteDeck("dragon");
    }
    for(unsigned int i=0; i<ballons; ++i)
    {
        this->ajoutCarteDeck("ballon");
    }
    for(unsigned int i=0; i<pekkas; ++i)
    {
        this->ajoutCarteDeck("pekka");
    }
    for(unsigned int i=0; i<bdf; ++i)
    {
        this->ajoutCarteDeck("Boule de feu");
    }
    for(unsigned int i=0; i<foudre; ++i)
    {
        this->ajoutCarteDeck("Foudre");
    }
    for(unsigned int i=0; i<seisme; ++i)
    {
        this->ajoutCarteDeck("Seisme");
    }
    for(unsigned int i=0; i<tornade; ++i)
    {
        this->ajoutCarteDeck("Tornade");
    }
    for(unsigned int i=0; i<poison; ++i)
    {
        this->ajoutCarteDeck("Poison");
    }
    for(unsigned int i=0; i<rage; ++i)
    {
        this->ajoutCarteDeck("Rage");
    }
    for(unsigned int i=0; i<soin; ++i)
    {
        this->ajoutCarteDeck("Soin");
    }
    for(unsigned int i=0; i<bdn; ++i)
    {
        this->ajoutCarteDeck("Boule de neige");
    }
    for(unsigned int i=0; i<clonage; ++i)
    {
        this->ajoutCarteDeck("Clonage");
    }
    for(unsigned int i=0; i<bouclier; ++i)
    {
        this->ajoutCarteDeck("Bouclier");
    }

    this->afficherDeck();

}



void Joueur::creerCollection()
{
    unsigned int geants=0, sorciers=0, dragons=0, ballons=0, pekkas=0, bdf=0, foudre=0, seisme=0, tornade=0, poison=0, rage=0, soin=0, bdn=0, clonage=0, bouclier=0;
    std::cout << "Creation de la collection de " << m_nom << std::endl;
    std::cout << "Indiquez le nombre de creatures que vous souhaitez ajouter a votre collection dans l'ordre suivant :" << std::endl;
    std::cout << "Geant ElectroSorcier Dragon Ballon Pekka BouleDeFeu Foudre Seisme Tornade Poison Rage Soin BouleDeNeige Clonage Bouclier" << std::endl;
    std::cin >> geants >> sorciers >> dragons >> ballons >> pekkas >> bdf >> foudre >> seisme >> tornade >> poison >> rage >> soin >> bdn >> clonage >> bouclier;

    for(unsigned int i=0; i<geants; ++i)
    {
        this->ajoutCarteCollection("geant");
    }
    for(unsigned int i=0; i<sorciers; ++i)
    {
        this->ajoutCarteCollection("electrosorcier");
    }
    for(unsigned int i=0; i<dragons; ++i)
    {
        this->ajoutCarteCollection("dragon");
    }
    for(unsigned int i=0; i<ballons; ++i)
    {
        this->ajoutCarteCollection("ballon");
    }
    for(unsigned int i=0; i<pekkas; ++i)
    {
        this->ajoutCarteCollection("pekka");
    }
    for(unsigned int i=0; i<bdf; ++i)
    {
        this->ajoutCarteCollection("Boule de feu");
    }
    for(unsigned int i=0; i<foudre; ++i)
    {
        this->ajoutCarteCollection("Foudre");
    }
    for(unsigned int i=0; i<seisme; ++i)
    {
        this->ajoutCarteCollection("Seisme");
    }
    for(unsigned int i=0; i<tornade; ++i)
    {
        this->ajoutCarteCollection("Tornade");
    }
    for(unsigned int i=0; i<poison; ++i)
    {
        this->ajoutCarteCollection("Poison");
    }
    for(unsigned int i=0; i<rage; ++i)
    {
        this->ajoutCarteCollection("Rage");
    }
    for(unsigned int i=0; i<soin; ++i)
    {
        this->ajoutCarteCollection("Soin");
    }
    for(unsigned int i=0; i<bdn; ++i)
    {
        this->ajoutCarteCollection("Boule de neige");
    }
    for(unsigned int i=0; i<clonage; ++i)
    {
        this->ajoutCarteCollection("Clonage");
    }
    for(unsigned int i=0; i<bouclier; ++i)
    {
        this->ajoutCarteCollection("Bouclier");
    }

    this->afficherCollection();

}


void Joueur::melangerDeck()
{
    std::string enjeu;

    m_deck.melanger();

    enjeu = m_deck.getCartes()[m_deck.getCartes().size()-1]->getNom();

    m_enjeu.ajouterCarte(enjeu);

    std::cout << "Enjeu de " << m_nom << std::endl;
    m_enjeu.afficher();

    for(unsigned int i=0; i<m_deck.getCartes().size()-1; ++i)
    {
        m_pioche.ajouterCarte(m_deck.getCartes()[i]->getNom());
    }

    std::cout << "Pioche de " << m_nom << std::endl;
    m_pioche.afficher();

}


void Joueur::afficherPioche()
{
    m_pioche.premiereCarteAfficher();
}

void Joueur::retourCarteDansPioche()
{
    m_pioche.ajouterCarte(m_pioche.premiereCarte()->getNom());
    m_pioche.popPremiereCarte();

}

void Joueur::jouerLaCarte()
{
    m_zone.ajouterCarte(m_pioche.premiereCarte()->getNom());
    m_pioche.popPremiereCarte();

}



void Joueur::checkEtatCreatureActive()   /// check les pdv de la creature de la zone pour savoir si elle est morte -> push cimetiere, si creature meurt on decremente pdv du joueur
{
    bool etatCreature;
    std::string nomCreature;
    etatCreature = m_zone.checkEtatCreatureActive();

    if(etatCreature == true)  // si la creature active est morte
    {
        nomCreature = m_zone.getNomCreature();
        this->setPointsVie(this->getPointsVie() + this->getZone().pvCreature());
        m_zone.supprimerCreature();
        this->getCimetiere().ajouterCarte(nomCreature);
        m_nbCreatures--;
        std::cout << "Votre creature active '" << nomCreature << "' est morte, elle a ete envoyee au cimetiere." << std::endl;
    }

}



void Joueur::analyseAttaques(std::string creature, int energiesFeu, int energiesElectricite, int energiesTerrestre, int energiesAerien)
{
    if(creature == "electrosorcier")
    {
        std::cout << "Attaque 1 necessite 1 pt d'energie de type 'electricite'." << std::endl;
        std::cout << "Attaque 2 necessite 2 pt d'energie de type 'electricite'." << std::endl;

        if(energiesElectricite >= 1) std::cout << "Vous pouvez utiliser l'attaque 1 !" << std::endl;

        else if(energiesElectricite >= 2) std::cout << "Vous pouvez utiliser l'attaque 2 !" << std::endl;

        else std::cout << "Vous ne pouvez utiliser aucune attaque !" << std::endl;

    }

    else if(creature == "geant")
    {
        std::cout << "Attaque 1 necessite 1 pt d'energie de type 'terrestre'." << std::endl;
        std::cout << "Attaque 2 necessite 2 pt d'energie de type 'terrestre'." << std::endl;

        if(energiesTerrestre >= 1) std::cout << "Vous pouvez utiliser l'attaque 1 !" << std::endl;

        else if(energiesTerrestre >= 2) std::cout << "Vous pouvez utiliser l'attaque 2 !" << std::endl;

        else std::cout << "Vous ne pouvez utiliser aucune attaque !" << std::endl;

    }

    else if(creature == "ballon")
    {
        std::cout << "Attaque 1 necessite 1 pt d'energie de type 'aerien'." << std::endl;
        std::cout << "Attaque 2 necessite 2 pt d'energie de type 'aerien'." << std::endl;

        if(energiesAerien >= 1) std::cout << "Vous pouvez utiliser l'attaque 1 !" << std::endl;

        else if(energiesAerien >= 2) std::cout << "Vous pouvez utiliser l'attaque 2 !" << std::endl;

        else std::cout << "Vous ne pouvez utiliser aucune attaque !" << std::endl;

    }

    else if(creature == "pekka")
    {
        std::cout << "Attaque 1 necessite 1 pt d'energie de type 'terrestre'." << std::endl;
        std::cout << "Attaque 2 necessite 2 pt d'energie de type 'terrestre'." << std::endl;

        if(energiesTerrestre >= 1) std::cout << "Vous pouvez utiliser l'attaque 1 !" << std::endl;

        else if(energiesTerrestre >= 2) std::cout << "Vous pouvez utiliser l'attaque 2 !" << std::endl;

        else std::cout << "Vous ne pouvez utiliser aucune attaque !" << std::endl;

    }

    else if(creature == "dragon")
    {
        std::cout << "Attaque 1 necessite 1 pt d'energie de type 'feu'." << std::endl;
        std::cout << "Attaque 2 necessite 1 pt d'energie de type 'feu' et 1 pt d'energie de type 'aerien'." << std::endl;

        if(energiesFeu >= 1) std::cout << "Vous pouvez utiliser l'attaque 1 !" << std::endl;

        else if(energiesFeu >= 1 && energiesAerien >= 1) std::cout << "Vous pouvez utiliser l'attaque 2 !" << std::endl;

        else std::cout << "Vous ne pouvez utiliser aucune attaque !" << std::endl;

    }


}


bool Joueur::decisionAttaques(int noAttaque, std::string creature, int energiesFeu, int energiesElectricite, int energiesTerrestre, int energiesAerien)
{
    if(creature == "electrosorcier")
    {
        if(noAttaque == 1)
        {
            if(energiesElectricite >= 1) return true;
            else return false;
        }

        else if(noAttaque == 2)
        {
            if(energiesElectricite >= 2) return true;
            else return false;
        }
        else return false;
    }

    else if(creature == "geant")
    {
        if(noAttaque == 1)
        {
            if(energiesTerrestre >= 1) return true;
            else return false;
        }

        else if(noAttaque == 2)
        {
            if(energiesTerrestre >= 2) return true;
            else return false;
        }
        else return false;
    }

    else if(creature == "ballon")
    {
        if(noAttaque == 1)
        {
            if(energiesAerien >= 1) return true;
            else return false;
        }

        else if(noAttaque == 2)
        {
            if(energiesAerien >= 2) return true;
            else return false;
        }
        else return false;
    }

    else if(creature == "pekka")
    {
        if(noAttaque == 1)
        {
            if(energiesTerrestre >= 1) return true;
            else return false;
        }

        else if(noAttaque == 2)
        {
            if(energiesTerrestre >= 2) return true;
            else return false;
        }
        else return false;
    }

    else if(creature == "dragon")
    {
        if(noAttaque == 1)
        {
            if(energiesFeu >= 1) return true;
            else return false;
        }

        else if(noAttaque == 2)
        {
            if(energiesFeu >= 1 && energiesAerien >= 1) return true;
            else return false;
        }
        else return false;
    }

    else return false;

}



void Joueur::supprimerEnergies(std::string creature, int noAttaque)
{
    if(creature == "electrosorcier")
    {
        if(noAttaque == 1)
        {
            m_zone.suppressionEnergies(0,1,0,0);
        }
        else if(noAttaque == 2)
        {
            m_zone.suppressionEnergies(0,2,0,0);
        }
    }

    if(creature == "geant")
    {
        if(noAttaque == 1)
        {
            m_zone.suppressionEnergies(0,0,1,0);
        }
        else if(noAttaque == 2)
        {
            m_zone.suppressionEnergies(0,0,2,0);
        }
    }

    if(creature == "ballon")
    {
        if(noAttaque == 1)
        {
            m_zone.suppressionEnergies(0,0,0,1);
        }
        else if(noAttaque == 2)
        {
            m_zone.suppressionEnergies(0,0,0,2);
        }
    }

    if(creature == "pekka")
    {
        if(noAttaque == 1)
        {
            m_zone.suppressionEnergies(0,0,1,0);
        }
        else if(noAttaque == 2)
        {
            m_zone.suppressionEnergies(0,0,2,0);
        }
    }

    if(creature == "dragon")
    {
        if(noAttaque == 1)
        {
            m_zone.suppressionEnergies(1,0,0,0);
        }
        else if(noAttaque == 2)
        {
            m_zone.suppressionEnergies(1,0,0,1);
        }
    }

}



void Joueur::actionsSpeciales(Joueur& adversaire)
{
    std::string type = m_zone.getNomSpeciale();

    if(type == "Poison")
    {
        if(adversaire.getZone().getCreatureActive())
        {
            int pv = adversaire.getZone().getCreature()->getPointsVie();
            adversaire.getZone().getCreature()->setPointsVie(0.93*pv);
            std::cout << std::endl;
            std::cout << "ACTION Poison" << std::endl;
            std::cout << std::endl;

        }
    }

    if(type == "Rage")
    {
        if(this->getZone().getCreatureActive())
        {
            int degats1 = this->getZone().getCreature()->getPointsDegatsAttaque1();
            int degats2 = this->getZone().getCreature()->getPointsDegatsAttaque2();
            this->getZone().getCreature()->setPointsDegatsAttaque1(degats1 + 10);
            this->getZone().getCreature()->setPointsDegatsAttaque2(degats2 + 10);
            std::cout << std::endl;
            std::cout << "ACTION Rage" << std::endl;
            std::cout << std::endl;

        }
    }

    if(type == "Soin")
    {
        if(this->getZone().getCreatureActive())
        {
            int pv = this->getZone().getCreature()->getPointsVie();
            this->getZone().getCreature()->setPointsVie(1.05*pv);
            std::cout << std::endl;
            std::cout << "ACTION Soin" << std::endl;
            std::cout << std::endl;
        }
    }

    if(type == "Boule de neige")
    {
        if(this->getZone().getCreatureActive() && adversaire.getZone().getCreatureActive())
        {
            int degats1 = adversaire.getZone().getCreature()->getPointsDegatsAttaque1();
            int degats2 = adversaire.getZone().getCreature()->getPointsDegatsAttaque2();
            int pv = adversaire.getZone().getCreature()->getPointsVie();
            adversaire.getZone().getCreature()->setPointsDegatsAttaque1(degats1 -5);
            adversaire.getZone().getCreature()->setPointsDegatsAttaque2(degats2 -5);
            adversaire.getZone().getCreature()->setPointsVie(0.96*pv);
            std::cout << std::endl;
            std::cout << "ACTION Boule de neige" << std::endl;
            std::cout << std::endl;
        }
    }

    if(type == "Clonage")
    {
        if(this->getZone().getCreatureActive())
        {
            int degats1 = this->getZone().getCreature()->getPointsDegatsAttaque1();
            int degats2 = this->getZone().getCreature()->getPointsDegatsAttaque2();
            this->getZone().getCreature()->setPointsDegatsAttaque1(degats1*2);
            this->getZone().getCreature()->setPointsDegatsAttaque2(degats2*2);
            std::cout << std::endl;
            std::cout << "ACTION Clonage" << std::endl;
            std::cout << std::endl;

        }
    }

    if(type == "Bouclier")
    {


    }

}


void Joueur::supprimerSpeciale(Joueur& adversaire)
{
    std::string type = m_zone.getNomSpeciale();

    if(type == "Clonage")
    {
        int degats1 = this->getZone().getCreature()->getPointsDegatsAttaque1();
        int degats2 = this->getZone().getCreature()->getPointsDegatsAttaque2();
        this->getZone().getCreature()->setPointsDegatsAttaque1(degats1/2);
        this->getZone().getCreature()->setPointsDegatsAttaque2(degats2/2);
        std::cout << std::endl;
        std::cout << "suppression Clonage" << std::endl;
        std::cout << std::endl;
    }

    if(type == "Rage")
    {
        int degats1 = this->getZone().getCreature()->getPointsDegatsAttaque1();
        int degats2 = this->getZone().getCreature()->getPointsDegatsAttaque2();
        this->getZone().getCreature()->setPointsDegatsAttaque1(degats1 - 10);
        this->getZone().getCreature()->setPointsDegatsAttaque2(degats2 - 10);
        std::cout << std::endl;
        std::cout << "suppression Rage" << std::endl;
        std::cout << std::endl;

    }

    if(type == "Soin")
    {
        std::cout << std::endl;
        std::cout << "suppression Soin" << std::endl;
        std::cout << std::endl;
    }

    if(type == "Poison")
    {
        std::cout << std::endl;
        std::cout << "suppression Poison" << std::endl;
        std::cout << std::endl;
    }

    if(type == "Boule de neige")
    {
        int degats1 = adversaire.getZone().getCreature()->getPointsDegatsAttaque1();
        int degats2 = adversaire.getZone().getCreature()->getPointsDegatsAttaque2();
        adversaire.getZone().getCreature()->setPointsDegatsAttaque1(degats1 +5);
        adversaire.getZone().getCreature()->setPointsDegatsAttaque2(degats2 +5);
        std::cout << std::endl;
        std::cout << "suppression Boule de neige" << std::endl;
        std::cout << std::endl;
    }


    if(type == "Bouclier")
    {


    }


    this->getZone().supprimerSpeciale();
}


