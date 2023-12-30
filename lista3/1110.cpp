#include <bits/stdc++.h>

using namespace std;

int main(){
    int entrada, aux;
    int lastone;
    queue<int> deck;
    cin>>entrada;
    while(entrada!=0){
        
        for(int i = 1; i <= entrada; i++) deck.push(i);
        cout << "Discarded cards:";
        while(deck.size()!=1){
            cout << " "<<deck.front();
            deck.pop();
            deck.push(deck.front());
            deck.pop();
            if(deck.size()!=1)cout <<",";
            
        }
        cout << "\n";
        cout <<"Remaining card: "<<deck.front() << endl;
        deck.pop();
        cin>>entrada;
    }
    
    return 0;
    
}