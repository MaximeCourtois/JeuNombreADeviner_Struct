/*************************************************/
// Nom du projet: Jeu du nombre à deviner
// Nom du fichier: MainJeuNombreAdeviner.cpp
// Version : 1.0
// Nom du programmeur: MP Pinaud
// Date de création : 25/01/2021
// Rôle du fichier: Contient le code jeu
// Nom des composants utilises: JeuNombreADeviner.h
//                              iostream
// Historique du fichier:
/*************************************************/
#include <iostream>
#include <cstdlib>
#include <random>
using namespace std;

#include "../include/JeuNombreADeviner.h"

int main()
{
    int i = 0;
    int j = 0;
    int k = 0;
    int nbJoueur;
    cout << "Combien de joueurs :";
    cin >> nbJoueur ;
    TJoueur NomJoueur[nbJoueur];
    string nom;
    int NombreParti = 0;
    cout << "Vous allez jouer pour deviner un nombre secret" << endl;
    cout << "-------------------------------------------------" << endl;
    cout << "Entrer le nombre de parti que vous voulez realiser : ";

    cin >> NombreParti;
    for (i=0;i<nbJoueur;i++)
    {
        cout << "Entrer le nom de joueur : ";
        cin >> nom;
        InitJoueur(NomJoueur[i],nom);
    }
    for (k=0;k<NombreParti;k++)
    {
        i=0;
        for (j=0;j<nbJoueur;j++)
        {
            cout << "C'est au joueur : " << Nom(NomJoueur[i]) << endl;

            JouerPartie(NomJoueur[j],TirerNombreMystere());
            i++;

        }
    }
    i=0;
    for (i=0;i<nbJoueur;i++)
    {
        cout << "Pour le joueur : " << Nom(NomJoueur[i]) << endl;
        AfficherJoueur(NomJoueur[i]);
    }
    i=0;
    int maxwin;
    int maxtenta;
    int a =0;
    int b =0;
    maxwin = NomJoueur[i].nbPartiesGagnees;
    maxtenta = NomJoueur[i].nbTentatives;
    do
    {
        if(maxwin < NomJoueur[i].nbPartiesGagnees)
        {
            maxwin = NomJoueur[i].nbPartiesGagnees;
            maxtenta = NomJoueur[i].nbTentatives;
            a = i;
        }
        if(maxwin == NomJoueur[i].nbPartiesGagnees && maxtenta > NomJoueur[i].nbTentatives)
        {
            maxtenta = NomJoueur[i].nbTentatives;
            a = i;
        }
        if (maxwin == NomJoueur[i].nbPartiesGagnees && maxtenta == NomJoueur[i].nbTentatives)
        {
            if (a != i)
            {
                b = i;
            }
        }
        if (NomJoueur[a].nbTentatives < NomJoueur[i].nbTentatives)
        {
            b=a;
        }
        else if (NomJoueur[a].nbTentatives > NomJoueur[i].nbTentatives)
        {
            a=b;
        }
        i++;
    }
    while (i<nbJoueur);

    //cout << "Gagnant : " << Nom(NomJoueur[a])<< " "<< Nom(NomJoueur[b])<<endl;

}
