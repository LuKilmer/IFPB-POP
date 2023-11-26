#include <bits/stdc++.h>

using namespace std;

int main(){
    map<string, int> grupos = {{"bonecos",8}, {"arquitetos",4}, {"musicos",6},{"desenhistas",12}}; 
    map<string, int> extra_grupos = {{"bonecos",0}, {"arquitetos",0}, {"musicos",0},{"desenhistas",0}}; 
    int teste_case;
    string nome;
    string grupo;
    int horario;
    cin >> teste_case;
    int answer = 0;
    while(teste_case>0){
        cin >> nome >> grupo >> horario;
        extra_grupos[grupo] += horario;
        teste_case--;
    }
    for (auto &n: grupos) { 
        answer+= extra_grupos[n.first]/grupos[n.first];
    }
    cout << answer << endl;

    return 0;
}