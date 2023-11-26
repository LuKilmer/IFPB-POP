#include <bits/stdc++.h>

using namespace std;

int main(){
    int num1, num2;
    long long int num1_result =1;
    long long int num2_result =1;
    int count = 1;
    while(cin >> num1 >> num2){
        count=1;
        num1_result =1;
        num2_result =1;
        while(count<=num1 or count<=num2){
            //cout << num1<<" "<< num2<<" "<<count <<endl;
            //cout << num1_result<<" "<< num2_result<< endl;
            if(count<=num1){
                num1_result*=count;
            }
            if(count<=num2){
                num2_result*=count;
            }
            count++;
        }
        cout << num1_result+ num2_result<< endl;
    }
    
    return 0;
}