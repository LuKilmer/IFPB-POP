#include <bits/stdc++.h>

using namespace std;

int main(){
    int size[3];
    vector<int>aux, ssup;
    vector<int>more;
    int number;
    int cont = 1;
    cin >> size[0] >> size[1] >> size[2];
    while(cont!=0){
        vector<vector<int>>matriz;
        matriz.clear();
        for(int i=0; i < size[1];i++){matriz.push_back(ssup);}
        for(int i=0; i < size[0]*size[1]; i++){
            cin >> number;
            aux.push_back(number);
        }
        for(int i=0; i < size[2];i++){cin>>number;more.push_back(number);}
        for(int i =0 ; i < aux.size();i++){
            cout << aux[i];
        }
        cout << endl;
        cont=5;
        for(int i = 0; i < size[1]; i++){
            for(int j=0; j< size[0]; j++){
                matriz[i].push_back(aux[j*cont]);
            }
            cont++;
        }
        for(int i = 0; i < size[1]; i++){
            for(int top: matriz[i]){
                cout << top << " ";
            }
            cout << endl;
        }
        


        cont = 0;
        cin >> size[0] >> size[1] >> size[2];
    }
    return 0;
}
//10001101011111111111
//11111111111
//0-5-10-15