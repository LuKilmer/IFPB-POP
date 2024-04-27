#include <iostream>
#include <vector>
#include <utility>
#include <limits>
#include <algorithm>

using namespace std;

const int INF = numeric_limits<int>::max();


vector<int> bellmand_ford_adulterado(vector<vector<pair<int, long long int>>> grafo, int n){
    vector<int> answer;
    int ciclo = -1;
    vector<long long int> dist(n+1, INF);
    vector<int> predecessor(n+1, -1);
    dist[0] = dist[1] = 0;
    
    for(int iter = 0; iter < n && ciclo; iter++) {
        ciclo = 0;
        for(int u = 1; u <= n; u++) {
            for(auto edge : grafo[u]) {
                int v = edge.first;
                long long int w = edge.second;
                
                if(dist[v] > dist[u] + w) {
                    dist[v] = dist[u] + w;
                    predecessor[v] = u;
                    ciclo = v;
                }
            }
        }
    }

    if(ciclo!=0){
        for(int i = 0; i < n; i++)ciclo = predecessor[ciclo];
        for(int i = ciclo;; i = predecessor[i]){
            answer.push_back(i);
            if(i == ciclo && (int) answer.size() > 1)break;
        }
        reverse(answer.begin(), answer.end());
    }

    return answer;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, long long int>>> grafo(100005);
    int v1, v2;
    long long int v3;

    for (int i = 0; i < m; i++) {
        cin >> v1 >> v2 >> v3;
        grafo[v1].push_back({v2 , v3});
    }
    vector<int> answer = bellmand_ford_adulterado(grafo, n);
    if(answer.size()==0){
        cout << "NO" << endl;
    }else{
        cout << "YES" << endl;
        for(int i = 0; i < answer.size(); i++){
            cout << answer[i] << (" \n")[i==answer.size()-1];
        }
    }

    return 0;
}
