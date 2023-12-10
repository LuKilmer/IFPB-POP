#include <bits/stdc++.h>

using namespace std;

int main(){
    vector<int>cartela;
    vector<int>loteria;
    int aux;
    int total=0;
    for(int i=0; i< 6; i++){
        cin>>aux;
        cartela.push_back(aux);
    }
    for(int i=0; i< 6; i++){
        cin>>aux;
        loteria.push_back(aux);
    }
    for(int i=0; i<6; i++){
        if ( find(loteria.begin(), loteria.end(), cartela[i]) != loteria.end() )total++;
    }
    if(total < 3) cout << "azar" << endl;
    else if(total==3) cout << "terno" << endl;
    else if(total==4)   cout << "quadra" << endl;
    else if(total==5)   cout << "quina" << endl;
    else if(total==6)   cout << "sena" << endl;
 
    return 0;
}