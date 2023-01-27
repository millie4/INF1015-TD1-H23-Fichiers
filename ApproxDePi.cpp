#include <iostream>
#include <cmath>
#include <random>
using namespace std;

int main() {
    // Initialisation d'un générateur aleatoire.
    double borneInf = -1.0;
    double borneSup = 1.0; 
    default_random_engine aleatoire(random_device{}());
    uniform_real_distribution<double> myUnifRealDist(borneInf, borneSup);

    double nIterations;
    cout << "Entrez le nombre d'iterations souhaite: ";
    cin >> nIterations;

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
    printf("L'approximation de pi est %.6lf", approxPi);
    return 0;
}