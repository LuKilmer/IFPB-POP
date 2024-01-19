#include <bits/stdc++.h>

using namespace std;




void forcaBruta(const vector<int>& array) {
    int tamanho = array.size();

    int totalCombinacoes = 1 << tamanho;

    for (int i = 0; i < totalCombinacoes; i++) {
        cout << "Combinação " << i << ": ";

        for (int j = 0; j < tamanho; j++) {
            if ((i & (1 << j)) != 0) {
                cout << array[j] << " ";
            }
        }

        cout << endl;
    }
}

void forcaBruta1(const vector<int>& array) {
    int tamanho = array.size();

    int totalCombinacoes = 1 << tamanho;

    for (int i = 0; i < totalCombinacoes; i++) {
        cout << "Combinação " << i << ": ";

        for (int j = 0; j < tamanho; j++) {
            if ((i & (1 << j)) != 0) {
                
                cout << array[j] << " ";
            }
        }
        cout << endl;
    }
}

int main() {
    vector<pair<int,int>> array1 = {
        {72,17},
        {44,23},
        {31,24},
        {22,2}
    };
    vector<int> array = {0, 1, 2, 3};
    forcaBruta1(array);

    return 0;
}