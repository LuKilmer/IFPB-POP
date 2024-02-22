#include <bits/stdc++.h>

using namespace std;

int main(){
    string calopeira;
    int contador,test_case;
    bool flag; 
    cin>> test_case;
    for(int i=0; i < test_case; i++){
        cin >> calopeira;
        contador = 0;
        flag=false;
        for(char letter:calopeira){
            if(letter=='i') flag = !flag;
            if(flag)contador++;
            if(letter=='p') flag = !flag;
        }
        cout << fixed<< setprecision(2) << 0.01*contador + 0.08 << endl;
    }



    return 0;
}