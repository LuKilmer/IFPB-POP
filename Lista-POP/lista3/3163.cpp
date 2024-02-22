#include <bits/stdc++.h>

using namespace std;

int main(){
    string entrada;
    queue<string> answer;
    queue<string> norte;
    queue<string> sul;
    queue<string> oeste;
    queue<string> leste;
    cin>>entrada;
    while(true){
        if(entrada=="0"){
            break;
        }else if(entrada=="-1"){
            while(cin >> entrada){
                if(entrada[0]!='A')break;
                oeste.push(entrada);
            }
        }else if(entrada=="-2"){
            while(cin >> entrada){
                if(entrada[0]!='A')break;
                sul.push(entrada);
            }
        }else if(entrada=="-3"){
            while(cin >> entrada){
                if(entrada[0]!='A')break;
                norte.push(entrada);
            }
        }else if(entrada=="-4"){
            while(cin >> entrada){
                if(entrada[0]!='A')break;
                leste.push(entrada);
            }
        }
    }
    while(!leste.empty() or !oeste.empty() or !norte.empty() or !sul.empty()){
        if(!oeste.empty()){answer.push(oeste.front());oeste.pop();}
        if(!norte.empty()){answer.push(norte.front());norte.pop();}
        if(!sul.empty()){answer.push(sul.front());sul.pop();}
        if(!leste.empty()){answer.push(leste.front());leste.pop();}
    }

    while(!answer.empty()){
        if(answer.size()==1) cout << answer.front()<< endl;
        else cout << answer.front() << " ";
        answer.pop();
    }
    return 0;
    //-1 -3 -2 -4
    //80 20 2 1 40 
    // -1 oeste primeiro, -3 norte e  -2 sul revesados, -4 lest por ultimo
}