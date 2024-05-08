#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <limits> 

using namespace std;

const int INF = numeric_limits<int>::max();

int dijkstra(const vector<vector<pair<int, int>>>& graph, int n, int start, int tempo) {
    vector<int> dist(n + 1, INF);
    dist[start] = 0;
    int contador = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push(make_pair(0, start));

    while (!pq.empty()) {
        int node = pq.top().second;
        int tempo_atual = pq.top().first;
        pq.pop();

        if (tempo_atual > dist[node]) continue; 

        

        for (const auto& aux : graph[node]) {
            int vizinho = aux.first;
            int peso = aux.second;

            if (tempo_atual + peso <= tempo) {
                dist[vizinho] = tempo_atual + peso;
                pq.push({dist[vizinho], vizinho});
            }
        }
    }
    for(int i=1; i<= n; i++){
        if( dist[i] <= tempo){
            contador+=1;
        }
    }
    return contador;
}

int main() {
    int num_cases, empyt;
    cin >> num_cases;
    cin.ignore();
    
    for (int case_num = 0; case_num < num_cases; ++case_num) {
        int n, start, tempo, m;
        scanf("%d %d %d %d", &n, &start, &tempo, &m);
        vector<vector<pair<int, int>>> grafo(n + 1);
        
        int v1, v2, v3;
        for (int i = 0; i < m; i++) {
            scanf("%d %d %d", &v1, &v2, &v3);
            grafo[v1].push_back({v2, v3}); 
        }

        printf("%d\n", dijkstra(grafo, n, start, tempo));
        
        cout << endl;
        
        
    }

    return 0;
}
