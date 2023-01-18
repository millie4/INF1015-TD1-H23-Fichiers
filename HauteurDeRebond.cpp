#include <iostream>
#include <cmath>
using namespace std;

int validation(int number, int borneSup, int borneInf, int mombreRebond, int hauteur) {
        bool valide = true;
        if (number > borneSup || number < borneInf || mombreRebond < 0 || hauteur < 0 ) {
            valide = false;
        }
        return valide;
    }

int main() {

    double nb_rebonds, hauteur_init, coef;

    cout << "entrez le nombre de rebonds : ";
    cin >> nb_rebonds;
    cout << "entrez la hauteur maximale : ";
    cin >> hauteur_init;
    cout << "entrez le coefficient : ";
    cin >> coef;

    double vitesse = sqrt(2*9.8*hauteur_init);

    if (validation(coef, 1, 0, hauteur_init, nb_rebonds)) {
        for (int i = 2; i < nb_rebonds; i++) {
            


        }
    }




}