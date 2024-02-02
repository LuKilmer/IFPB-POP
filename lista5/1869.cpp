#include <bits/stdc++.h>

using namespace std;


string base32(unsigned long long num){
    vector<char> digitos {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F','G','H','I','J', 'K','L','M','N','O','P','Q','R','S','T','U','V'};
    string answer;
    while(num!=0){
        answer.push_back(digitos[num%32]);
       
        num/=32;
    }
    reverse(answer.begin(),answer.end());
    return answer;
}


int main(){
    unsigned long long num;
    cin>> num;
    while(num!=0){
        cout << base32(num)<<endl;
        cin >> num;
    }
    cout << 0 << endl;



    return 0;
}