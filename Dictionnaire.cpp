#include <iostream>
#include <string>
#include <fstream>
using namespace std;


int main () {
    int nMots = 4;
    int nColonnes = 3;
    int elementsTotaux = nColonnes*nMots;
    // initialisation d'un tableau de taille 12, soit le nombre total d'élements dans le dictionnaires 
    string tableau[elementsTotaux]; 
    // lecture du fichier .txt
    ifstream fichier("dictionnaire.txt");

    if(fichier.is_open()) {
        string texte;
        // On itere sur chaque element du tableau
        for (int element=0; element< elementsTotaux; element++) {
            getline(fichier, texte, '\t');
            tableau[element] = texte;
        }

        // initialisation de la variable de l'index du plus long mot
        int indexPlusLongMot = 0;
        // variable de la plus grande taille d'un mot
        int tailleMax = 0;
        int prochainMot = 3;
        for (int indexMot = 0; indexMot < nMots; indexMot+=prochainMot) {
            if ( tailleMax < tableau[indexMot].size() ) { 
                tailleMax = tableau[indexMot].size();
                indexPlusLongMot = indexMot;
            }           
        }
        cout << tableau[indexPlusLongMot] << " "<< '(' << tableau[indexPlusLongMot + 1] << ')' << " " << ":" << " "<< tableau[indexPlusLongMot + 2];
        
    }
        
    return 0;
}
