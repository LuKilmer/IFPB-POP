#include <bits/stdc++.h>

using namespace std;

int main(){
    string entrada, aux;
    
    vector<char>numbers = {'0','1','2','3','4','5','6','7','8','9'};
    int total = 0;
    while(cin>>entrada){
        aux="";
        for(char i: entrada){
            if(count(numbers.begin(), numbers.end(), i)){
                aux+=i;
                break;
            }
        }
        reverse(entrada.begin(),entrada.end());
        for(char i: entrada){
            if(count(numbers.begin(), numbers.end(), i)){
                aux+=i;
                break;
            }
        }
        total+=stoi(aux);
    }
    cout << total << endl;
    return 0;
}