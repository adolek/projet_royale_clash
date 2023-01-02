#include <iostream>
#include <vector>
#include <string>
#include "partie.h"


void Partie::lancer()
{
    int tourActuel = 1;
    std::string choix1="",choix2="",creature;
    int action1,action2,attaqueJoueur1,attaqueJoueur2,energiesFeu,energiesElectricite,energiesTerrestre,energiesAerien;

    std::cout << "Debut de la partie." << std::endl;
    std::cout << std::endl;
    std::cout << "Match en 1vs1 ! Merci de saisir votre pseudo de joueur afin de recuperer votre sauvegarde." << std::endl;
    std::cout << std::endl;
    std::string pseudo1,pseudo2;
    std::cout << "Pseudo joueur 1 :" << std::endl;
    std::cin >> pseudo1;
    std::cout << std::endl;
    std::cout << "Pseudo joueur 2 :" << std::endl;
    std::cin >> pseudo2;
    std::cout << std::endl;
    m_joueurs.push_back(new Joueur(pseudo1));
    m_joueurs.push_back(new Joueur(pseudo2));

    this->charger();

    this->initDecks();
    this->melangerDecks();

    this->getJoueurs()[0]->setNbCreatures();
    this->getJoueurs()[1]->setNbCreatures();


    do
    {
        /// TOUR JOUEUR 1 ///

        std::cout << "C'est au tour de "<< this->getJoueurs()[0]->getNom() <<" de jouer !" << std::endl;
        std::cout << std::endl;
        this->getJoueurs()[0]->checkEtatCreatureActive();

        this->getJoueurs()[0]->afficherPioche();

        do
        {
            std::cout << "Souhaitez vous jouer cette carte ? (repondre par oui ou non)" << std::endl;
            std::cin >> choix1;

        }
        while(choix1 != "oui" && choix1 != "non");

        if (choix1 == "oui")
        {
            if(this->getJoueurs()[0]->getZone().getSpecialeActive())
            {
                std::string type = this->getJoueurs()[0]->getPioche().premiereCarte()->getNom();
                if(type == "Soin" || type == "Rage" || type == "Poison" || type == "Boule de neige" || type == "Clonage" || type == "Bouclier")
                {
                    if(this->getJoueurs()[0]->getZone().getSpeciale()->getCycleDeVie() == 0)  // retour dans la pioche
                    {
                        this->getJoueurs()[0]->getPioche().ajouterCarte(this->getJoueurs()[0]->getZone().getSpeciale()->getNom());  // ajout en bas de la pioche
                    }
                    else
                    {
                        this->getJoueurs()[0]->getCimetiere().ajouterCarte(this->getJoueurs()[0]->getZone().getSpeciale()->getNom());   // ajout au cimetiere
                    }

                    this->getJoueurs()[0]->supprimerSpeciale(*this->getJoueurs()[1]);

                }

            }

            if(this->getJoueurs()[0]->getZone().getCreatureActive())
            {
                std::string type = this->getJoueurs()[0]->getPioche().premiereCarte()->getNom();

                 if(type == "geant" || type == "electrosorcier" || type == "dragon" || type == "pekka" || type == "ballon")
                 {
                     this->getJoueurs()[0]->getPioche().ajouterCarte(this->getJoueurs()[0]->getZone().getSpeciale()->getNom());   // retour en bas de la pioche
                     this->getJoueurs()[0]->getZone().supprimerCreature();
                 }

            }

            this->getJoueurs()[0]->jouerLaCarte();

        }
        else if (choix1 == "non")
        {
            this->getJoueurs()[0]->retourCarteDansPioche();
            std::cout << "La carte a ete remise sous votre pioche" << std::endl;
        }
        else
        {
            std::cout << "erreur de saisie" << std::endl;
        }


        if(this->getJoueurs()[0]->getZone().getSpecialeActive())
        {
            this->getJoueurs()[0]->actionsSpeciales(*this->getJoueurs()[1]);
        }


        this->getJoueurs()[0]->getPioche().afficher();
        this->getJoueurs()[0]->afficherZoneDeJeu();
        this->getJoueurs()[0]->afficherPointsEnergie();

        do
        {
            std::cout << "Que souhaitez vous faire ?" << std::endl;
            std::cout << "1/ attaquer     2/ ne rien faire" << std::endl;
            std::cin >> action1;

        }
        while(action1 != 1 && action1 != 2);

        switch(action1)
        {
        case 1:
            if(this->getJoueurs()[1]->getZone().getCreatureActive())
            {
                this->getJoueurs()[0]->afficherPointsEnergie();
                creature = this->getJoueurs()[0]->getZone().getNomCreature();
                energiesFeu = this->getJoueurs()[0]->getZone().getNbEnergieFeu();
                energiesElectricite = this->getJoueurs()[0]->getZone().getNbEnergieElectricite();
                energiesTerrestre = this->getJoueurs()[0]->getZone().getNbEnergieTerrestre();
                energiesAerien = this->getJoueurs()[0]->getZone().getNbEnergieAerien();
                this->getJoueurs()[0]->analyseAttaques(creature, energiesFeu, energiesElectricite, energiesTerrestre, energiesAerien);

                do
                {
                    std::cout << "Quelle attaque souhaitez vous utilisez ?" << std::endl;
                    std::cout << "1/ attaque 1     2/ attaque 2    3/ ne pas attaquer" << std::endl;
                    std::cin >> attaqueJoueur1;

                }
                while(attaqueJoueur1 != 1 && attaqueJoueur1 != 2 && attaqueJoueur1 != 3);

                switch(attaqueJoueur1)
                {
                case 1:

                    if(this->getJoueurs()[0]->decisionAttaques(1,creature, energiesFeu, energiesElectricite, energiesTerrestre, energiesAerien))
                    {

                        this->getJoueurs()[0]->getZone().getCreature()->attaque1(*this->getJoueurs()[1]->getZone().getCreature());  //attaque
                        this->getJoueurs()[0]->supprimerEnergies(creature,1);

                        if(this->getJoueurs()[0]->getZone().getSpecialeActive() && this->getJoueurs()[0]->getZone().getSpeciale()->getCycleDeVie() == 1)
                        {
                            this->getJoueurs()[0]->supprimerSpeciale(*this->getJoueurs()[1]);
                        }

                    }
                    else
                    {
                        std::cout << "Vous n'avez pas les points d'energie requis pour lancer l'attaque 1 !" << std::endl;
                    }

                    break;
                case 2:

                    if(this->getJoueurs()[0]->decisionAttaques(2,creature, energiesFeu, energiesElectricite, energiesTerrestre, energiesAerien))
                    {

                        this->getJoueurs()[0]->getZone().getCreature()->attaque2(*this->getJoueurs()[1]->getZone().getCreature());
                        this->getJoueurs()[0]->supprimerEnergies(creature,2);

                        if(this->getJoueurs()[0]->getZone().getSpecialeActive() && this->getJoueurs()[0]->getZone().getSpeciale()->getCycleDeVie() == 1)
                        {
                            this->getJoueurs()[0]->supprimerSpeciale(*this->getJoueurs()[1]);
                        }
                    }
                    else
                    {
                        std::cout << "Vous n'avez pas les points d'energie requis pour lancer l'attaque 2 !" << std::endl;
                    }
                    break;
                case 3:
                    break;
                default:
                    break;
                }

                /// affichage creatures

                this->getJoueurs()[0]->afficherCreature();
                this->getJoueurs()[1]->afficherCreature();

            }
            else
            {
                std::cout << "Votre adversaire n'a pas de creature posee, vous ne pouvez pas lancer d'attaques." << std::endl;
            }

            break;
        case 2:
            break;
        default:
            break;
        }


        /// TOUR JOUEUR 2 ///

        std::cout << "C'est au tour de "<< this->getJoueurs()[1]->getNom() <<" de jouer !" << std::endl;
        std::cout << std::endl;
        this->getJoueurs()[1]->checkEtatCreatureActive();

        this->getJoueurs()[1]->afficherPioche();

        do
        {
            std::cout << "Souhaitez vous jouer cette carte ? (repondre par oui ou non)" << std::endl;
            std::cin >> choix2;

        }
        while(choix2 != "oui" && choix2 != "non");


        if (choix2 == "oui")
        {
            if(this->getJoueurs()[1]->getZone().getSpecialeActive())
            {
                std::string type = this->getJoueurs()[1]->getPioche().premiereCarte()->getNom();
                if(type == "Soin" || type == "Rage" || type == "Poison" || type == "Boule de neige" || type == "Clonage" || type == "Bouclier")
                {
                    if(this->getJoueurs()[1]->getZone().getSpeciale()->getCycleDeVie() == 0)  // retour dans la pioche
                    {
                        this->getJoueurs()[1]->getPioche().ajouterCarte(this->getJoueurs()[1]->getZone().getSpeciale()->getNom());  // ajout en bas de la pioche
                    }
                    else
                    {
                        this->getJoueurs()[1]->getCimetiere().ajouterCarte(this->getJoueurs()[1]->getZone().getSpeciale()->getNom());   // ajout au cimetiere
                    }

                    this->getJoueurs()[1]->supprimerSpeciale(*this->getJoueurs()[0]);

                }
            }

            if(this->getJoueurs()[1]->getZone().getCreatureActive())
            {
                std::string type = this->getJoueurs()[1]->getPioche().premiereCarte()->getNom();

                 if(type == "geant" || type == "electrosorcier" || type == "dragon" || type == "pekka" || type == "ballon")
                 {
                     this->getJoueurs()[1]->getPioche().ajouterCarte(this->getJoueurs()[1]->getZone().getSpeciale()->getNom());   // retour en bas de la pioche
                     this->getJoueurs()[1]->getZone().supprimerCreature();
                 }

            }

            this->getJoueurs()[1]->jouerLaCarte();

        }
        else if (choix2 == "non")
        {
            this->getJoueurs()[1]->retourCarteDansPioche();
            std::cout << "La carte a ete remise sous votre pioche" << std::endl;
        }
        else
        {
            std::cout << "erreur de saisie" << std::endl;
        }


        if(this->getJoueurs()[1]->getZone().getSpecialeActive())
        {
            this->getJoueurs()[1]->actionsSpeciales(*this->getJoueurs()[0]);
        }


        this->getJoueurs()[1]->getPioche().afficher();
        this->getJoueurs()[1]->afficherZoneDeJeu();
        this->getJoueurs()[1]->afficherPointsEnergie();

        do
        {
            std::cout << "Que souhaitez vous faire ?" << std::endl;
            std::cout << "1/ attaquer  2/ ne rien faire" << std::endl;
            std::cin >> action2;

        }
        while(action2 != 1 && action2 != 2);

        switch(action2)
        {
        case 1:
            if(this->getJoueurs()[0]->getZone().getCreatureActive())
            {
                this->getJoueurs()[1]->afficherPointsEnergie();
                creature = this->getJoueurs()[1]->getZone().getNomCreature();
                energiesFeu = this->getJoueurs()[1]->getZone().getNbEnergieFeu();
                energiesElectricite = this->getJoueurs()[1]->getZone().getNbEnergieElectricite();
                energiesTerrestre = this->getJoueurs()[1]->getZone().getNbEnergieTerrestre();
                energiesAerien = this->getJoueurs()[1]->getZone().getNbEnergieAerien();
                this->getJoueurs()[1]->analyseAttaques(creature, energiesFeu, energiesElectricite, energiesTerrestre, energiesAerien);

                do
                {
                    std::cout << "Quelle attaque souhaitez vous utilisez ?" << std::endl;
                    std::cout << "1/ attaque 1     2/ attaque 2    3/ ne pas attaquer" << std::endl;
                    std::cin >> attaqueJoueur2;

                }
                while(attaqueJoueur2 != 1 && attaqueJoueur2 != 2 && attaqueJoueur2 != 3);

                switch(attaqueJoueur2)
                {
                case 1:

                    if(this->getJoueurs()[1]->decisionAttaques(1,creature, energiesFeu, energiesElectricite, energiesTerrestre, energiesAerien))
                    {
                        this->getJoueurs()[1]->getZone().getCreature()->attaque1(*this->getJoueurs()[0]->getZone().getCreature());
                        this->getJoueurs()[1]->supprimerEnergies(creature,1);

                        if(this->getJoueurs()[1]->getZone().getSpecialeActive() && this->getJoueurs()[1]->getZone().getSpeciale()->getCycleDeVie() == 1)
                        {
                            this->getJoueurs()[1]->supprimerSpeciale(*this->getJoueurs()[0]);
                        }
                    }
                    else
                    {
                        std::cout << "Vous n'avez pas les points d'energie requis pour lancer l'attaque 1 !" << std::endl;
                    }

                    break;
                case 2:

                    if(this->getJoueurs()[1]->decisionAttaques(2,creature, energiesFeu, energiesElectricite, energiesTerrestre, energiesAerien))
                    {
                        this->getJoueurs()[1]->getZone().getCreature()->attaque2(*this->getJoueurs()[0]->getZone().getCreature());
                        this->getJoueurs()[1]->supprimerEnergies(creature,2);

                        if(this->getJoueurs()[1]->getZone().getSpecialeActive() && this->getJoueurs()[1]->getZone().getSpeciale()->getCycleDeVie() == 1)
                        {
                            this->getJoueurs()[1]->supprimerSpeciale(*this->getJoueurs()[0]);
                        }
                    }
                    else
                    {
                        std::cout << "Vous n'avez pas les points d'energie requis pour lancer l'attaque 2 !" << std::endl;
                    }
                    break;
                case 3:
                    break;
                default:
                    break;
                }

                /// affichage creatures

                this->getJoueurs()[0]->afficherCreature();
                this->getJoueurs()[1]->afficherCreature();
            }
            else
            {
                std::cout << "Votre adversaire n'a pas de creature posee, votre attaque n'a pas d'effet." << std::endl;
            }

            break;
        case 2:
            break;
        default:
            break;
        }

        tourActuel++;

        std::cout << this->getJoueurs()[0]->getPointsVie() << std::endl;
        std::cout << this->getJoueurs()[1]->getPointsVie() << std::endl;

    }
    while((this->getJoueurs()[0]->getPointsVie() > 0) && (this->getJoueurs()[1]->getPointsVie() > 0) && (this->getJoueurs()[0]->getNbCreatures() > 0) && (this->getJoueurs()[1]->getNbCreatures() > 0));  /// tant qu'un des 2 joueurs n'a pas perdu

    /// En cas de victoire du joueur 2
    if(this->getJoueurs()[0]->getPointsVie() == 0 || this->getJoueurs()[0]->getNbCreatures() == 0)
    {
        std::cout << "Felicitations " << this->getJoueurs()[1]->getNom() << ", vous avez remporte la partie !" << std::endl;
        this->getJoueurs()[1]->setPieces(this->getJoueurs()[1]->getPieces() + 20);
        std::cout << "La carte enjeu de " << this->getJoueurs()[0]->getNom() << " etait : " << this->getJoueurs()[0]->getEnjeu().nomCarteEnjeu() << std::endl;
        this->getJoueurs()[1]->ajoutCarteCollection(this->getJoueurs()[0]->getEnjeu().nomCarteEnjeu());
        this->getJoueurs()[0]->retraitCarteCollection(this->getJoueurs()[0]->getEnjeu().nomCarteEnjeu());
        std::cout << "L'enjeu de " << this->getJoueurs()[0]->getNom() << " a ete ajoute a la collection de " << this->getJoueurs()[1]->getNom() << " avec succes !" << std::endl;

    }

    /// En cas de victoire du joueur 1
    else
    {
        std::cout << "Felicitations " << this->getJoueurs()[0]->getNom() << ", vous avez remporte la partie !" << std::endl;
        this->getJoueurs()[0]->setPieces(this->getJoueurs()[0]->getPieces() + 20);
        std::cout << "La carte enjeu de " << this->getJoueurs()[1]->getNom() << " etait : " << this->getJoueurs()[1]->getEnjeu().nomCarteEnjeu() << std::endl;
        this->getJoueurs()[0]->ajoutCarteCollection(this->getJoueurs()[1]->getEnjeu().nomCarteEnjeu());
        this->getJoueurs()[1]->retraitCarteCollection(this->getJoueurs()[1]->getEnjeu().nomCarteEnjeu());
        std::cout << "L'enjeu de " << this->getJoueurs()[1]->getNom() << " a ete ajoute a la collection de " << this->getJoueurs()[0]->getNom() << " avec succes !" << std::endl;
    }

    this->sauvegarder();

}



