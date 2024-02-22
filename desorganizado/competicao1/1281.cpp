#include <bits/stdc++.h>

using namespace std;

int main(){
    int test_case,quant;
    double total=0;
    map<string,double>cardapio;
    cin >> test_case;
    pair<string, double>produto;
    pair<string, int>comprado;
    while(test_case!=0){
        cardapio={};
        total=0;
        cin>>quant;
        for(int i = 0; i< quant;i++){
            cin>> produto.first>>produto.second;
            cardapio.insert(make_pair(produto.first,produto.second));
        }
        cin>>quant;
        for(int i = 0; i< quant;i++){
            cin>> comprado.first>>comprado.second;
            total+=(cardapio[comprado.first]*comprado.second);
        }
        cout <<"R$ "<< fixed << setprecision(2) << total << endl;
        test_case--;
    }

    return 0;
}