#include <iostream>
#include "collection.h"


Collection::Collection()
{
    m_nbDragons=0;
    m_nbGeants=0;
    m_nbPekkas=0;
    m_nbBallons=0;
    m_nbSorciers=0;
    m_nbBDF=0;
    m_nbFoudre=0;
    m_nbSeisme=0;
    m_nbTornade=0;
}


void Collection::ajouterCarte(std::string type)
{
    if(type == "geant")
    {
        m_cartes.push_back(new Geant());
        m_nbGeants++;
    }
    if(type == "electrosorcier")
    {
        m_cartes.push_back(new ElectroSorcier());
        m_nbSorciers++;
    }
    if(type == "dragon")
    {
        m_cartes.push_back(new Dragon());
        m_nbDragons++;
    }
    if(type == "pekka")
    {
        m_cartes.push_back(new Pekka());
        m_nbPekkas++;
    }
    if(type == "ballon")
    {
        m_cartes.push_back(new Ballon());
        m_nbBallons++;
    }
    if(type == "Boule de feu")
    {
        m_cartes.push_back(new BouleDeFeu());
        m_nbBDF ++;
    }
    if(type == "Foudre")
    {
        m_cartes.push_back(new Foudre());
        m_nbFoudre++;
    }
    if(type == "Seisme")
    {
        m_cartes.push_back(new Seisme());
        m_nbSeisme ++;
    }
    if(type == "Tornade")
    {
        m_cartes.push_back(new Tornade());
        m_nbTornade++;
    }
    if(type == "Poison")
    {
        m_cartes.push_back(new Poison());
        m_nbPoison++;
    }
    if(type == "Rage")
    {
        m_cartes.push_back(new Rage());
        m_nbRage++;
    }
    if(type == "Soin")
    {
        m_cartes.push_back(new Soin());
        m_nbSoin++;
    }
    if(type == "Boule de neige")
    {
        m_cartes.push_back(new BouleDeNeige());
        m_nbBDN++;
    }
    if(type == "Clonage")
    {
        m_cartes.push_back(new Clonage());
        m_nbClonage++;
    }
    if(type == "Bouclier")
    {
        m_cartes.push_back(new Bouclier());
        m_nbBouclier++;
    }

}


void Collection::retirerCarte(std::string type)
{
    int nbCartesASup=1;
    do
    {
        for(unsigned int i=0; i<m_cartes.size(); i++)
        {
            if(type == m_cartes[i]->getNom())
            {
                m_cartes.erase(m_cartes.begin() + i);
                nbCartesASup--;
            }
        }

    }while(nbCartesASup != 0);
}


void Collection::enregistrer(const std::string& path)
{
    std::string geant = "geant", sorcier = "electrosorcier", dragon = "dragon", pekka = "pekka", ballon = "ballon", bdf = "bouledefeu", foudre = "foudre", seisme = "seisme", tornade = "tornade", poison = "poison", rage = "rage", soin = "soin", bdn = "bouledeneige", clonage = "clonage", bouclier = "bouclier";

    // Ouverture fichier en mode "w"
    // pour le mode append, utiliser std::ios::app
    std::ofstream ofs(path.c_str(), std::ios::app);
    if (ofs)
    {
        // Ecriture dans le fichier
        for(unsigned int i=0; i<m_nbGeants; ++i)
        {
            ofs << geant << std::endl;
        }
        for(unsigned int i=0; i<m_nbSorciers; ++i)
        {
            ofs << sorcier << std::endl;
        }
        for(unsigned int i=0; i<m_nbDragons; ++i)
        {
            ofs << dragon << std::endl;
        }
        for(unsigned int i=0; i<m_nbPekkas; ++i)
        {
            ofs << pekka << std::endl;
        }
        for(unsigned int i=0; i<m_nbBallons; ++i)
        {
            ofs << ballon << std::endl;
        }
        for(unsigned int i=0; i<m_nbBDF; ++i)
        {
            ofs << bdf << std::endl;
        }
        for(unsigned int i=0; i<m_nbFoudre; ++i)
        {
            ofs << foudre << std::endl;
        }
        for(unsigned int i=0; i<m_nbSeisme; ++i)
        {
            ofs << seisme << std::endl;
        }
        for(unsigned int i=0; i<m_nbTornade; ++i)
        {
            ofs << tornade << std::endl;
        }
        for(unsigned int i=0; i<m_nbPoison; ++i)
        {
            ofs << poison << std::endl;
        }
        for(unsigned int i=0; i<m_nbRage; ++i)
        {
            ofs << rage << std::endl;
        }
        for(unsigned int i=0; i<m_nbSoin; ++i)
        {
            ofs << soin << std::endl;
        }
        for(unsigned int i=0; i<m_nbBDN; ++i)
        {
            ofs << bdn << std::endl;
        }
        for(unsigned int i=0; i<m_nbClonage; ++i)
        {
            ofs << clonage << std::endl;
        }
        for(unsigned int i=0; i<m_nbBouclier; ++i)
        {
            ofs << bouclier << std::endl;
        }

        ofs.close(); // fermeture du flux
    }

}


