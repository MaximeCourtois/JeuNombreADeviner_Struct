/*************************************************/
// Nom du projet: Jeu du nombre à deviner
// Nom du fichier: Joueur.h
// Version : 1.0
// Nom du programmeur: MP Pinaud / Maxime Courtois
// Date de création : 05/02/2021
// Rôle du fichier: Contient la déclaration des attributs et méthodes de la classe qui représente un joueur
// Nom des composants utilises: string
// Historique du fichier:
/*************************************************/
#include <string>
using namespace std;



class CJoueur {

    public:

    // Nom :CJoueur  Constructeur
    // Rôle : Initialise toutes les informations du joueur.
    //        Le nombre de tentatives, de parties gagnées et de parties jouées seront à 0.
    // Paramètre d'entrée :
    //                  un_nom le nom du joueur
    //                  un_prenom : le prenom du joueur
    // Sortie : le joueur créé

    CJoueur(string un_nom,string un_prenom);

    // Nom :CJoueur Destructeur
    // Rôle : Delete toutes les informations du joueur.
    //        Le nombre de tentatives, de parties gagnées et de parties jouées seront à 0.
    // Sortie : le joueur supprimer

    ~CJoueur();

    // Nom : MajResultats
    // Rôle : met à jour les informations d'un joueur
    // Paramètres d'entrée:
    //                  - le nombre d'essais
    //                  - gagne qui vaut true si le joueur a gagné, false sinon
    // Entrée/sortie :
    //                  le joueur dont on met à jour les résultats

    void MajResultats(int nbEssais, bool gagne);

    // Nom : Resultats
    // Rôle : indique les résultats d'un joueur
    //        le nombre de parties gagnées, le nombre de parties perdues, le nombre d'essais total
    //        La fonction N'affiche PAS les informations à l'écran
    // Paramètres de sortie:
    //                      - le nombre de succès,
    //                      - le nombre d'échecs
    //                      - le nombre total d'essais
    // Entrée :
    //            -le joueur dont on veut les résultats

    void Resultats(int &nbsucces, int &nbechec, int & nbessais);


    // Nom :Nom
    // Rôle : retourne le nom d'un joueur
    // Entrée: le joueur dont on veut le nom
    // Valeur de retour : nom du joueur
    // Entrée : le joueur dont on veut le nom

    string Nom();

        // Nom :Prenom
    // Rôle : retourne le prenom du joueur
    // Paramètres d'entrée: le joueur dont on veut le prenom
    // Valeur de retour : prenom du joueur
    // Entrée : le joueur dont on veut le prenom

    string Prenom();

    // Nom : Moyenne
    // Rôle : return le moyenne du nombre d'essis d'un joueur
    // Paramètres d'entrée: le joueur dont on veut la moyenne
    // Valeur de retour : moyenne du nombre d'essais du joueur
    // Entrée : le joueur dont on veut la moyenne

    float Moyenne();


    private :

        string nom;  // nom du joueur
        string prenom;  // prenom du joueur
        int nbPartiesJouees;
        int nbPartiesGagnees;
        int nbTentatives;
};






