#include <bits/stdc++.h>

using namespace std;

int possible_answer(){
    int answer, index=0;
    string bina;
    cin>> answer;
    cin >> bina;

    while(bina.size()-1-index>index){
        if((bina[bina.size()-1-index]=='0' && bina[index]=='1')||(bina[bina.size()-1-index]=='1' && bina[index]=='0')){
            answer = answer-2;
        }else{
            break;
        }
        index++;
    }
    
    return answer;
}


int main(){
    int test_case;
    cin >> test_case;
    while(test_case--){
        cout << possible_answer() << endl;
    }
    return 0;
}