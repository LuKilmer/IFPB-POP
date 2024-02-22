#include <bits/stdc++.h>

using namespace std;

int main(){
    int num;
    cin >> num;
    long long actual = 0;
    long long past = actual;
    long long aux;
    for(int i = 0; i< num ; i++){
        
        if(i==num-1) cout<< actual <<"\n";
        else cout<< actual <<" ";
        aux = actual;
        actual = actual+past;
        if(actual==0) actual = 1;
        past = aux;
        

    }
    return 0;
}