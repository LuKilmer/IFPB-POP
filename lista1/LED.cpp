#include <bits/stdc++.h>

using namespace std;

int main(){
    int test_case;
    map<char, int> number_leds = {
        {'0',6},
        {'1',2},
        {'2',5},
        {'3',5},
        {'4',4},
        {'5',5},
        {'6',6},
        {'7',3},
        {'8',7},
        {'9',6}};
    int answer;
    string inputs;
    cin >> test_case;
    while(test_case!=0){
        cin >> inputs;
        for(char letter: inputs){
            answer+=number_leds[letter];
        }
        printf("%d leds\n", answer);
        answer = 0;
        test_case-=1;
    }
    return 0;
}