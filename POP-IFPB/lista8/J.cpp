#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

int get_answer(int coin, vector<int>coins_type){
    vector<int>aux(coin+1,0);
    aux[0]=1;
    for(int coin_type: coins_type){
        for(int i= coin_type; i <= coin; ++i){
            aux[i] += aux[i-coin_type];
            aux[i] %= 1000000007;
        }
    }
    return aux[coin];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ofstream outputFile("answer.txt");
    int n, m;
    cin >>n >> m;
    vector<int>coins_type(n);
    for(int i=0; i < n; i++){
        cin >> coins_type[i];
    }
    cout << get_answer(m, coins_type) << endl;
}