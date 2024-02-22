#include <bits/stdc++.h>

using namespace std;

int main(){
    size_t maxSize = SIZE_MAX;
    std::cout << "Tamanho máximo do array em bytes: " << maxSize << std::endl;
    int value,aux, contador, strike,answer;
    while(cin>> value){
        contador=1;
        if(value%2==0){
            aux = (value/2);
        }else{
            aux= (value+1)/2;
        }
        
        for(int i = 1; i <= aux;i++){
           
            strike=0;
            for(int j = i; j <= aux; j++){
                if(j+strike>value){
                    break;
                }
                if(j+strike==value){
                  contador++;
                }else{
                    strike+=j;
                }
            }
        }
        if(value==1)cout<<1<<endl;
        else cout << contador << endl;
        
    }
}