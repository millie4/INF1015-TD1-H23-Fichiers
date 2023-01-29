#include <iostream>
#include <string>
#include <fstream>
using namespace std;

// initialisation d'une struct Dictionnaire 
struct Dictionnaire{
      string mots[4]; // Pour coontenir tous les mots du dictionnaire
      string type[4]; // Pour contenir tous les types du dictionnaire 
      string definition[4]; // Pour contenir toutes les définitions du dictionniare
};

int main () {

    Dictionnaire monDict; // creation d'un objet de type Dictionnaire

    int nMots = 4;
    int nColonnes = 3;
    ifstream fichier("dictionnaire.txt");

    if(fichier.is_open()) {

        string elementDictionnaire;
        int compteur = 0;
        // boucle pour iterer sur tout les elements du fichiers Dictionnaire.txt
        for (compteur; compteur< nMots*nColonnes; compteur++) { 
            // mettre les mots dans le tableau des mots
            if (compteur % nColonnes == 0) {
                getline(fichier, elementDictionnaire, '\t');
                monDict.mots[compteur/3] = elementDictionnaire;
            }
            // les types dans le tableau des types 
            else if (compteur % nColonnes == 1) {
                getline(fichier, elementDictionnaire, '\t');
                monDict.type[compteur/3] = elementDictionnaire;
            }
            // les définitions dans le tableau des définitions 
            else if (compteur % nColonnes == 2) {
                getline(fichier, elementDictionnaire, '\t');
                monDict.definition[compteur/3] = elementDictionnaire;
            }
        }

        int indexPlusLongMot = 0;
        // variable de la plus grande taille d'un mot
        int tailleMax = 0;
        // boucle qui itère sur tous les mots du dictionnaires (monDict.mots[])
        for (int indexMot = 0; indexMot < nMots; indexMot++) {
            // Calcule la taille et l'index du plus grand mot 
            if ( tailleMax < monDict.mots[indexMot].size() ) { 
                tailleMax = monDict.mots[indexMot].size();
                indexPlusLongMot = indexMot;
            }
        }    
        
        cout << monDict.mots[indexPlusLongMot] << ' '<< '(' << monDict.type[indexPlusLongMot] << ')' << ' ';
        cout << ':' << ' ' << monDict.definition[indexPlusLongMot]<< endl;       

    }
    return 0;
}
