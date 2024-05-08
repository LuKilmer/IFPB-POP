#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int get_answer(vector<int>& pedras) {
    int n = pedras.size();
    vector<int> dp(n, 0);
    
    dp[0] = 0;
    dp[1] = abs(pedras[1] - pedras[0]);
    
    for (int i = 2; i < n; i++) {
        dp[i] = min(dp[i-1] + abs(pedras[i] - pedras[i-1]), dp[i-2] + abs(pedras[i] - pedras[i-2]));
    }
    
    return dp[n-1];
}

int main() {
    int n;
    cin >> n;
    
    vector<int> pedras(n);
    for (int i = 0; i < n; i++) {
        cin >> pedras[i];
    }
    
    int answer = get_answer(pedras);
    cout <<  answer << endl;
    
    return 0;
}
