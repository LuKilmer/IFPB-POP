#include <bits/stdc++.h>

using namespace std;


struct menu{
        string nome;
        double preco;
    };


int main(){
    int teste_case;
    int couter;
    menu aux;
    cin >> teste_case;
    double total=0;
    for(int i=0; i < teste_case; i++){
        cin >> couter;
        total=0;
        map<string,double> cardapio;
        vector<menu> sacola;
        while(couter!=0){
            cin >>aux.nome >> aux.preco;
            cardapio.insert(make_pair(aux.nome, aux.preco));
            couter--;
        }
        cin >> couter;
        while(couter!=0){
            cin >>aux.nome >> aux.preco;
            sacola.push_back(aux);
            couter--;
        }
        for(size_t i=0; i < sacola.size();i++){
            total+=cardapio[sacola[i].nome]*sacola[i].preco;
        }
        cout << fixed << setprecision(2) <<"R$ "<<total << endl;
    }

    return 0;
}