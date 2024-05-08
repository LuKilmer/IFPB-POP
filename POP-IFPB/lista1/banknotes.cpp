#include <bits/stdc++.h>

using namespace std;

int main(){
    list<string> lista = {"100.00", "50.00", "20.00", "10.00", "5.00", "2.00", "1.00", "0.50", "0.25", "0.10", "0.05", "0.01"};
    double valor;
    cin >> valor;
    int centavos = round(valor * 100);
    cout << "NOTAS:" << endl;
    for(const string note: lista){
        int nota = stod(note)*100;

        if(nota==100) cout << "MOEDAS:"<<endl;

        if(nota > 100) cout << centavos/nota <<" nota(s) de R$ "<< note << endl;
        else cout << centavos/nota <<" moeda(s) de R$ "<< note << endl;
        centavos = centavos%nota;

    }




    return 0;
}