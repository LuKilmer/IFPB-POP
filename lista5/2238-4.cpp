#include <bits/stdc++.h>

using namespace std;

bool check(int a,int  b,int c,int d,int n){
    return n%a ==0 && n % b != 0 && c % n == 0 && d % n != 0;
}

int main()
{
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    pair<bool,bool>flag;
    int answer = c+1;
    for (int i = 1; i <= sqrt(c)+1; i++){
        if(c%i==0 ){
            
            flag.first=check(a,b,c,d,i);
            flag.second=check(a,b,c,d,c/i);
            if(flag.first&&flag.second){
                if(i<answer || c/i < answer){
                    answer = min(i,c/i);     
                }
            }else if(flag.first){
                if(i<answer){
                    answer = i;
                }
                
            }
            else if(flag.second){   
                if(c/i<answer){

                answer = c/i;
                } 
            }
        }
    }
    if(answer== c+1)cout << -1 << endl;
    else cout << answer << endl;
    
    return 0;
}