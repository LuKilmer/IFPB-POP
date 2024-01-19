#include <bits/stdc++.h>

using namespace std;

int forcaBruta2(const vector<pair<int, int>>& array, int limit) {
    int answer = 0;
    int tamanho = array.size();
    int total = 1 << tamanho;
    int test_answer=0;
    int multiplicador;
    string support_answer="";

    for (int i = 0; i < total; i++) {
        int somatorio = limit;
        test_answer=0;
        support_answer="";
        for (int j = 0; j < tamanho; j++) {
            if ((i & (1 << j)) != 0) {
                
                if (somatorio >= array[j].first) {
                    support_answer += "|" + to_string(array[j].first) + ":" + to_string(array[j].second);
                    multiplicador = somatorio / array[j].first;
                    test_answer += array[j].second * multiplicador;
                    somatorio %= array[j].first;
                }
            }
        }

        if (test_answer > answer) {
            cout << support_answer << endl;
            answer = test_answer;
            
        }
    }

    return answer;
}
int main() {
    int test_case, limit;
    pair<int, int> aux;
    vector<pair<int, int>> lista;
    cin >> test_case >> limit;
    while (test_case-- > 0) {
        cin >> aux.first >> aux.second;
        lista.push_back(aux);
    }
    
    cout << forcaBruta2(lista, limit) << endl;

    return 0;
}
