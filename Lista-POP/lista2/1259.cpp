#include <bits/stdc++.h>

using namespace std;

int main(){
    int teste_case;
    vector<int>par;
    vector<int>impar;
    cin >> teste_case;
    int aux;
    for(size_t i =0; i< teste_case;i++){
        cin >> aux;
        if(aux%2==0){
            par.push_back(aux);
        }
        else{
            impar.push_back(aux);
        }
    }
    sort(par.begin(), par.begin()+par.size()); 
    sort(impar.begin(), impar.begin()+impar.size()); 
    for(auto &n: par){
        cout << n << endl;
    }
    for(size_t i =0; i < impar.size();i++){
        cout << impar[impar.size()-1-i] << endl;
    }

    
    return 0;
}