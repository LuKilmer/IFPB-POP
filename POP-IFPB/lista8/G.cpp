#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

int coins_type[] = {1,5,10,25, 50};

int get_answer(int coin){
    
    vector<int>sup(coin+1,0);
    sup[0]=1;
    for(int coin_type: coins_type){
        for(int i= coin_type; i <= coin; i++){
            sup[i] += sup[i-coin_type];
        }
    }

    return sup[coin];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ofstream outputFile("answer.txt");
    vector<int> coins;
    int entrada;
    while(cin>>entrada){
        coins.push_back(entrada);
    }
    for(int coin: coins ){
        cout << get_answer(coin) << endl;
    }

}