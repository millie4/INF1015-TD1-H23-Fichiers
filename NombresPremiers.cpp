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

int main () {
    int i, nombre;
    bool is_prime = true;
    

    cout << "Entrez un nombre entier : ";
    cin >> nombre;

    // 0 and 1 are not prime numbers
    if (nombre == 0 || nombre == 1) {
        is_prime = false;
    }

    // loop to check if n is prime
    for (i = 2; i <= nombre/2; ++i) {
        if (nombre % i == 0) {
        is_prime = false;
        break;
        }
    }

    int n = 2;
    if (is_prime)
        cout << nombre << " est un nombre premier";
    else
        while (n <= nombre) {
            if (nombre % n == 0) {
                printf("Ce nombre n'est pas premier car il est divisible par %d\n", n);
                break;
            }
            n ++;
        }
  return 0;
}
