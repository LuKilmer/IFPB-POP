#include <bits/stdc++.h>

using namespace std;

void sontarMatriz(vector<vector<char>>& matriz, vector<vector<bool>>& visitado, int i, int j) {
    int lin = matriz.size();
    int col = matriz[0].size();

    if (i < 0 || i >= lin || j < 0 || j >= col || matriz[i][j] == '#' || visitado[i][j]) {
        return;
    }

    visitado[i][j] = true;

    sontarMatriz(matriz, visitado, i + 1, j);
    sontarMatriz(matriz, visitado, i - 1, j);
    sontarMatriz(matriz, visitado, i, j + 1);
    sontarMatriz(matriz, visitado, i, j - 1);
}

int getAnswer(vector<vector<char>>& matriz) {
    int lin = matriz.size();
    int col = matriz[0].size();
    vector<vector<bool>> visitado(lin, vector<bool>(col, false));
    int contador = 0;
    for (int i = 0; i < lin; ++i) {
        for (int j = 0; j < col; ++j) {
            if (matriz[i][j] == '.' && !visitado[i][j]) {
                sontarMatriz(matriz, visitado, i, j);
                contador++;
            }
        }
    }
    return contador;
}

int main() {
    int x, y;
    cin >> x >> y;

    vector<vector<char>> matriz(x, vector<char>(y));

    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            cin >> matriz[i][j];
        }
    }

    cout << getAnswer(matriz) << endl;

    return 0;
}
