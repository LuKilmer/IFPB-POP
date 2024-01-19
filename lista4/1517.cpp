#include <bits/stdc++.h>

using namespace std;

struct apple{
    int x;
    int y;
    int time;
};
void zerarmatriz(std::vector<std::vector<int>>& matriz, const pair<int,int>& tamanho) {
    matriz.assign(tamanho.first, std::vector<int>(tamanho.second, 0));
}

bool compararTempo(const apple& a, const apple& b) {
    return a.time >= b.time;
}

void timeStamp(pair<int,int>matriz,vector<apple> apples){
    sort(apples.begin(),apples.end(),compararTempo);
    int contador = 0;
    
    
    vector<vector<int>> matriz2(matriz.first, vector<int>(matriz.second, 0));
    
    while(!apples.empty()){
        if(apples.back().time != contador){
            cout << "segundo: "<<contador <<endl;
            for(int i =0; i < matriz.first;i++){
                for(int j=0; j < matriz.second; j++){
                    cout << matriz2[i][j] << " ";
                }
                cout << endl;
            }
            zerarmatriz(matriz2, matriz);
            contador++;
        }else{
            matriz2[apples.back().y-1][apples.back().x-1]++;
            apples.pop_back();
        }
    }
    cout << "segundo: "<<contador <<endl;
    for(int i =0; i < matriz.first;i++){
        for(int j=0; j < matriz.second; j++){
            cout << matriz2[i][j] << " ";
        }
        cout << endl;
        }
    zerarmatriz(matriz2, matriz);
}


int main(){
    int test_case;
    pair<int,int>matriz, position;
    vector<apple> apples;
    apple sup;
    cin >> matriz.first >> matriz.second >> test_case;
    
    while(matriz.first + matriz.second +test_case!=0){
        apples.clear();
        while(test_case-->0){
            cin >> sup.x >> sup.y >> sup.time;
            apples.push_back(sup);
        }
        cout<<"new testcase\n";
        cin >> position.first >> position.second;
        timeStamp(matriz, apples);

        cin >> matriz.first >> matriz.second >> test_case;
    }
    return 0;
}