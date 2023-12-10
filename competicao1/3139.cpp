#include <bits/stdc++.h>

using namespace std;

int main(){
    double start, finalQuan, aux;
    double total = 0;
    cin >> start >> finalQuan;
    vector<int>mes;
    for(int i =0; i < 30;i++){
        cin >> aux;
        total += aux;
    }
    total = ceil(total/30);
    int contador = 0;
    
    while(finalQuan>=start){
        start+=total;
        contador++;
    }
    cout << contador << endl;


    return 0;
}