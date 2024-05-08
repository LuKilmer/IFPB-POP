#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <limits>

using namespace std;

const long long int INF = numeric_limits<long long int>::max();

vector<long long int> dijkstra(vector<vector<pair<int, long long int>>>& grafo, int v, int fonte) {
    vector<long long int> dist(v, INF);
    dist[fonte] = 0;
    priority_queue<pair<long long int, int>, vector<pair<long long int, int>>, greater<pair<long long int, int>>> pq;
    pq.push({0, fonte});
    
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
                pq.push({dist[vizinho], vizinho});
            }
        }
    }
    return dist;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, long long int>>> grafo(n);
    int v1, v2;
    long long int v3;

    for (int i = 0; i < m; i++) {
        cin >> v1 >> v2 >> v3;
        grafo[v1 - 1].push_back({v2 - 1, v3});
    }

    vector<long long int> distancia = dijkstra(grafo, n, 0);
    for (int i = 0; i < n; ++i) {
        cout << distancia[i];
        if (i == n - 1)
            cout << endl;
        else
            cout << " ";
    }

    return 0;
}
