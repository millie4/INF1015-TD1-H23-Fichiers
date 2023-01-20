#include <iostream>
#define HUGE_VAL __builtin_huge_val();
#include <cmath>
using namespace std;

//À enlever dans le doc final!!
bool validerBornes(double nombre, double borneInf, double borneSup) {
        bool valide = true;
        if (nombre > borneSup || nombre < borneInf) {
            valide = false;
        }
        return valide;
    }

int main() {

    double nbRebonds, hauteur, coeffRebond;
    bool validationVariables = false;

    while(!validationVariables) {
        cout << "Entrez le nombre de rebonds : ";
        cin >> nbRebonds;
        cout << "Entrez la hauteur initiale : ";
        cin >> hauteur;
        cout << "Entrez le coefficient : ";
        cin >> coeffRebond;
        
        if (validerBornes(nbRebonds, 0.0, HUGE_VAL) & validerBornes(hauteur, 0.0, HUGE_VAL) & validerBornes(coeffRebond, 0.0, 1.0)) {
            validationVariables = true;
        }
        else {
            cout << "Les donnees ne sont pas valides. Veulliez reessayer." << endl;
        }
    }
    
    double g = 9.81; // constante d'acceleration gravitationnelle
    double vitesse = sqrt(2.0 * g * hauteur);

    for (int i = 2; i < nbRebonds; i++) {
        hauteur = ( vitesse * vitesse + 1 ) / ( 2.0 * g );
        vitesse *= coeffRebond;
    }

    cout << hauteur << endl;
}