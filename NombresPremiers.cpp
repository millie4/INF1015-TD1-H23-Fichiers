#include <iostream>
using namespace std;
#include <cmath>

int main () {

    int nombre; // notre nombre entier 
    bool estPrime = true;
    cout << "Entrez un nombre entier : ";
    cin >> nombre;

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
        cout << nombre << " est un nombre premier";
    }
    else {
        if (nombre % 2 == 0) {
            printf("Ce nombre n'est pas premier car il est divisible par 2");
        }
        else {
            for (int n = 3; n <= sqrt(nombre); n += 2 ) {
                if (nombre % n == 0 ) {
                    printf("Ce nombre n'est pas premier car il est divisible par %d\n", n);
                    break;
                }
            }
        }
    }
  return 0;
}