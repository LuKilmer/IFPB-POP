#include <bits/stdc++.h>

using namespace std;

int main(){
    int hora_posicao=0;
    int minuto_posicao=0;
    int count;
    int hora_cout=0;
    int aux;
    int find_value;
    bool flag;
    while(cin>>find_value){
        hora_posicao=0;
        minuto_posicao=0;
        count = 720;
        flag = false;
        while(count >=0){
            if(hora_cout==12){
                 hora_posicao++; 
                 hora_cout=1;
            }else{
                hora_cout++;
            } 
            if(minuto_posicao==60)minuto_posicao=0;
            minuto_posicao++;
            if (minuto_posicao > hora_posicao) aux = minuto_posicao - hora_posicao;
            else aux = hora_posicao - minuto_posicao;
            if(aux*6 == find_value){
                //cout <<hora_posicao << " "<< minuto_posicao <<endl;
                flag=true;
                break;
            }
            count--;
        }
        if(flag)cout<<"Y"<<endl;
        else cout<<"N"<<endl;
        
    }
    return 0;
}