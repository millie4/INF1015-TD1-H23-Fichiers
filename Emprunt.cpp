#include <iostream>
using namespace std;


bool validation(int number, int borneSup, int borneInf, int montant) {
        bool valide = true;
        if (number > borneSup || number < borneInf || montant < 0 ) {
            valide = false;
        }
        return valide;
    }
int main() {
    while (true) {

        double somme_argent;
        double montant_mensuel;
        double taux_interet;

        cout << "Entrez la somme d'argent pretee : ";
        cin >> somme_argent;
        cout << "Entrez le montant rembourse mensuellement : "; 
        cin >> montant_mensuel;
        cout << "Entrez le taux d'interet annuel : ";
        cin >> taux_interet;

        // calcul du taux d'interets mensuel
        double taux_mensuel = taux_interet / 1200.0;

        // verification de la validité des données
        if (validation(taux_interet, 100.0, 0.0, somme_argent)) {

            // Calcul du montant total à rembourser, interets inclues 
            double MontantArembourse = somme_argent * (1.0 + taux_interet/100.0);
            // Calcul du montant remboursé mensuellement, intérets inclues 
            double Mensualite = montant_mensuel * (1.0 + taux_mensuel);
            // Calcul du nombre de mois nécessaires pour le remboursement
            double NombreDeMois = MontantArembourse / Mensualite;
            // Calcul des interets totaux percus par le pretteur
            double InteretsTotaux = montant_mensuel * taux_mensuel * NombreDeMois;

            cout << NombreDeMois << endl;
            cout << InteretsTotaux << endl;
            break;

        }

        // si les données ne sont pas valides, refaire la boucle
        else {
            cout << "Les données ne sont pas valides. veulliez reessayer." << endl;
        }
        }
    return 0;
}