void Partie::creerJoueur()
{
    std::string pseudo;
    std::cout << "Creation du nouveau joueur :" << std::endl;
    std::cout << "Quel est votre pseudo ?" << std::endl;
    std::cin >> pseudo;
    m_joueurs.push_back(new Joueur(pseudo));
    m_joueurs[m_joueurs.size()-1]->afficher();

}


void Partie::initCollection()
{
    m_joueurs[m_joueurs.size()-1]->creerCollection();
    m_joueurs[m_joueurs.size()-1]->enregistrerCollection();

    m_joueurs.clear();

}


void Partie::initDecks()
{
    for(unsigned int i=0; i<m_joueurs.size(); ++i)
    {
        m_joueurs[i]->creerDeck();
    }
}


void Partie::melangerDecks()
{
    for(unsigned int i=0; i<m_joueurs.size(); ++i)
    {
        m_joueurs[i]->melangerDeck();
    }
}


void Partie::sauvegarder()
{
    for(unsigned int i=0; i<m_joueurs.size(); ++i)
    {
        m_joueurs[i]->enregistrerCollection();
    }
}


void Partie::charger()
{
    for(unsigned int i=0; i<m_joueurs.size(); ++i)
    {
        m_joueurs[i]->chargerCollection();
        m_joueurs[i]->afficherCollection();
    }
    for(unsigned int i=0; i<m_joueurs.size(); ++i)
    {
        m_joueurs[i]->afficher();

    }

}


