#include <bits/stdc++.h>

using namespace std;

int main(){
    int num, total=0;
    int mars_distance = 60000000;
    bool isPrime;
    int flag = 0;
    cin >> num;
    while(flag!=10){
        
        isPrime=true;
        for(int i = 2 ; i <= num/2;i++){
            if(num%i==0){
                isPrime=false;
                break;
            }
        }
        if(isPrime==true){
            cout << flag << " "<< num << endl;
            total+=num;
            flag++;
        }
        num++;
    }
    cout << total <<" km/h"<< endl;
    cout << mars_distance/total << " h / "<< (mars_distance/total)/24<<" d"<< endl;
    
    return 0;
}