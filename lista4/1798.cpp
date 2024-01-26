#include <bits/stdc++.h>

using namespace std;


int answer = 0;



void forcaBruta5(const vector<pair<int,int>>& lista, int limit, int total){
    if(total>answer)answer = total;
    for(int i = 0; i < lista.size(); i++){
        if(lista[i].first <=limit){
            forcaBruta5(lista, limit % lista[i].first,total + lista[i].second * (limit / lista[i].first));    
        }else{
            break;
        }
    }
}


void mochilaMochila(const vector<pair<int,int>>& lista, int limit){}

void showData(vector<pair<int, int>> lista ){
    for(pair<int, int> aux: lista){
        cout << aux.first <<" "<< aux.second << endl;
    }
    
    answer = lista.size();
}
void teste_bag(const vector<pair<int,int>>& lista, int limit){
    
    int total = 0;
    int aux = limit;
    for(int i = 0; i < lista.size();i++){
        total = (aux/lista[i].first)* lista[i].second;
        aux = aux%lista[i].first;
        if(total>answer)answer =total;
        for(int j = 0; j < lista.size();j++){
            if(lista[j].first<=aux){
                total = (aux/lista[j].first)* lista[j].second;
                aux = aux%lista[j].first;
                if(total>answer)answer =total;
            }
            for(int w = 0; w < lista.size();w++){
                if(lista[w].first<=aux){
                    total = (aux/lista[w].first)* lista[w].second;
                    if(total>answer)answer =total;
                }
            }
        }
        if(total>answer)answer =total;
    }
    if(total>answer)answer =total;
}

int main() {
    int test_case, limit; int  contador = 0;
    pair<int, int> aux;
    vector<pair<int, int>> lista;
    cin >> test_case >> limit;
    while (test_case-- > 0) {
        cin >> aux.first >> aux.second;
        contador++;
        if(aux.first<=limit)
        lista.push_back(aux);
    }
    sort(lista.begin(),lista.end());
    cout << "tamanho:"<< lista.size()<< endl;
    //showData(lista);
    teste_bag(lista, limit);
    cout<< "resposta:" << answer << endl;
    return 0;
}
