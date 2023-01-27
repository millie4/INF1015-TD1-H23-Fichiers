#include <iostream>
#include <cmath>
#include <random>
#define HUGE_VAL __builtin_huge_val();
using namespace std;

// int genererNombresAleatoires(int borneInf, int borneSup) {
//     default_random_engine aleatoire(random_device{}());
//     uniform_int_distribution<int> myUnifRealDist(borneInf, borneSup);
//     int monNombre = myUnifRealDist(aleatoire);
//     return monNombre;
// }

int main () {

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

    return 0;
}
