#include <iostream>
#include <vector>
#include <cmath>
#include <climits>

using namespace std;

struct dia{
    int op1;
    int op2;
    int op3;
} dias;
//0 - 1 2
//1 - 0 2
//2 - 0 1

int get_answer(vector<dia> dias){
    int n = dias.size();
    vector<vector<int>> dp(n + 1, vector<int>(3, 0));
    dp[1][0] = dias[0].op1;
    dp[1][1] = dias[0].op2;
    dp[1][2] = dias[0].op3;

    for(int i=2; i <= n; i++){
        dp[i][0] = max(dp[i-1][1] + dias[i-1].op1, dp[i-1][2] +dias[i-1].op1);
        dp[i][1] = max(dp[i-1][0] + dias[i-1].op2, dp[i-1][2] +dias[i-1].op2);
        dp[i][2] = max(dp[i-1][0] + dias[i-1].op3, dp[i-1][1] +dias[i-1].op3);
    }
    return max(max(dp[n][0], dp[n][1]), dp[n][2]);
}

int main(){
    int n;
    cin >> n;
    dia aux;
    aux.op1 = aux.op2 = aux.op3 = 0;
    vector<dia> dias(n, aux);
    for(int i = 0; i < n ; i++){
        cin >> dias[i].op1 >> dias[i].op2 >> dias[i].op3;
    }
    int answer = get_answer(dias);
    cout << answer << endl;
    return 0;
}