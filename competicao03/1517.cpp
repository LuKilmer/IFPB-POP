#include <bits/stdc++.h>

using namespace std;

struct posicao {
    int x;
    int y;
    int extra;
};


int get_answer(posicao inicio, vector<posicao> apples, posicao pessoa, int maior_tempo){
    int answer=0;
    int cerarios=0;
    int matriz[inicio.x][inicio.y];
    for (int i = 0; i < inicio.x; ++i) {
        for (int j = 0; j < inicio.y; ++j) {
            if(i<=inicio.x-1 && j <= inicio.y-1){
                matriz[i][j] = 0;
            }
        }
    };
    for(posicao aux : apples){
        matriz[aux.x][aux.y] = aux.extra;
    };
    if(matriz[pessoa.x][pessoa.y]>0)answer++;
    matriz[pessoa.x][pessoa.y]=-1;

    

    
    return answer;

}

int main(){
    
    posicao inicio;
    posicao apple;
    posicao pessoa;
    vector<posicao> apples;
    int maior_tempo;
    cin >> inicio.x >> inicio.y >> inicio.extra;
    while(true){
        if(inicio.x+ inicio.y+ inicio.extra==0) break;
        while(inicio.extra--!=0){
            cin >> apple.x >> apple.y >> apple.extra;
            apples.push_back(apple);
            if(apple.extra>maior_tempo) maior_tempo = apple.extra;

        }
        cin >> pessoa.x >> pessoa.y;
        cout << get_answer(inicio, apples, pessoa,maior_tempo)<< endl;
        cin >> inicio.x >> inicio.y >> inicio.extra;
    }


    return 0;
}