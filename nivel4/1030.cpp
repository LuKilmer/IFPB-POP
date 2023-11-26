#include <bits/stdc++.h>

using namespace std;

int main(){
    int num = 5;
    int jump = 2;
    vector<int> array;
    for(int i = 0; i < num; i++){
        array.push_back(i+1);
    }
    int contador = 1;
    size_t pointer = 0;
    bool flag = true;
    while(flag){
        cout << size(array) << endl;
        cout << pointer << " "<< contador << " " << array[pointer] << endl;
        if(contador==jump){
            
            array.erase(array.begin() + pointer);
            contador = 1;
        }else{contador++;}
        if(pointer==size(array)-1){
            pointer=0;
        }else if(size(array)==1){
            cout << "acabou\n";
            break;
        }else{
            pointer++;
        }
    }
    cout << array[0] << endl;


    return 0;
}