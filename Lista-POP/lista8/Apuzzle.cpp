#include <iostream>
#include <vector>

using namespace std;

int main(){
    int t;
    int n;
    cin >> t;
    n = t;
    while(t--){
        vector<int> answers;
        for(int i = 1; i <= n; i++){
            int num;
            cin >> num;
           
            if(num == 1){
                answers.push_back(i);
            }
        }
        
        
        for(int j = 0; j < answers.size(); j++){
            if(j == answers.size() - 1){
                cout << answers[j] << endl;
            }else{
                cout << answers[j] << " ";
            }
        }
    }

    return 0;
}
