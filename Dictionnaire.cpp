#include <iostream>
#define HUGE_VAL __builtin_huge_val();
#include <string>
#include <fstream>
using namespace std;


int main () {
    int nbrMots = 4;
    int tableau[nbrMots];

    ifstream file("dictionnaire.txt");
    int count; // the number of lines
    string* lines = nullptr; // array of strings

    if(file.is_open()) {
        string myArray[5];

        for(int i = 0; i < 5; ++i)
        {
            file >> myArray[i];
        }
    }
}
