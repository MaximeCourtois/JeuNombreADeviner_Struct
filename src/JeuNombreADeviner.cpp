/*************************************************/
// Nom du projet: Jeu du nombre � deviner
// Nom du fichier: JeuNombreADeviner.cpp
// Version : 1.0
// Nom du programmeur: MP Pinaud
// Date de cr�ation : 25/01/2021
// R�le du fichier: Contient le code des fonctions du jeu
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
// R�le : Cr�e un joueur. Initialise toutes les informations du joueur.
//        Le nombre de tentatives, de parties gagn�es et de parties jou�es seront � 0.
// Param�tres d'entr�e : un_nom
// Param�tres de sortie : joueurAcreer


void InitJoueur(TJoueur& joueurAcreer, string un_nom)
{
   joueurAcreer.nom = un_nom;
   joueurAcreer.nbPartiesJouees = 0;
   joueurAcreer.nbPartiesGagnees = 0;
   joueurAcreer.nbTentatives = 0;
}



// Nom :TirerNombreMystere
// R�le : Tire al�atoirement un nombre � deviner entre 0 et 10
// Valeur de retour : nombre � deviner

int TirerNombreMystere()
{
    int nombreADeviner;
    srand(time(NULL));
    nombreADeviner = rand() % 10 + 1;
    return nombreADeviner;
}


// Nom :JouerPartie
// R�le : Fait jouer une partie au joueur pass� en param�tre
//        A la fin, met � jour les informations du joueur
// Param�tres d'entr�e:
// Param�tres de sortie:
// Param�tres d'entr�e/sortie :

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
// R�le : met � jour les informations du joueur pass� en param�tre
// Param�tres d'entr�e:
// Param�tres de sortie:
// Param�tres d'entr�e/sortie :

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
// R�le : indique les r�sultats du joueur pass� en param�tre
//        le nombre de parties gagn�es, le nombre de parties perdues, le nombre d'essais total
//        La fonction N'affiche PAS les informations � l'�cran
// Param�tres d'entr�e:
// Param�tres de sortie:
// Param�tres d'entr�e/sortie :

void ResultatsJoueur(TJoueur joueur, int & nbsucces, int & nbechec, int & nbessais)
{
joueur.nbPartiesGagnees = joueur.nbPartiesGagnees + nbsucces;
joueur.nbPartiesJouees = joueur.nbPartiesJouees + nbsucces + nbechec;
joueur.nbTentatives = joueur.nbTentatives + nbessais;
}

// Nom :Nom
// R�le : retourne le nom du joueur
// Param�tres d'entr�e: le joueur dont on veut le nom
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
