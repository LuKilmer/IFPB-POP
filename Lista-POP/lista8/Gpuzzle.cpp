#include <bits/stdc++.h>

using namespace std;

vector<char> caminho;

int check(int x, int y, int lin, int col, const vector<vector<char>> &matriz) {
    return (x >= 0 && x < lin && y >= 0 && y < col && matriz[x][y] != '#');
}

int getAnswer(pair<int, int> comeco, pair<int,int> end, const vector<vector<char>> &matriz) {
    int lin = matriz.size();
    int col = matriz[0].size();
    vector<vector<bool>> visitado(lin, vector<bool>(col, false));
    vector<vector<pair<int, int>>> caminhos(lin, vector<pair<int, int>>(col, {-1, -1}));
    int x, y;

    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};

    queue<pair<int, int>> q;
    q.push({comeco.first, comeco.second});
    visitado[comeco.first][comeco.second] = true;

    while (!q.empty()) {
        int current_x = q.front().first;
        int current_y = q.front().second;
        q.pop();

        if (current_x == end.first && current_y == end.second) {
            x = end.first;
            y = end.second;
           
            while (x != comeco.first || y != comeco.second) {
                auto p = caminhos[x][y];
                int caminhos_x = p.first;
                int caminhos_y = p.second;
                if (caminhos_x < x)
                    caminho.push_back('D');
                else if (caminhos_x > x)
                    caminho.push_back('U');
                else if (caminhos_y < y)
                    caminho.push_back('R');
                else if (caminhos_y > y)
                    caminho.push_back('L');
                x = caminhos_x;
                y = caminhos_y;
            }
            reverse(caminho.begin(), caminho.end());
            return true;
        }

        for (int i = 0; i < 4; i++) {
            int newX = current_x + dx[i];
            int newY = current_y + dy[i];

            if (check(newX, newY, lin, col, matriz) && !visitado[newX][newY]) {
                q.push({newX, newY});
                visitado[newX][newY] = true;
                caminhos[newX][newY] = {current_x, current_y};
            }
        }
    }

    return false;
}



int main() {
    int x, y;
    cin >> x >> y;
    pair<int, int> comeco, objetivo;
    vector<vector<char>> matriz(x, vector<char>(y));

    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            cin >> matriz[i][j];
            if (matriz[i][j] == 'A') {
                comeco.first = i;
                comeco.second = j;
            }
            if (matriz[i][j] == 'B') {
                objetivo.first = i;
                objetivo.second = j;
            }
        }
    }

    if (getAnswer(comeco, objetivo, matriz)) {
        cout << "YES" << endl;
        cout << caminho.size()<<endl;
        for (char aux : caminho) {
            cout << aux;
        }
        cout << endl;
    } else {
        cout << "NO" << endl;
    };
        //LDDRRRRRU
    return 0;
}
