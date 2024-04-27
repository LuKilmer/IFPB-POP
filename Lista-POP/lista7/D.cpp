#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>
#include <climits>
using namespace std;

void floyd_warshall(vector<vector<long long>>& dist, vector<vector<pair<int, long long int>>>& grafo, int n){
    for (int i = 1; i <= n; ++i) {
        for (auto& ponto : grafo[i]) {
            int v = ponto.first;
            long long int weight = ponto.second;
            dist[i][v] = min(dist[i][v], weight);
            dist[v][i] = min(dist[v][i], weight);
        }
    }
    for (int k = 1; k <= n; ++k) {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (dist[i][k] < LLONG_MAX && dist[k][j] < LLONG_MAX)
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
}

int main(){
    int n, m, q;
    cin >> n >> m >> q;
    vector<vector<pair<int, long long int>>> grafo(n + 1);
    for (int i = 0; i < m; ++i) {
        int a, b;
        long long int c;
        cin >> a >> b >> c;
        grafo[a].push_back({b, c});
        grafo[b].push_back({a, c});
    }
    vector<vector<long long>> dist(n + 1, vector<long long>(n + 1, LLONG_MAX));

    for (int i = 1; i <= n; i++) {
        dist[i][i] = 0;
    }

    floyd_warshall(dist, grafo, n);

    for (int i = 0; i < q; ++i) {
        int origem, dest;
        cin >> origem >> dest;
        //cout << dist[origem][dest] << endl;
        cout << (dist[origem][dest] >= LLONG_MAX ? -1 : dist[origem][dest]) << endl;
    }
}
