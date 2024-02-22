#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

int main() {
    ifstream inputFile("../inputs/input.txt"); 

    if (!inputFile.is_open()) {
        cerr << "Não foi possível abrir o arquivo de entrada." << endl;
        return 1;
    }

    double matriz[12][12];
    double total = 0;
    char operation;
    int quantity = 0;

    inputFile >> operation;

    for (int i = 0; i < 12; i++) {
        for (int j = 0; j < 12; j++) {
            inputFile >> matriz[i][j];
            if (j > i) {
                total += matriz[i][j];
                quantity += 1;
            }
        }
    }

    inputFile.close();

    if (operation == 'M') {
        cout << fixed << setprecision(1) << total / quantity << endl;
    } else {
        cout << total << endl;
    }

    return 0;
}
