#include <iostream>
#include <string>
#include <fstream>
using namespace std;


int main () {
    int nbrMots = 4;
    int nbrColonnes = 3;
    string tableau[nbrMots][nbrColonnes];

    ifstream fichier("dictionnaire.txt");

    if(fichier.is_open()) {
        string texte;
        for (int ligne = 0; ligne < nbrMots; ligne++) {
            for (int colonne = 0; colonne < nbrColonnes; colonne++) {
                getline(fichier, texte, '\t');
                tableau[ligne][colonne] = texte;
            }
        }
        cout << tableau[2][3] << endl;
        int indexPlusLongMot = 0;
        int max_size =0;
        for (int mot = 0; mot < nbrMots; mot++) {
            if ( max_size < tableau[mot][0].size() ) { 
                max_size = tableau[mot][0].size();
                tableau[mot][0] = mot;
            }           
            else if ( max_size == mot.size() ) { 
                max mot += "; ";
                max mot += mot;
            }         
            // if (tableau[mot][0].length() < tableau[indexPlusLongMot][0].length()) {
            //     indexPlusLongMot = mot;
            // }
        }
        cout << tableau[indexPlusLongMot][0];
        
    }
        
    return 0;
}
