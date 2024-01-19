#include <bits/stdc++.h>

using namespace std;

bool diagonalPosition(pair<int,int> position, pair<int,int>match){
    pair<int,int>aux = position;
    while(aux.first<9 or aux.second < 9){
        if(aux == match){
            return true;
        }
        aux.first++;
        aux.second++;
    };
    aux = position;
    while(aux.first>0 or aux.second > 0){
        if(aux == match){
            return true;
        }
        aux.first--;
        aux.second--;
    };
    aux = position;
    while(aux.first>0 or aux.second < 9){
        if(aux == match){
            return true;
        }
        aux.first--;
        aux.second++;
    };
    aux = position;
    while(aux.first<9 or aux.second > 0){
        if(aux == match){
            return true;
        }
        aux.first++;
        aux.second--;
    };
    return false;
}


int main(){
    int answer =0;
    pair<int, int> aux;
    pair<int, int>match;
    while(true){
        answer = 0;
        cin >> aux.first >> aux.second >> match.first >> match.second;
        if(aux.first+aux.second+match.first+match.second == 0)break;
        if(aux != match){
            if(diagonalPosition(aux,match)){
                answer++;
            }else{
                if(aux.first!=match.first){
                    answer++;
                }
                if(aux.second!=match.second){
                    answer++;
                }
            }
        }
        cout << answer << endl;
    }

    return 0;
}