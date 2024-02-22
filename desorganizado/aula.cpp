#include <bits/stdc++.h>

using namespace std;


int main(){
    string input; 
    getline(cin, input);
    int array[10];  
    stringstream ss(input);
    int aux;
    for (int i = 0; i < 10 && ss >> aux; ++i) {
        array[i] = aux;
    }
    
    int finded ;
    bool flag = 0;
    for(int i = 0; i <3 ; i++ ){
        cin >> finded;
        flag = false;
        for(int j= 0; j<10 ; j++){
            if(array[j]==finded){
                cout << j+1 << endl;
                flag = 1;
                break;
            }
        }
        if(flag == 0){
            cout << "Não existe na lista\n";
        }
    }

    return 0;
}