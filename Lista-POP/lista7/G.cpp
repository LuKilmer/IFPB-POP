#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <limits>

using namespace std;

const long long int INF = numeric_limits<long long int>::max();

vector<long long int> dijkstra(vector<vector<pair<int, long long int>>>& grafo, int v, vector<int>& caminho) {
    vector<long long int> dist(v + 1, INF);
    dist[1] = 0;
    priority_queue<pair<long long int, int>, vector<pair<long long int, int>>, greater<pair<long long int, int>>> pq;
    pq.push({0, 1});

    while (!pq.empty()) {
        long long int dist_atual = pq.top().first;
        int atual = pq.top().second;
        pq.pop();

        if (dist_atual > dist[atual])
            continue;

        for (auto& aresta : grafo[atual]) {
            int vizinho = aresta.first;
            long long int peso = aresta.second;
            if (dist[atual] + peso < dist[vizinho]) {
                dist[vizinho] = dist[atual] + peso;
                caminho[vizinho] = atual;
                pq.push({dist[vizinho], vizinho});
            }
        }
    }
    return dist;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, long long int>>> grafo(n + 1);

    for (int i = 0; i < m; i++) {
        int v1, v2;
        long long int v3;
        cin >> v1 >> v2 >> v3;
        grafo[v1].push_back({v2, v3});
        grafo[v2].push_back({v1, v3});
    }
    vector<int> caminho(n + 1, -1); 

    vector<long long int> distancia = dijkstra(grafo, n, caminho);
    
        vector<int> resultado;
        if (distancia[n] != INF) { 
            for (int j = n; j != -1; j = caminho[j]) {
                resultado.push_back(j);
            }
            for (int j = resultado.size() - 1; j >= 0; --j) {
                cout << resultado[j];
                if (j != 0) cout << " ";
            }
            cout << endl;
        } else {
            cout <<-1 << endl;
        }
    
    return 0;
}
