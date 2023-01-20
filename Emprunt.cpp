#include <iostream>
using namespace std;
#define INFINITY __builtin_inff();
#include <cmath>


bool validerBornes(int nombre, int borneSup, int borneInf) {
        bool valide = true;
        if (nombre > borneSup || nombre < borneInf) {
            valide = false;
        }
        return valide;
    }
int main() {
    while (true) {

        double sommeArgent;
        double montantMensuel;
        double tauxInteret;

        cout << "Entrez la somme d'argent pretee : ";
        cin >> sommeArgent;
        cout << "Entrez le montant rembourse mensuellement : "; 
        cin >> montantMensuel;
        cout << "Entrez le taux d'interet annuel : ";
        cin >> tauxInteret;

        // calcul du taux d'interets mensuel
        double tauxMensuel = tauxInteret / 1200.0;

        // verification des bornes des donnees
        if (validerBornes(tauxInteret, 100.0, 0.0) & validerBornes(sommeArgent, HUGE_VAL, 0.0)) {

            // Calcul du montant total a rembourser, interets inclus 
            double dette = sommeArgent * (1.0 + tauxInteret/100.0);
            // Calcul du montant rembourse mensuellement, interets inclus 
            double mensualite = montantMensuel * (1.0 + tauxMensuel);
            // Calcul du nombre de mois necessaires pour le remboursement
            double nombreDeMois = dette / mensualite;
            // Calcul des interets totaux percus par le pretteur
            double interetsTotaux = montantMensuel * tauxMensuel * nombreDeMois;

            cout << nombreDeMois << endl;
            cout << interetsTotaux << endl;
            break;

        }

        // si les données ne sont pas valides, refaire la boucle
        else {
            cout << "Les données ne sont pas valides. veulliez reessayer." << endl;
        }
        }
    return 0;
}