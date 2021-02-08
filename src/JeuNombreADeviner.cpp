/*************************************************/
// Nom du projet: Jeu du nombre à deviner
// Nom du fichier: JeuNombreADeviner.cpp
// Version : 1.0
// Nom du programmeur: MP Pinaud
// Date de création : 25/01/2021
// Rôle du fichier: Contient le code des fonctions du jeu
// Nom des composants utilises: JeuNombreADeviner.h
//                              iostream
//                              ctime
// Historique du fichier:
/*************************************************/

#include <iostream>
#include <cstdlib>
#include <random>
#include <time.h>
using namespace std;
#include "../include/JeuNombreAdeviner.h"


// Nom :InitJoueur
// Rôle : Crée un joueur. Initialise toutes les informations du joueur.
//        Le nombre de tentatives, de parties gagnées et de parties jouées seront à 0.
// Paramètres d'entrée : un_nom
// Paramètres de sortie : joueurAcreer


void InitJoueur(TJoueur& joueurAcreer, string un_nom)
{
   joueurAcreer.nom = un_nom;
   joueurAcreer.nbPartiesJouees = 0;
   joueurAcreer.nbPartiesGagnees = 0;
   joueurAcreer.nbTentatives = 0;
}



// Nom :TirerNombreMystere
// Rôle : Tire aléatoirement un nombre à deviner entre 0 et 10
// Valeur de retour : nombre à deviner

int TirerNombreMystere()
{
    int nombreADeviner;
    srand(time(NULL));
    nombreADeviner = rand() % 10 + 1;
    return nombreADeviner;
}


// Nom :JouerPartie
// Rôle : Fait jouer une partie au joueur passé en paramètre
//        A la fin, met à jour les informations du joueur
// Paramètres d'entrée:
// Paramètres de sortie:
// Paramètres d'entrée/sortie :

void JouerPartie(TJoueur& un_joueur, int nombreADeviner)
{
    int NbEssai = 0;
    int NbInput = 0;
    while (NbEssai <4)
    {
        cout <<"entrer un nombre : ";
        cin >> NbInput;
        if (NbInput > nombreADeviner)
        {
            NbEssai = NbEssai + 1;
            cout <<"Le Nombre est plus petit que "<< NbInput << endl;
        }
        else if (NbInput < nombreADeviner)
            {
                NbEssai = NbEssai + 1;
                cout <<"Le Nombre est plus grand que "<< NbInput << endl;
            }
            else
            {
            NbEssai = NbEssai + 10;
            cout << "----------------------------" <<endl;
            cout <<"Bravo tu a trouver le nombre en "<< NbEssai - 9 << " essais" <<endl;
            cout << "----------------------------" <<endl;
            }

    }
    if (NbInput == nombreADeviner)
    {
        NbEssai = NbEssai - 9;
        un_joueur.nbPartiesGagnees = un_joueur.nbPartiesGagnees +1;
    }
    if (NbEssai == 4 && NbInput != nombreADeviner)
    {
        cout << "----------------------------" <<endl;
        cout <<"C'est perdu "<<endl;
        cout << "----------------------------" <<endl;
    }
    un_joueur.nbPartiesJouees = un_joueur.nbPartiesJouees + 1;
    un_joueur.nbTentatives = un_joueur.nbTentatives + NbEssai;
}


// Nom : MajResultatsJoueur
// Rôle : met à jour les informations du joueur passé en paramètre
// Paramètres d'entrée:
// Paramètres de sortie:
// Paramètres d'entrée/sortie :

void MajResultatsJoueur(TJoueur joueur, int nbEssais, bool gagne)
{
    if (gagne==true)
    {
        joueur.nbPartiesGagnees++;
    }
    joueur.nbPartiesJouees++;
    joueur.nbTentatives = joueur.nbTentatives + nbEssais;
}

// Nom : ResultatsJoueur
// Rôle : indique les résultats du joueur passé en paramètre
//        le nombre de parties gagnées, le nombre de parties perdues, le nombre d'essais total
//        La fonction N'affiche PAS les informations à l'écran
// Paramètres d'entrée:
// Paramètres de sortie:
// Paramètres d'entrée/sortie :

void ResultatsJoueur(TJoueur joueur, int & nbsucces, int & nbechec, int & nbessais)
{
joueur.nbPartiesGagnees = joueur.nbPartiesGagnees + nbsucces;
joueur.nbPartiesJouees = joueur.nbPartiesJouees + nbsucces + nbechec;
joueur.nbTentatives = joueur.nbTentatives + nbessais;
}

// Nom :Nom
// Rôle : retourne le nom du joueur
// Paramètres d'entrée: le joueur dont on veut le nom
// Valeur de retour : nom du joueur

string Nom(TJoueur joueur){

    return joueur.nom;
}





void AfficherJoueur(TJoueur joueur)
{
    cout << "nbPartiesJouees : " << joueur.nbPartiesJouees <<endl;
    cout << "nbPartiesGagnees : " << joueur.nbPartiesGagnees <<endl;
    cout << "nbTentatives : " << joueur.nbTentatives <<endl;
}
