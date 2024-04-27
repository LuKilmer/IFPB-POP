#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <limits>

using namespace std;

const long long int INF = numeric_limits<long long int>::max();

long long int dijkstra(vector<vector<pair<int, long long int>>>& grafo, int v, int origem, int dest) {
    vector<long long int> dist(v, INF);
    dist[origem] = 0;
    priority_queue<pair<long long int, int>, vector<pair<long long int, int>>, greater<pair<long long int, int>>> pq;
    pq.push({dist[origem], origem});
    
    while (!pq.empty()) {
        long long int dist_atual = pq.top().first;
        int atual = pq.top().second;
        pq.pop();
        
        if (atual == dest) { 
            return dist[dest];
        }
      
        for (auto& aresta : grafo[atual]) {
            int vizinho = aresta.first;
            long long int peso = aresta.second;
            if (dist[atual] + peso < dist[vizinho]) {
                dist[vizinho] = dist[atual] + peso;
                pq.push({dist[vizinho], vizinho});
            }
        }
    }
    return -1; 
}

int main() {
    int t;
    cin >> t;
    int contador = 1;

    while (contador != t + 1) {
        int n, m, orig, dest;
        cin >> n >> m >> orig >> dest;
        vector<vector<pair<int, long long int>>> grafo(n+1);
       
        for (int i = 0; i < m; i++) {
            int v1, v2;
            long long int v3;
         
            cin >> v1 >> v2 >> v3;
            if (v1 >= 0 && v1 < n && v2 >= 0 && v2 < n) {
                grafo[v1].push_back({v2, v3});
                grafo[v2].push_back({v1, v3});
            } 
        }
       
        if (orig < n && dest < n && !grafo[dest].empty()) {
            long long int result = dijkstra(grafo, n, orig, dest);
            if (result != -1) {
                cout << "Case #" << contador << ": " << result << endl;
            } else {
                cout << "Case #" << contador << ": " << "unreachable" << endl;
            }
        } else {
            cout << "Case #" << contador << ": " << "unreachable" << endl;
        }
        contador++;
    }

    return 0;
}