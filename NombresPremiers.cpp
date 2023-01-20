#include <iostream>
using namespace std;
#include <cmath>

int main () {

    int i; 
    int nombre; // notre nombre entier 
    bool est_prime = true;
    cout << "Entrez un nombre entier : ";
    cin >> nombre;

    // O et 1 sont des nombres premiers 
    if (nombre == 0 || nombre == 1) {
        est_prime = false;
    }

    // Boucle pour verifier si le nombre est premier 
    for (i = 2; i <= nombre/2; ++i) {
        if (nombre % i == 0) {
        est_prime = false;
        break;
        }
    }

    int n = 3;
    if (est_prime)
        cout << nombre << " est un nombre premier";
    else {
        if (nombre % 2 == 0) {
            printf("Ce nombre n'est pas premier car il est divisible par 2");
        }
        else {
            for (n; n <= sqrt(nombre); n += 2 ) {
                if (nombre % n == 0 ) {
                    printf("Ce nombre n'est pas premier car il est divisible par %d\n", n);
                    break;
                }
            }
        }
    }
  return 0;
}