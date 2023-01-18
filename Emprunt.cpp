#include <iostream>
using namespace std;


bool validation(int number, int borneSup, int borneInf, int montant) {
        bool valide = true;
        if (number > borneSup || number < borneInf || montant < 0 ) {
            valide = false;
        }
        return valide;
    }

int tempsNecessaire(int montant, int remboursementMensuel, int tauxAnnuel) {

}

int main() {
    double somme_argent;
    double montant_mensuel;
    double taux_interet;

    cout << "entrez la somme d'argent pretee : " << endl;
    cin >> somme_argent;
    cout << "Entrez le montant rembourse mensuellement : " << endl; 
    cin >> montant_mensuel;
    cout << "Entrez le taux d'interet annuel : " << endl;

    if (validation(taux_interet, 100, 0, somme_argent)) {
        tempsNecessaire(somme_argent, montant_mensuel, taux_interet);
    }

    else {
        cout << "Les données ne sont pas valides. veulliez reessayer." << endl;

    }

}