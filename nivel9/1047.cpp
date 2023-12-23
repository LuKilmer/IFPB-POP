#include <bits/stdc++.h>

using namespace std;

int main(){
    pair<int , int> end, inicial, result;
    int total_end, total_inic, total_result;
    cin >> inicial.first  >> inicial.second  >> end.first >> end.second;
    total_end = end.first * 60 + end.second;
    total_inic = inicial.first * 60 + inicial.second;
    if(total_end==total_inic){
        total_result=24*60;
    }else if(total_end<total_inic){
        total_result =  total_end + 60*24 - total_inic;
    }else{
        total_result = total_end - total_inic;
    };
    cout << "O JOGO DUROU "<<int(total_result/60)<<" HORA(S) E "<< total_result%60<<" MINUTO(S)"<<endl;
    
    return 0;
}