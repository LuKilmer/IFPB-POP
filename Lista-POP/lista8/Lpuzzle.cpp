#include <bits/stdc++.h>

using namespace std;

vector<int> times;
vector<vector<int>> abiguinhos;

int getAnswer(int index) {
    queue<int> aux;
    aux.push(index);
    times[index] = 1;
    
    while (!aux.empty()) {
        int sup = aux.front(); 
        aux.pop();
        
        for (int amigos : abiguinhos[sup]) {
            if (times[amigos] == times[sup]) {
                return true; 
            }
            if (times[amigos] == 0) {
                times[amigos] = (times[sup] == 1) ? 2 : 1;
                aux.push(amigos);
            }
        }
    }
    return false;
}

int main() {
    int n, m;
    cin >> n >> m;

    abiguinhos.resize(n + 1);
    times.resize(n + 1, 0);

    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        abiguinhos[a].push_back(b);
        abiguinhos[b].push_back(a);
    }

    for (int i = 1; i <= n; ++i) {
        if (times[i] == 0) {
            if (getAnswer(i)) {
                cout << "IMPOSSIBLE\n";
                return 0;
            }
        }
    }

    for (int i = 1; i <= n; ++i) {
        cout << times[i] << " ";
    }
    cout << endl;

    return 0;
}
