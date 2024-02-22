#include <bits/stdc++.h>

using namespace std;

int main(){
    double matriz[12][12];
    double total=0;
    char operation;
    cin >> operation;
    int quantity=0;
    for(int i = 0; i < 12; i++){
        for(int j = 0; j < 12; j++){
            cin >> matriz[i][j];
            if(j>i){
            total+=matriz[i][j];
            quantity+=1;
            }
        }
    }
    if(operation == 'M') cout << fixed << setprecision(1) <<total/quantity << endl;
    else cout<< total<< endl;

    
    return 0;
}