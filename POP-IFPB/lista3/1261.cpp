#include <bits/stdc++.h>

using namespace std;

int main(){
    map<string,double> cargos;
    pair<string,double> sup;
    string entrada;
    int num_cargo, num_empr;
    double total;
    cin >> num_cargo >> num_empr;
    for(int i =0;i<num_cargo; i++){
        cin>> sup.first >> sup.second;
        cargos.insert(sup);
    }
    for(int i=0;i<num_empr;i++){
        total=0;
        while(cin>>entrada){
            if(entrada=="."){
                break;
            }
            for(auto &aux:cargos){
                if(entrada==aux.first){
                    total+=aux.second;
                }
            }
        }
        cout << static_cast<long long>(total) << endl;
    }
    
    return 0;
}