#include <bits/stdc++.h>
using namespace std;

vector<int> getAnswer(const vector<vector<int>>& procaria, int start, int final) {
    vector<int> historico(procaria.size() + 1, -1);
    vector<int> visitado(procaria.size() + 1, 0);
    queue<int> aux;
    int x;
    aux.push(start);
    visitado[start] = true;

    while (!aux.empty()) {
        x = aux.front();
        aux.pop();
        for (int v : procaria[x]) {
            if (!visitado[v]) {
                visitado[v] = 1;
                historico[v] = x;
                aux.push(v);
            }
        }
    }
    vector<int> caminho;
    int sup = final;
    while (sup != -1) {
        caminho.push_back(sup);
        sup = historico[sup];
    }
    reverse(caminho.begin(), caminho.end());
    return caminho;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> porcaria(n + 1);

    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        porcaria[a].push_back(b);
        porcaria[b].push_back(a);
    }

    auto answer = getAnswer(porcaria, 1, n);
    
    if (answer.size()!=1) {
        cout << answer.size() << endl;
        for (int ayx : answer) {
            cout << ayx << " ";
        }
        cout << endl;
    } else {
        cout << "IMPOSSIBLE" << endl;
    }

    return 0;
}
