// Nombres premiers : Écrivez un programme qui lit du clavier un nombre entier, puis détermine si ce
// nombre est premier ou non. S’il n’est pas premier, le plus petit entier qui est un diviseur de ce nombre est
// affiché. Pour trouver un diviseur, commencez par vérifier si le nombre entré est divisible par 2, sinon
// essayez de le diviser par les nombres impairs entre 3 et √, et arrêtez-vous au plus petit (aide : un
// algorithme similaire est écrit dans l’énoncé du TD1).
// Exemple d’affichage :
// Entrer un nombre entier : 8
// Ce nombre n'est pas premier car il est divisible par 2.
// Entrer un nombre : 2
// Ce nombre est premier. 

#include <iostream>
using namespace std;
#include <cmath>

int main () {

    int i; 
    int nombre; // notre nombre entier 
    bool is_prime = true;
    cout << "Entrez un nombre entier : ";
    cin >> nombre;

    // O et 1 sont des nombres premiers 
    if (nombre == 0 || nombre == 1) {
        is_prime = false;
    }

    // Boucle pour verifier si le nombre est premier 
    for (i = 2; i <= nombre/2; ++i) {
        if (nombre % i == 0) {
        is_prime = false;
        break;
        }
    }

    int n = 3;
    if (is_prime)
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