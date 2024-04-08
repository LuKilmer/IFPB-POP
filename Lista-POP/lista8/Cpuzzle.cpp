#include <bits/stdc++.h>

using namespace std;

int getAnswer(int n, int m) {
    queue<pair<int, int>> aux; 
    unordered_set<int> visitado; 
    
    aux.push({n, 0});
    visitado.insert(n); 
    int num, clicks;
    while (!aux.empty()) {
        num = aux.front().first;
        clicks = aux.front().second;
        aux.pop();
        
        if (num == m) {
            return clicks; 
        }
        
        if (num < m && visitado.find(num * 2) == visitado.end()) {
            aux.push({num * 2, clicks + 1});
            visitado.insert(num * 2);
        }
        
        if (num > 1 && visitado.find(num - 1) == visitado.end()) {
            aux.push({num - 1, clicks + 1});
            visitado.insert(num - 1);
        }
    }
    
    return -1; 
}

int main() {
    int n, m;
    cin >> n >> m; 
    cout <<  getAnswer(n, m) << endl;
    
    return 0;
}
