#include <iostream>
using namespace std;
#define HUGE_VAL __builtin_huge_val();
#include <cmath>

bool validerBornes(double nombre, double borneInf, double borneSup) {
        bool estValide = true;
        if (nombre > borneSup || nombre < borneInf) {
            estValide = false;
        }
        return estValide;
    }

int main() {

    while (true) {

        double sommeArgent;
        double montantMensuel;
        double tauxInteretAnnuel;

        cout << "Entrez la somme d'argent pretee : ";
        cin >> sommeArgent;
        cout << "Entrez le montant rembourse mensuellement : "; 
        cin >> montantMensuel;
        cout << "Entrez le taux d'interet annuel : ";
        cin >> tauxInteretAnnuel;

        // calcul du taux d'interets mensuel
        int nombreMoisParAnnee = 12;
        double tauxInteretMensuel = (tauxInteretAnnuel / 100) / nombreMoisParAnnee;

        // verification des bornes des donnees
        if (validerBornes(tauxInteretAnnuel, 0.0, 100.0) & validerBornes(sommeArgent, 0.0, HUGE_VAL)) {

            // Calcul du montant total à rembourser, interets inclus 
            double dette = sommeArgent * (1.0 + tauxInteretAnnuel/100.0);
            // Calcul du nombre de mois necessaires pour le remboursement
            double nombreDeMois = dette / montantMensuel;
            // Calcul des interets totaux percus par le pretteur
            double interetsTotaux = sommeArgent * (1 + tauxInteretAnnuel/100);

            cout << "Cela prendra " << nombreDeMois << " mois pour rembourser la dette."<< endl;
            cout << "La somme d'interet percue par le pretteur est : "<< interetsTotaux << "$" << endl;
            break;
        }
        // si les données ne sont pas valides, refaire la boucle
        else {
            cout << "Les donnees ne sont pas valides. Veulliez reessayer." << endl;
        }
        }
    return 0;
}