/*************************************************/
// Nom du projet: Jeu du nombre à deviner
// Nom du fichier: Partie.h
// Version : 1.0
// Nom du programmeur: MP Pinaud / Maxime Courtois
// Date de création : 05/02/2021
// Rôle du fichier: Contient la déclaration de attributs et méthodes de la classe qui représente une partie
// Nom des composants utilises: string, la classe CJoueur
// Historique du fichier:
/*************************************************/
#include <string>
using namespace std;

#include "../include/Joueur.h"
class CPartie {

    public :

    // Nom :CPartie (constructeur)
    // Rôle : initialise la partie avec le nombre d'essais max, les nombres minimal et maximal à trouver
    // Paramètres d'entrée:
    //              le nombre d'essais max,
    //              le nombre minimal,
    //              le nombre maximal
    // Sortie : la partie qui est créée

     CPartie ( int nbmin = 0, int nbmax = 10, int nbessaismax = 4);



    // Nom :Jouer
    // Rôle : Tire un nombre aléatoire et démarre la partie
    //        A la fin, met à jour les informations du joueur
    // Parametre d'entrée/sortie : le joueur
    // Entrée : la partie qui va se jouer

    void Jouer (CJoueur &joueur);



    private :

        //Nom :TirerNombreMystere
        // Rôle : Tire aléatoirement un nombre à deviner entre nbMin et nbMax
        // Valeur de retour : nombre à deviner
        // Entrée : la partie pour laquelle est tiré le nombre mystère

        int TirerNombreMystere();



        int nbEssaisMax; // nombre d'essais max

        int nbMin; // nombre minimal à trouver
        int nbMax; // nombre maximal à trouver


};

















