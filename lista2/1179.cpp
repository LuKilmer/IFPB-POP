#include <bits/stdc++.h>

using namespace std;

int main(){
    vector<int>par;
    vector<int>impar;
    int aux;
    for(int i=0;i < 15;i++){
        cin >> aux;
        if(aux%2==0){
            if(par.size()==5){
                for(size_t j=0; j< 5;j++){
                    cout << "par["<<j<<"] = "<< par[j]<<endl;  
                    par.pop_back(); 
                }
            }
            par.push_back(aux);
        }else{
            if(impar.size()==5){
                for(size_t j=0; j< 5;j++){
                    cout << "impar["<<j<<"] = "<< impar[j]<<endl;   
                    impar.pop_back();
                }
            }
            impar.push_back(aux);
        }
    }
    for(size_t j=0; j< impar.size();j++){
        cout << "impar["<<j<<"] = "<< impar[j]<<endl;   
    }
    for(size_t j=0; j< par.size();j++){
        cout << "par["<<j<<"] = "<< par[j]<<endl;  
    }
    return 0;
}