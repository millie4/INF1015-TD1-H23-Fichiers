#include <iostream>
#include <cmath>
#include <random>
using namespace std;


int main () {

    int tailleTableau = 10;
    int tableau[tailleTableau] = {};

    default_random_engine aleatoire(random_device{}());
    std::uniform_int_distribution<int> myUnifRealDist(0, 10);

    for (int i = 0; i < tailleTableau; i++) {

        int nombre = myUnifRealDist(aleatoire);
        tableau[i] = nombre;
        
    }

    for (int valeur : tableau) {
        cout << valeur << ' ';
    }

    return 0;



}
