#include <bits/stdc++.h>

using namespace std;

int main() {
    while (true) {
        int largura, altura, vetor_inserido, aux;
        cin >> largura >> altura >> vetor_inserido;
        queue<int> vetor_extra;

        if (largura == 0 || altura == 0 || vetor_inserido == 0) {
            break;
        }


        vector<vector<int>> matriz(largura, vector<int>(altura, 0));  // Inicializa a matriz com zeros

        for (int j = 0; j < largura; j++) {
            for (int i = 0; i < altura; i++) {
                cin >> aux;
                matriz[j][i] = aux;
            }
        }

        for (int i = 0; i < vetor_inserido; i++) {
            cin >> aux;
            vetor_extra.push(aux);
        }


    
        for (int j = altura-1; j >= 0; j--) {
            for (int i = largura-1; i >=0 ; i--) {
                if(vetor_extra.size()==0)break;
                if(matriz[i][j]==0){
                    matriz[i][j]=vetor_extra.front();
                    vetor_extra.pop();
                }
            }
            if(vetor_extra.size()==0)break;
        }
        for (int j = 0; j < largura; j++) {
            for (int i = 0; i < altura; i++) {
                cout << matriz[j][i];
                if(i!=altura-1)cout << " ";
                else cout << endl;
            }
        
        }
      
        

    }

    return 0;
}
