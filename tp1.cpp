#include <iostream>
#include <string>
#include <fstream>
#include <random>
using namespace std;
#define HUGE_VAL __builtin_huge_val();
#include <cmath>

// premier exercice 
string determinerNombrePremier(int nombre) {
    bool estPrime = true;
    // O et 1 ne sont pas des nombres premiers 
    if (nombre == 0 || nombre == 1) {
     estPrime = false;
    }
    // Boucle pour verifier si le nombre est premier
    // on commence à 2 
    for (int i = 2; i <= nombre/2; i++) {
        if (nombre % i == 0) {
            estPrime = false;
            break;
        }
    }
    if (estPrime) {
        cout << nombre << " est un nombre premier" << endl;
    }
    else {
        if (nombre % 2 == 0) {
            printf("Ce nombre n'est pas premier car il est divisible par 2 \n" );
        }
        else {
            for (int n = 3; n <= sqrt(nombre); n += 2 ) {
                if (nombre % n == 0 ) {
                    printf("Ce nombre n'est pas premier car il est divisible par %d \n", n);
                    break;
                }
            }
        }
    }

}

// fonction générale de validation
bool validerBornes(double nombre, double borneInf, double borneSup) {
        bool estValide = true;
        if (nombre > borneSup || nombre < borneInf) {
            estValide = false;
        }
        return estValide;
    }


// Deuxieme exercice 
string calculerEmprunt() {
    while (true) {

        double sommeArgent;
        double montantMensuel;
        double tauxInteretAnnuel;

        cout << "Entrez la somme d'argent pretee : ";
        cin >> sommeArgent;
        cout << "Entrez le montant rembourse mensuellement : "; 
        cin >> montantMensuel;
        cout << "Entrez le taux d'interet annuel : ";
        cin >> tauxInteretAnnuel;

        // calcul du taux d'interets mensuel
        int nombreMoisParAnnee = 12;
        double tauxInteretMensuel = (tauxInteretAnnuel / 100) / nombreMoisParAnnee;

        // verification des bornes des donnees
        if (validerBornes(tauxInteretAnnuel, 0.0, 100.0) & validerBornes(sommeArgent, 0.0, HUGE_VAL)) {

            // Calcul du montant total à rembourser, interets inclus 
            double dette = sommeArgent * (1.0 + tauxInteretAnnuel/100.0);
            // Calcul du nombre de mois necessaires pour le remboursement
            double nombreDeMois = dette / montantMensuel;
            // Calcul des interets totaux percus par le pretteur
            double interetsTotaux = sommeArgent * (1 + tauxInteretAnnuel/100);

            cout << "Cela prendra " << nombreDeMois << " mois pour rembourser la dette."<< endl;
            cout << "La somme d'interet percue par le pretteur est : "<< interetsTotaux << "$" << endl;
            break;
        }
        // si les données ne sont pas valides, refaire la boucle
        else {
            cout << "Les donnees ne sont pas valides. Veulliez reessayer." << endl;
        }
    }
}

// Exercice 3
string calculerHauteurBalle() {

    bool validationVariables = false;
    double nbRebonds, hauteur, coeffRebond;
    while(!validationVariables) {
        cout << "Entrez le nombre de rebonds : ";
        cin >> nbRebonds;
        cout << "Entrez la hauteur initiale : ";
        cin >> hauteur;
        cout << "Entrez le coefficient : ";
        cin >> coeffRebond;
        
        // Vérifier si la saisie de l'utilisateur est valide 
        if (validerBornes(nbRebonds, 0.0, HUGE_VAL) & validerBornes(hauteur, 0.0, HUGE_VAL) & validerBornes(coeffRebond, 0.0, 1.0)) {
            validationVariables = true;
        }
        else {
            cout << "Les donnees ne sont pas valides. Veulliez reessayer." << endl;
        }
    }
    
    double g = 9.81; // constante d'acceleration gravitationnelle
    double vitesse = sqrt(2.0 * g * hauteur);

    for (int i = 2; i < nbRebonds; i++) {
        hauteur = ( vitesse * vitesse + 1 ) / ( 2.0 * g );
        vitesse *= coeffRebond;
    }

    cout << "La hauteur atteinte pas la balle est : "<<hauteur << endl;
}

// Exercice 4
string approximerPi(int nIterations) {
    // Initialisation d'un générateur aleatoire.
    double borneInf = -1.0;
    double borneSup = 1.0; 
    default_random_engine aleatoire(random_device{}());
    uniform_real_distribution<double> myUnifRealDist(borneInf, borneSup);
    double pointsDansCercle = 0;

    for(int i = 0; i < nIterations; i++) {
        // Generation de deux valeurs aleatoires entre -1 et 1
        double x = myUnifRealDist(aleatoire);
        double y = myUnifRealDist(aleatoire);
        
        // compte des points qui se trouvent à l'intérieur du cercle
        if ((x*x + y*y)<1.0) {
            pointsDansCercle++;
        }
    }
    double aireCarre = 4.0;
    double approxPi = aireCarre * pointsDansCercle * nIterations;
    printf("L'approximation de pi est %.6lf \n", approxPi);
}

