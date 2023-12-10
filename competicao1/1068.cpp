#include <bits/stdc++.h>

using namespace std;

int main(){
    string entrada;
    int flag =0;
    bool answer=true;
    while(cin>>entrada){
        flag=0;
        for(int i=0; i < entrada.length();i++){
            if(entrada[i]=='(') flag++;
            else if(entrada[i]==')')flag--;
            if(flag<0){
                break;
            }
        }
        if(flag==0)cout << "correct" << endl;
        else cout << "incorrect" << endl;
    }


    return 0;
}