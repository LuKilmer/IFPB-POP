#include <bits/stdc++.h>

using namespace std;

void show(vector<int> &livros){
    for (int aux : livros){
        cout << aux << " ";
    }
    cout << endl;
}

int get_answer(vector<int> &oarray){
    int answer = 0;
    int ponteirobaixo = 0, ponteiroalto = oarray.size()-1;
    while(ponteirobaixo < ponteiroalto){
        if(oarray[ponteirobaixo]==1 && oarray[ponteiroalto]==0){
            oarray[ponteirobaixo]=0;
            oarray[ponteiroalto]=1;
            ponteiroalto--;
            ponteirobaixo++;
            answer++;
        } else {
            if(oarray[ponteirobaixo]==0){
                ponteirobaixo++;
            }
            if(oarray[ponteiroalto]==1){
                ponteiroalto--;
            }
        }
    }

    return answer;
}


int main(){
    int test_case, array_size, contador;
    cin >> test_case;
    while(test_case--){
        cin >> array_size;
        contador = 0;
        vector<int> oarray(array_size);
        while(contador < array_size){
            cin >> oarray[contador];
            contador++;
        }

        cout << get_answer(oarray) << endl;

    }
    return 0;
}