void Collection::charger(const std::string& path)
{
    std::ifstream fichier;
    fichier.open(path);
    //std::ifstream fichier(path, std::ios::in | std::ios::out | std::ios::trunc);
    std::string ligne;
    unsigned int nbGeants = 0, nbSorciers = 0, nbDragons = 0, nbPekkas = 0, nbBallons = 0, nbBDF = 0, nbFoudre = 0, nbSeisme = 0, nbTornade = 0, nbPoison = 0, nbRage = 0, nbSoin = 0, nbBDN = 0, nbClonage = 0, nbBouclier = 0;

    /*  std::istringstream iss{nomJoueur};
      iss >> nomJoueur;
      fichier.seekg(nomJoueur.size()+1, std::ios::beg);*/

    while(std::getline(fichier, ligne))
    {

        std::istringstream iss{ligne};
        std::string carte;

        iss >> carte;


        if(carte.compare("geant") == 0)
        {
            nbGeants++;
        }
        else if(carte.compare("electrosorcier") == 0)
        {
            nbSorciers++;
        }
        else if(carte.compare("dragon") == 0)
        {
            nbDragons++;
        }
        else if(carte.compare("pekka") == 0)
        {
            nbPekkas++;
        }
        else if(carte.compare("ballon") == 0)
        {
            nbBallons++;
        }
        else if(carte.compare("bouledefeu") == 0)
        {
            nbBDF++;
        }
        else if(carte.compare("foudre") == 0)
        {
            nbFoudre++;
        }
        else if(carte.compare("seisme") == 0)
        {
            nbSeisme++;
        }
        else if(carte.compare("tornade") == 0)
        {
            nbTornade++;
        }
        else if(carte.compare("poison") == 0)
        {
            nbPoison++;
        }
        else if(carte.compare("rage") == 0)
        {
            nbRage++;
        }
        else if(carte.compare("soin") == 0)
        {
            nbSoin++;
        }
        else if(carte.compare("bouledeneige") == 0)
        {
            nbBDN++;
        }
        else if(carte.compare("clonage") == 0)
        {
            nbClonage++;
        }
        else if(carte.compare("bouclier") == 0)
        {
            nbBouclier++;
        }


    }
    fichier.close();

    for(unsigned int i=0; i<nbGeants ; ++i)
    {
        this->ajouterCarte("geant");
    }
    for(unsigned int i=0; i<nbSorciers ; ++i)
    {
        this->ajouterCarte("electrosorcier");
    }
    for(unsigned int i=0; i<nbDragons ; ++i)
    {
        this->ajouterCarte("dragon");
    }
    for(unsigned int i=0; i<nbPekkas ; ++i)
    {
        this->ajouterCarte("pekka");
    }
    for(unsigned int i=0; i<nbBallons ; ++i)
    {
        this->ajouterCarte("ballon");
    }
    for(unsigned int i=0; i<nbBDF ; ++i)
    {
        this->ajouterCarte("Boule de feu");
    }
    for(unsigned int i=0; i<nbFoudre ; ++i)
    {
        this->ajouterCarte("Foudre");
    }
    for(unsigned int i=0; i<nbSeisme ; ++i)
    {
        this->ajouterCarte("Seisme");
    }
    for(unsigned int i=0; i<nbTornade ; ++i)
    {
        this->ajouterCarte("Tornade");
    }
    for(unsigned int i=0; i<nbPoison ; ++i)
    {
        this->ajouterCarte("Poison");
    }
    for(unsigned int i=0; i<nbRage ; ++i)
    {
        this->ajouterCarte("Rage");
    }
    for(unsigned int i=0; i<nbSoin ; ++i)
    {
        this->ajouterCarte("Soin");
    }
    for(unsigned int i=0; i<nbBDN ; ++i)
    {
        this->ajouterCarte("Boule de neige");
    }
    for(unsigned int i=0; i<nbClonage ; ++i)
    {
        this->ajouterCarte("Clonage");
    }
    for(unsigned int i=0; i<nbBouclier ; ++i)
    {
        this->ajouterCarte("Bouclier");
    }

}



void Collection::afficher()const
{

    for(const auto& elem : m_cartes)
    {
        elem->afficher();
    }
    std::cout << std::endl;

}
