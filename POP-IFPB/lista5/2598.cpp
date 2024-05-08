#include <bits/stdc++.h>

using namespace std;



int main(){
    int test_case, avenida,radar, answer;
    cin >> test_case;
    while(test_case--!=0){
        cin >> avenida >> radar;
        answer=avenida/radar;
        if(avenida%radar!=0){
            answer+=1;
        }
        cout << answer << endl;
    }

    return 0;
}