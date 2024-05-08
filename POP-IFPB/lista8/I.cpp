#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;

int get_answer(vector<int> preco, vector<int> pages){
    
    vector<int> aux(m + 1, 0);

    for (int i = 0; i < n; i++) {
        for (int w = m; w >= pages[i]; w--) {
            aux[w] = max(aux[w], preco[i] + aux[w - pages[i]]);
        }
    }
    return aux[m];
}


int main(){
    
    cin >> n >> m;
    vector<int> preco(n);
    vector<int> pages(n);

    for (int i = 0; i < n; i++) {
        cin >> pages[i];
    }

    for (int j = 0; j < n; j++) {
        cin >> preco[j];
    }

    cout << get_answer(preco, pages) << endl;

    return 0;
}