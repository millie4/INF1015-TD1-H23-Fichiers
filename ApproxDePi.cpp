#include <iostream>
#include <cmath>
#include <random>
using namespace std;

int main() {
    // Initialisation d'un générateur aleatoire.
    default_random_engine aleatoire(random_device{}());
    std::uniform_real_distribution<double> myUnifRealDist(-1.0, 1.0);

    double nbIterations;
    cout << "Entrez le nombre d'iterations souhaite: ";
    cin >> nbIterations;

    double ptDansCercle = 0;

    for(int i = 0; i<nbIterations; i++) {
        // Generation de deux valeurs aleatoires entre -1 et 1
        double x = myUnifRealDist(aleatoire);
        double y = myUnifRealDist(aleatoire);
        
        if ((x*x + y*y)<1.0) {
            ptDansCercle++;
        }
    }

    double aireCarre = 4.0;
    double approxPi = aireCarre * ptDansCercle/nbIterations;
    printf("L'approximation de pi est : %.6lf", approxPi);
    return 0;
}