void Partie::boutique()
{
    std::string pseudo = "", carte = "";

    std::cout << "Bienvenue dans la boutique !"<< std::endl;
    std::cout << std::endl;
    std::cout << "Pour quel joueur souhaitez vous acheter des cartes ?"<< std::endl;
    std::cin >> pseudo;
    m_joueurs.push_back(new Joueur(pseudo));

    m_joueurs[m_joueurs.size()-1]->chargerCollection();
    m_joueurs[m_joueurs.size()-1]->afficher();
    m_joueurs[m_joueurs.size()-1]->afficherCollection();

    if(m_joueurs[m_joueurs.size()-1]->getPieces() >= 20 )
    {
        do
        {
            std::cout << "Quelle carte souhaitez vous acheter ?"<< std::endl;
            std::cin >> carte;

        }
        while(carte != "geant" && carte != "electrosorcier" && carte != "pekka" && carte != "dragon" && carte != "ballon" && carte != "Boule de feu" && carte != "Foudre" && carte != "Seisme" && carte != "Tornade");

        m_joueurs[m_joueurs.size()-1]->ajoutCarteCollection(carte);

        m_joueurs[m_joueurs.size()-1]->setPieces(m_joueurs[m_joueurs.size()-1]->getPieces()-20);
        std::cout << "La nouvelle carte '"<< carte << "' a bien ete ajoutee a votre collection." << std::endl;
        std::cout << "Merci pour votre achat, a bientot !"<< std::endl;
    }
    else
    {
        std::cout << "Vous avez besoin de 20 pieces pour acheter une nouvelle carte. Revenez quand vous aurez un minimum de 20 pieces ! A bientot !"<< std::endl;

    }

    this->sauvegarder();

    m_joueurs.clear();

}
