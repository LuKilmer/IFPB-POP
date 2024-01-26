#include <bits/stdc++.h>

using namespace std;



void showData(vector<int> aux){
    cout << "=========================="<<endl;
    for(int a : aux){
        cout << a << endl;
    }

}

int melhorpreco(vector<int>& preco, vector<int>& comprimento, int limite) {
    int n = preco.size();
    vector<int> aux(limite + 1, 0);

    for (int i = 1; i <= limite; i++) {
        for (int j = 0; j < n; j++) {
            if (comprimento[j] <= i) {
                //verifica se o atual valor que está em i é maior que o valor do comprimento que está em i menos o comprimento do index de j,
                //acumula as sobras
                aux[i] = max(aux[i], aux[i - comprimento[j]] + preco[j]);
            }
        }
    }
 
    return aux[limite];
}

int main() {
    vector<int> preco;
    vector<int> comprimento;
    pair<int,int> aux;
    int n, limite;
    cin >> n >> limite;
    for(int i =0; i< n; i++){
        cin >> aux.first >> aux.second;
        if(aux.first<=limite){
            comprimento.push_back(aux.first);
            preco.push_back(aux.second);
        }
    }
    ;
    cout << melhorpreco(preco, comprimento, limite) << endl;

    return 0;
}
