#include <iostream>
#include <cmath>
#include <random>
#define HUGE_VAL __builtin_huge_val();
using namespace std;


int main () {

    int tailleTableau = 10;
    // initialisation de 4 tableaux de taille 10 : un pour les nombres générés aléatoirement, un qui 
    // stockera les nombres paires, un autre pour les nombres impaires et le dernier étant le tableau
    // final. 
    int tableau[tailleTableau], paires[tailleTableau], impaires[tailleTableau],nouveauTableau[tailleTableau];
    int compteurPaires=0, compteurImpaires=0;    

    default_random_engine aleatoire(random_device{}());
    std::uniform_int_distribution<int> myUnifRealDist(0, 100);

    // Création d'un tableau d'entiers aléatoires de taille 10 
    for (int i = 0; i < tailleTableau; i++) {
        int nombre = myUnifRealDist(aleatoire);
        tableau[i] = nombre;
    }

    // affichage du tableau
    for (int valeur : tableau) {
        cout << valeur << ' ';
    }

    // Pour itérer sur chaque élément du tableau
    for(int i=0;i<10;i++) {
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
