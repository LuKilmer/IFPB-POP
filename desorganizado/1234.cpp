#include <bits/stdc++.h>

using namespace std;

int main(){
    string input;
    bool aux = 0;
    while (getline(cin, input)) {
        aux = 1;
        
        for(char& letter: input){
            if(letter == ' ' or isdigit(letter)){
                cout << letter;
            }else{
                if(aux){
                    letter=toupper(letter);
                    cout << letter;
                    aux=0;
                }else{
                    aux=1;
                    letter=tolower(letter);
                    cout << letter;
                }
            }
        }
        cout << endl;
        
    }
    return 0;
}