#include <iostream>
#include <vector>
#include <cmath>
#include <climits>
using namespace std;

int get_answer(vector<int>& pedras, int m) {
    int n = pedras.size();
    vector<int> dp(n, INT_MAX);
    dp[0] = 0;
 
    for (int i = 1; i < n; i++) {
        for (int j = 1; j <= m ; j++) {
            if(i-j>=0){
                dp[i] = min(dp[i], dp[i-j] + abs(pedras[i] - pedras[i-j]));
            }else{
                break;
            }
            
        }
    }
    
    return dp[n-1];
}

int main() {
    int n, m;
    cin >> n >> m; 
    
    vector<int> pedras(n);
    for (int i = 0; i < n; i++) {
        cin >> pedras[i];
    }
    
    int answer = get_answer(pedras, m);
    cout << answer << endl;
    
    return 0;
}
