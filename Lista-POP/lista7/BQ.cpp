#include <bits/stdc++.h>

using namespace std;

int get_answer(const vector<int> &porcaria, int limite) {
    int tamanho_da_porcaria = porcaria.size();
    int esquerda = 0, direita = 0, total = 0, answer = 0;

    while (direita < tamanho_da_porcaria) {
        if (total + porcaria[direita] <= limite) {
            total += porcaria[direita];
            answer = max(answer, direita - esquerda + 1);
            direita++;
        } else {
            total -= porcaria[esquerda];
            esquerda++;
        }
    }

    return answer;
}

int main() {
    int tamanho_array, limite;
    cin >> tamanho_array >> limite;

    vector<int> porcaria(tamanho_array);
    for (int i = 0; i < tamanho_array; ++i) {
        cin >> porcaria[i];
    }
    //sort(porcaria.begin(), porcaria.end());

    cout << get_answer(porcaria, limite) << endl;

    return 0;
}
