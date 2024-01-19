#include <bits/stdc++.h>

using namespace std;

bool answere;
pair<int, int> final1 = {4, 4};
vector<pair<int,int>>visited;


void mostrar_matriz(vector<vector<int>>matriz, pair<int,int>atuacl_fator){
    for(int i = 0; i < 5; i ++){
        for(int j = 0 ; j < 5; j++){
            if(atuacl_fator.first == i && atuacl_fator.second==j){
                cout << "X" << " ";
            }else{
                cout << matriz[i][j] << " ";
            }
        }
        cout << endl;
    }
}
void logteste(pair<int,int>loga){
    cout <<"("<< loga.first << "|" << loga.second << ")";
}

int recursao(vector<vector<int>>matriz, pair<int,int>atual,pair<int,int>anterior){
    mostrar_matriz(matriz, atual);
    logteste(atual);
    logteste(anterior);
    cout << endl;
    if(atual.first == final1.first && atual.second == final1.second){
        answere = 1;
        return 1;
    }
    if(find(visited.begin(), visited.end(), atual)!=visited.end()){
        return 0;
    }else{
        visited.push_back(atual);
    }
    
    

    //sul
    if(atual.first+1<=4){
        logteste(atual);
        cout<< "teste para o sul" << endl;
        if(!(atual.first+1 == anterior.first && atual.second==anterior.second) && matriz[atual.first+1][atual.second]==0){
            logteste(atual);
            cout<< " pode ir para o sul" << endl;
            pair<int,int> auxi = atual;
            atual.first++;
            if(recursao(matriz,atual,auxi)) return 1;
            
        }
    }
    //direita
    if(atual.second+1<=4){
        logteste(atual);
        cout<< "teste para o direita" << endl;
        
        if(!(atual.first == anterior.first && atual.second+1==anterior.second) && matriz[atual.first][atual.second+1]==0){
            logteste(atual);
            cout<< " pode ir para o direita" << endl;
            pair<int,int> auxi = atual;
            atual.second++;
            if(recursao(matriz,atual,auxi)) return 1;
           
        }
    }
    //norte
    if(atual.first-1>=0){
        logteste(atual);
        cout<< "teste para o norte" << endl;

        if(!(atual.first-1 == anterior.first && atual.second==anterior.second) && matriz[atual.first-1][atual.second]==0){
            logteste(atual);
            cout<< " pode ir para o norte" << endl;
            pair<int,int> auxi = atual;
            atual.first--;
            if(recursao(matriz,atual,auxi)) return 1;
            
        }
    }
    
    //esquerda
    if(atual.second-1>=0){
        logteste(atual);
        cout<< "teste para o esquerda" << endl;
        if(!(atual.first == anterior.first && atual.second-1==anterior.second) && matriz[atual.first][atual.second-1]==0){
            logteste(atual);
            cout<< " pode ir para o esquerda" << endl;
            pair<int,int> auxi = atual;
            atual.second--;
            if(recursao(matriz,atual,auxi)) return 1;
            
        }
    }
    cout << "fault" << endl;
    return 0;
}


int main(){
    int coluna = 5;
    int linha = 5;
    int aux;
    vector<vector<int>> matriz(5, vector<int>(5));
    for(int i = 0; i < coluna; i ++){
        for(int j = 0 ; j < linha; j++){
            cin >> matriz[i][j];
        }
    }
  
    pair<int,int>inicio = {0,0};
    pair<int,int>past = {6,6};
    recursao(matriz,inicio,past);
    if(answere){
        cout << "possivel" << endl;
    }else{
        cout << "impossível" << endl;
    }
    return 0;
}