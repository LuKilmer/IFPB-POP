#include <bits/stdc++.h>

using namespace std;

int nextStep(vector<int>&vetor , int ponteiro){
    while(true){

        if(vetor[ponteiro]==0){
            if(ponteiro+1<=vetor.size()-1){
                ponteiro++;
            }else{
                ponteiro=1;
            }
        }else{
            cout << vetor[ponteiro] <<" steped "<< ponteiro << endl;
            vetor[ponteiro]=0;
            break;
        }
    }

    return ponteiro;
}


int main(){
    int num, ponteiro, base, contador;
    cin >> num;
    vector<int> vetor;for(int i=0; i<=num;i++){vetor.push_back(i);}
    contador = 0;
    base= 5;
    ponteiro = 1;
    while(contador!=num-1){
        if(vetor[ponteiro]!=0){
            cout << vetor[ponteiro] << " " << ponteiro << " "<< base<< endl;
            vetor[ponteiro]=0;
        }else{
            ponteiro = nextStep(vetor, ponteiro);
        }
        if(ponteiro==num){
            base+=2;
            ponteiro=base;
        }else if(ponteiro+base<num){
            ponteiro+=base;
        }else{
            base+=2;
            ponteiro=base-(num-ponteiro);
        }
        contador++;
    }
    for(int i=1; i<=num;i++){
        if(vetor[i]!=0){
            cout << vetor[i]<<endl;
        }
    }
    return 0;
}