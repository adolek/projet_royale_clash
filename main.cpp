#include <iostream>
#include <string>
#include "partie.h"
#include "joueur.h"
#include "creature.h"
#include "speciale.h"
#include "energie.h"


int menu(Partie &partie, bool&finDeJeu)
{
    std::string pseudo;
    int choix;

    do
    {
        std::cout <<"MENU :" << std::endl << "1/ Lancer un match" << std::endl << "2/ Creer un nouveau joueur et sa collection" << std::endl << "3/ Boutique " << std::endl << "4/ Quitter le jeu" << std::endl;
        std::cin >> choix;

    }while(choix!=1 && choix!=2 && choix!=3 && choix!=4);

    switch(choix)
    {
    case 1:
        partie.lancer();

        break;
    case 2:
        partie.creerJoueur();
        partie.initCollection();

        break;
    case 3:
        partie.boutique();

        break;
    case 4:
        partie.sauvegarder();
        finDeJeu = true;
        return 0;
        break;
    default:
        break;
    }
    return 0;

}

int main()
{
    Partie partie;
    bool finDeJeu = false;

    std::cout <<"ROYALE CLASH v1.06" << std::endl;
    std::cout << std::endl;


    while(finDeJeu != true)
    {
        menu(partie, finDeJeu);
    }

    return 0;
}
