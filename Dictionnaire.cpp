#include <iostream>
#include <string>
#include <fstream>
using namespace std;


int main () {
    int nbrMots = 4;
    int tableau[nbrMots];

    ifstream file("dictionnaire.txt");
    int count; // the number of lines

    if(file.is_open()) {
        string montexte;
        // Read data from the file object and put it into a string.
        while (getline(file, montexte)) { 
            // Print the data of the string.
            cout << montexte << "\n"; 
        }

    }
    return 0;
}
