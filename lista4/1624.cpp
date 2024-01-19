#include <bits/stdc++.h>

using namespace std;


int forcaBruta1(const vector<pair<int,int>>& array, int limit) {
    int tamanho = array.size();
    int answer = 0;
    int total = 1 << tamanho; // faz o calculo do bit a esquerda, ou 2^4, caso o array tenha tamnaho 4
    int test_answer;
    int somatorio;
    for (int i = 0; i < total; i++) { // 16 possibilidades para um array de tamnho 4
        test_answer = 0;
        somatorio = 0;
        for (int j = 0; j < tamanho; j++) {
            if ((i & (1 << j)) != 0) { // bit rise, 2 = 0010 = aryay[1]
                // i sendo 10 = 1010 = array[1] e array[3]
                if(limit<(somatorio+array[j].second)){
                    if(test_answer>answer)answer=test_answer;
                    break;
                }
                somatorio+=array[j].second;
                test_answer+=array[j].first;
            }
        }
        if(test_answer>answer)answer=test_answer;
    }
    return answer;
}

int main(){

    int answer,test_case, limit, bigger, aux;
    pair<int,int> produto;
    cin>>test_case;
    vector<pair<int,int>>pesos;
    while(test_case!=0){
        pesos.clear();
        answer = 0;
        while(test_case--!=0){
            cin >>produto.first  >>produto.second ;
            pesos.push_back(produto);
        }
        cin >> limit;
        
        cout << forcaBruta1(pesos, limit)<< endl;
        
        cin>>test_case;
    }

    return 0;
}