// Exercice 5
string organiserTableau() {
    int tailleTableau = 10;
    // initialisation de 4 tableaux de taille 10
    int tableau[tailleTableau], paires[tailleTableau], impaires[tailleTableau],nouveauTableau[tailleTableau]; 

    // initialisation d'un générateur d'entiers aléatoires entre 0 et 100
    int borneInf = 0;
    int borneSup = 100;
    default_random_engine aleatoire(random_device{}());
    uniform_int_distribution<int> myUnifRealDist(borneInf, borneSup);

    for (int i = 0; i < tailleTableau; i++) {
        // creation d'un entier aléatoir 
        int nombre = myUnifRealDist(aleatoire);
        // ajout dans le tableau
        tableau[i] = nombre;
    }

    // affichage du tableau
    for (int valeur : tableau) {
        cout << valeur << ' ';
    }

    int compteurPaires=0, compteurImpaires=0;   
    // Pour itérer sur chaque élément du tableau
    for(int i=0 ; i<tailleTableau ; i++) {
        if(tableau[i] % 2 == 0) {
            paires[compteurPaires++] = tableau[i]; // mettre les nombres paires dans le tableau paires
        }
        else {
            impaires[compteurImpaires++] = tableau[i]; // mettre les nombres impaires dans le tableau impaires
        }
    }
    
    // D'abord mettre les nombres paires dans le tableau final
    for(int i=0 ; i<compteurPaires ; i++) {
        nouveauTableau[i] = paires[i];
    }

    // Ensuite les nombres impaires 
    for (int i=0 ; i<compteurImpaires ; i++) {
        nouveauTableau[compteurPaires++] = impaires[i];
    }

    // Affichage du tableau final
    cout << ' ' << endl;
    for (int valeur : nouveauTableau) {
        cout << valeur << ' ';
    }

}

// Exercice 6
struct Dictionnaire{
      string mots[4]; // Pour coontenir tous les mots du dictionnaire
      string type[4]; // Pour contenir tous les types du dictionnaire 
      string definition[4]; // Pour contenir toutes les définitions du dictionniare
};

string afficherPlusLongMot() {
    Dictionnaire monDict; // creation d'un objet de type Dictionnaire

    int nMots = 4;
    int nColonnes = 3;
    ifstream fichier("dictionnaire.txt");

    if(fichier.is_open()) {

        string elementDictionnaire;
        int compteur = 0;
        // boucle pour iterer sur tout les elements du fichiers Dictionnaire.txt
        for (compteur; compteur< nMots*nColonnes; compteur++) { 
            // mettre les mots dans le tableau des mots
            if (compteur % nColonnes == 0) {
                getline(fichier, elementDictionnaire, '\t');
                monDict.mots[compteur/3] = elementDictionnaire;
            }
            // les types dans le tableau des types 
            else if (compteur % nColonnes == 1) {
                getline(fichier, elementDictionnaire, '\t');
                monDict.type[compteur/3] = elementDictionnaire;
            }
            // les définitions dans le tableau des définitions 
            else if (compteur % nColonnes == 2) {
                getline(fichier, elementDictionnaire, '\t');
                monDict.definition[compteur/3] = elementDictionnaire;
            }
        }

        int indexPlusLongMot = 0;
        // variable de la plus grande taille d'un mot
        int tailleMax = 0;
        // boucle qui itère sur tous les mots du dictionnaires (monDict.mots[])
        for (int indexMot = 0; indexMot < nMots; indexMot++) {
            // Calcule la taille et l'index du plus grand mot 
            if ( tailleMax < monDict.mots[indexMot].size() ) { 
                tailleMax = monDict.mots[indexMot].size();
                indexPlusLongMot = indexMot;
            }
        }    
        
        cout << monDict.mots[indexPlusLongMot] << ' '<< '(' << monDict.type[indexPlusLongMot] << ')' << ' ';
        cout << ':' << ' ' << monDict.definition[indexPlusLongMot]<< endl;       

    }
}

int main() {
    // premier exercice
    int nombre;
    cout << "Entrez un nombre entier : ";
    cin >> nombre;
    determinerNombrePremier(nombre);

    // deuxieme exercice 
    calculerEmprunt();

    // troisieme exercice
    calculerHauteurBalle();

    // quatrieme exercice 
    int nIterations;
    cout << "Entrez le nombre d'iterations souhaite: ";
    cin >> nIterations;
    approximerPi(nIterations);

    // cinquieme exercice
    organiserTableau();

    // sixieme exercice 
    afficherPlusLongMot();


    return 0;
}