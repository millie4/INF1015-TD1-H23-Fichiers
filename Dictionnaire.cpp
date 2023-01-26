#include <iostream>
#include <string>
#include <fstream>
using namespace std;


int main () {
    int nbrMots = 4;
    int nbrColonne = 3;
    string tableau[3][2];

    ifstream file("dictionnaire.txt");

    if(file.is_open()) {
        string montexte;
        // Read data from the file object and put it into a string.
        for (int i = 0; i < nbrMots; i++) {
            for (int j = 0; j < nbrColonne; j++) {
                while (getline(file, montexte, '\t')) { 
                    tableau[i][j] = montexte;
                }
            }
        }
        cout << tableau[0][0] << endl;

    }
        
    return 0;
}
