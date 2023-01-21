#include <iostream>
#include <cmath>
#include <random>
using namespace std;

int main() {
    // Initialisation d'un générateur aleatoire.
    default_random_engine aleatoire(random_device{}());
    std::uniform_real_distribution<double> myUnifRealDist(-1.0, 1.0);
    
    // Generation de deux valeurs aleatoires entre -1 et 1
    double x = myUnifRealDist(aleatoire);
    std::cout << std::fixed << x << std::endl;

    double y = myUnifRealDist(aleatoire);
    std::cout << std::fixed << y << std::endl;

    return 0;
}