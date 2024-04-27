#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <algorithm>
#include <climits>

using namespace std;

long long int bellmand_ford(vector<vector<pair<int, long long int>>> grafo){
    vector<long long int> dist(grafo.size(), LLONG_MIN);
    dist[1]=0;
    int n = grafo.size()-1;
    for (int i = 0; i < n - 1; i++){
        for (int j = 1; j < n + 1; j++){
            if (dist[j] != LLONG_MIN){
                for (pair<int, long long int> x : grafo[j]){
                    int v = x.first;
                    long long int w = x.second;
                    if (dist[j] + w > dist[v])
                        dist[v] = dist[j] + w;
                }
            }
        }
    }
    for(int i = 1; i < n + 1; i++){
        if( dist[i] != LLONG_MIN){
            for(pair<int,long long int> aux: grafo[i]){
                int next = aux.first;
                long long int peso = aux.second;
                if(dist[i] + peso > dist[next]){
                    queue<int> answer;
                    answer.push(i);
                    vector<bool> visitado(n+1, false);
                    while(answer.size()!=0){
                        int node = answer.front();
                        answer.pop();
                        if(node == n){
                            return -1;
                        }
                        visitado[node] = true;
                        for(pair<int,long long int> sangue: grafo[node]){
                            if(!visitado[sangue.first]){
                                answer.push(sangue.first);
                            }
                        }
                    }
                }

            }
        }
    }
    return dist[n];
}

int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, long long int>>> grafo(n + 1, vector<pair<int, long long int>>());
    for (int i = 0; i < m; i++){
        int v1, v2;
        long long int v3;
        cin >> v1 >> v2 >> v3;
        grafo[v1].push_back({v2, v3});
    }
    cout << bellmand_ford(grafo) << endl;
    return 0;
}
