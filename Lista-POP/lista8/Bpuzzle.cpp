#include <bits/stdc++.h>

using namespace std;

unordered_map<int, vector<int>> aux;

int arvore(int index, unordered_map<int, vector<int>>& aux, vector<int>& answer) {
    int contador = 1;
    if (aux.find(index) != aux.end()) {
        for (int sup : aux[index]) {
            contador += arvore(sup, aux, answer);
        }
    }
    answer[index - 1] = contador;
    return contador;
}

int main() {
    int n;
    cin >> n;

    vector<int> funcionarios(n - 1);
    for (int i = 0; i < n - 1; ++i) {
        cin >> funcionarios[i];
    }

   
    for (int i = 2; i <= n; ++i) {
        int boss = funcionarios[i - 2];
        aux[boss].push_back(i);
    }
    vector<int> answer(n);
    arvore(1, aux, answer);
    for (int contador : answer) {
        cout << contador-1 << " ";
    }
    cout << endl;

    return 0;
}
