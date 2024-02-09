#include <bits/stdc++.h>

using namespace std;

void prime_factors( int x ){
    while( x % 2 == 0){
        cout << 2 << endl;
        x/=2;
    }
    for(int i = 3 ; i % i <= x; i+=2){
        while(x%i==0){
            cout << i << endl;
            x/=i;
        }
        if(x!=1) cout << i << endl;
        else cout << endl;
    }
    
}



int main(){
    cout << gcd(8,2)<<endl;

    cout << lcm(8,2)<< endl;
    return 0;
}