#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <limits> 
 
using namespace std;
 
const int INF = numeric_limits<int>::max();
 
int dijkstra(const vector<vector<pair<int, int>>>& graph, int n, int start, int tempo) {
    vector<int> dist(n+1, INF);
    dist[start] = 0;
    int contador = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push(make_pair(0, start));
 
    while (!pq.empty()) {
        int node = pq.top().second;
        int tempo_atual = pq.top().first;
        pq.pop();
 
        contador++;
 
        for (const auto& aux : graph[node]) {
            int vizinho = aux.first;
            int peso = aux.second;
 
            if (tempo_atual + peso <= tempo && tempo_atual + peso < dist[vizinho]) {
                dist[vizinho] = tempo_atual + peso;
                pq.push({dist[vizinho], vizinho});
            }
        }
    }
 
    return contador;
}
 
int main() {
    
    int n, start, tempo, m, test_case;
    cin >> test_case;
    while(test_case--){
        cin >>n >> start >> tempo >> m;
    
        vector<vector<pair<int, int>>> grafo(n+1);
        
        int v1, v2, v3;
        for (int i = 0; i < m; i++) {
            cin >> v1 >> v2 >> v3;
            grafo[v2].push_back({v1, v3});
        }
 
        cout << dijkstra(grafo,n, start, tempo) << endl;
        cout << endl;
    }
 
    return 0;
}