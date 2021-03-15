/*************************************************/
// Nom du projet: Jeu du nombre � deviner
// Nom du fichier: MainJeuNombreAdeviner.cpp
// Version : 1.0
// Nom du programmeur: MP Pinaud / Maxime Courtois
// Date de cr�ation : 05/02/2021
// R�le du fichier: Contient le code jeu
// Nom des composants utilises: CPartie
//                              CJoueur
//                              iostream
// Historique du fichier: Moyenne
/*************************************************/
#include <iostream>
using namespace std;

#include "../include/Partie.h"

int main()
{

    //Cr�ation d'un joueur
    cout << "Vous allez jouer pour deviner un nombre secret" << endl;
    cout << "----------------------------------------------"<< endl;
    cout << "Veuillez entrer le nom du 1er joueur" << endl;
    string un_nom;
    cin >> un_nom;
    cout << "Veuillez entrer le prenom du 1er joueur" << endl;
    string un_prenom;
    cin >> un_prenom;
    cout << "Veuillez entrer le nom du 2eme joueur" << endl;
    string un_nom2;
    cin >> un_nom2;
    cout << "Veuillez entrer le prenom du 2eme joueur" << endl;
    string un_prenom2;
    cin >> un_prenom2;

    // Cr�ation du joueur
    /*
    CJoueur *joueur;
    joueur = new CJoueur(un_nom,un_prenom);
    CJoueur *joueur2;
    joueur2 = new CJoueur(un_nom2,un_prenom2);
    */
    CJoueur joueur(un_nom,un_prenom);
    CJoueur joueur2(un_nom2,un_prenom2);


    cout << "----------------------------------------------"<< endl;
    cout << "Combien de parties voulez-vous jouer ?" << endl;
    int nbParties;
    cin >> nbParties;


    for (int i = 0; i <nbParties; i++)
    {
        cout << "----------------------------------------------"<< endl;
        cout <<"Partie Numero : " << i+1 << endl;
        cout << "----------------------------------------------"<< endl;

        CPartie partie (0,10,4); // nombre � deviner entre 0 et 10, nombre de tentatives maximum 4

        partie.Jouer(joueur); // ex�cution d'une partie pour le joueur
        partie.Jouer(joueur2); // ex�cution d'une partie pour le joueur2

    }


    cout << "----------------------------------------------"<< endl;
    cout << "Affichage des resultats du joueur "<< joueur.Nom() << " " << joueur.Prenom()<< endl;
    cout << "----------------------------------------------"<< endl;

    // R�cup�ration des r�sultats du joueur
    int nbsucces, nbechecs, nbessais;
    joueur.Resultats(nbsucces, nbechecs, nbessais);  // les param�tres sont pass�s par r�f�rence

    // Affichage des r�sultats
    cout << "Nombre de parties gagnees : " << nbsucces << endl;
    cout << "Nombre de parties perdues : " << nbechecs << endl;
    cout << "Nombre de tentatives totales : " << nbessais << endl;

    cout << "----------------------------------------------"<< endl;


    cout << "----------------------------------------------"<< endl;
   cout << "Affichage des resultats du joueur "<< joueur2.Nom() << " " << joueur2.Prenom()<< endl;
   cout << "----------------------------------------------"<< endl;

    // R�cup�ration des r�sultats du joueur
    int nbsucces2, nbechecs2, nbessais2;
    joueur2.Resultats(nbsucces2, nbechecs2, nbessais2);  // les param�tres sont pass�s par r�f�rence

    // Affichage des r�sultats
    cout << "Nombre de parties gagnees : " << nbsucces2 << endl;
    cout << "Nombre de parties perdues : " << nbechecs2 << endl;
    cout << "Nombre de tentatives totales : " << nbessais2 << endl;

    cout << "----------------------------------------------"<< endl;

    if(nbsucces2 > nbsucces)
    {
        cout <<"Le gagnant est " << joueur2.Nom() << endl;
    }
    else if(nbsucces2 < nbsucces)
        {
             cout <<"Le gagnant est " << joueur.Nom() << endl;
        }
        else
        {
            cout <<"Le joueur " << joueur.Nom() << " et le joueur " << joueur2.Nom()<< " sont ex aequo "<<endl;
        }
    float moyenne;float moyenne2;
    moyenne = joueur.Moyenne();
    moyenne2 = joueur2.Moyenne();
    cout <<"La moyenne du joueur " << joueur.Nom() << " est " << moyenne << endl;
    cout <<"La moyenne du joueur " << joueur2.Nom() << " est " << moyenne2 << endl;
    cout << "----------------------------------------------"<< endl;
    cout << "----------------------------------------------"<< endl;

    cout << "Adresse Joueur1 : " << &joueur << endl;
    cout << "Adresse Joueur2 : " << &joueur2 << endl;
    delete &joueur,&joueur2;
    return 0;
}

