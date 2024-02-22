#include <bits/stdc++.h>

using namespace std;


int main(){
    int test_case, con2;
    int contador = 0;
    double aux;
    double aux2;
    bool flag = 0;
    pair<int,int> dados;
    vector<pair<int,int>> lista;
    auto compareFunction = [](const pair<int, int>& a, const pair<int, int>& b) {
        return (a.second/a.first) < (b.second / b.first);
    };
    cin >> test_case;
    while(test_case!=0){
        contador++;
        aux=0;
        aux2=0;
        cout << "Cidade# "<< contador<< ":\n";
        lista.clear();
        while(test_case--!=0){
            cin >> dados.first >> dados.second;
            flag = 1;
            aux+=dados.second;
            aux2+=dados.first;
            //TODO: algoritmo que faz inserção e compara ao mesmo tempo
            for(int i = 0; i < lista.size(); i++){
                if(lista[i].second/lista[i].first == dados.second/dados.first){

                    //lista[i].second=(dados.second+lista[i].second)/(lista[i].first+dados.first);
                    lista[i].first = lista[i].first + dados.first;
                    lista[i].second = lista[i].second + dados.second;
                    flag=0;
                    break;
                }
            }
            if(flag)lista.push_back(dados);
            
        };
        
        sort(lista.begin(), lista.end(), compareFunction);
        
        for(int i=0; i < lista.size();i++){
            cout << fixed << setprecision(0) << lista[i].first<<"-"<<floor(lista[i].second/lista[i].first);
            if(i==lista.size()-1)cout << endl;
            else cout << " ";
        }
  
        cout << "Consumo medio: " << std::fixed << std::setprecision(2);

        string resultado = to_string(aux / aux2);
        con2 = 0;
        for(char let : resultado){
            if(let!='.') con2++;
            else break;
        }
        resultado = resultado.substr(0, con2+3);
        std::cout << resultado << " m3." << std::endl;

        cin >> test_case;
        cout << endl;
    }


    return 0;
}