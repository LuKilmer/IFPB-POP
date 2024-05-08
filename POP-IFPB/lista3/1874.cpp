#include <bits/stdc++.h>

using namespace std;

int main(){
    int size[3];
    vector<int>aux;
    vector<int>more;
    int number;
    cin >> size[0] >> size[1] >> size[2];
    cout << size[0] << size[1] << size[2]<< endl;
    while((size[0]+size[1]+size[2])>0){
        vector<vector<int>>matriz;
        matriz.clear();
        for(int i=0; i < size[0]; i++){
            aux.clear();
            for(int j=0; j < size[1]; j++){
                cin >> number;
                aux.push_back(number);
            }
            matriz.push_back(aux);
        }
        for(int i=0; i < size[2];i++){
            cin>>number;
            more.push_back(number);
        }
        //set answer
        for(int i=size[0]-1; i >-1; i--){
            for(int j=size[1]-1; j >-1; j--){
                if (matriz[i][j]==0){
                    matriz[i][j]=more[0]; 
                }
            }
        }
        for(int i=0; i < size[0]; i++){
            for(int j=0; j < size[1]; j++){
                cout << matriz[i][j] << " ";
            }
            cout << endl;
        }
        
        
        cin >> size[0] >> size[1] >> size[2];
    }
    return 0;
}