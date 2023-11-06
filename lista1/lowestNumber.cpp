#include <bits/stdc++.h>

using namespace std;

int main(){
    int size_thing = 0;
    int answer = INT_MAX;
    int position = 0;
    int aux;
    cin >> size_thing;
    for(int i =0; i < size_thing; i++){
        cin >> aux;
        if(answer > aux){
            answer = aux;
            position = i;
        } answer = aux;
        
        size_thing -=1;
    }

    cout << "Menor valor: "<<answer <<endl;
    cout << "Posicao: "<<position <<endl;
}