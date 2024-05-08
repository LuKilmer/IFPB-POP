#include <bits/stdc++.h>

using namespace std;

struct entrada
{
   int num1;
   int num2;
   int sup;
};

int main(){
    entrada aux;
    cin >> aux.num1 >> aux.num2;
    int total=0;
    while(aux.num1>0 and aux.num2>0){
        total=0;
        if (aux.num1>aux.num2){
            aux.sup = aux.num2;
            aux.num2=aux.num1;
            aux.num1=aux.sup;
        }
       
        for(int i=aux.num1; i <= aux.num2;i++){
            cout<<i<<" ";
            total+=i;
        }
        cout << "Sum="<<total<<endl;
        cin >> aux.num1 >> aux.num2;
    }
    return 0;
}