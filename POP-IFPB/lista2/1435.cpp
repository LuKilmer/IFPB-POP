#include <bits/stdc++.h>

using namespace std;

int main(){
    int entrada,aux,limit;
    cin >> entrada;
    bool flag,flag1;
    while(entrada!=0){
        limit=1;flag=true;
        for(int i =0; i < entrada;i++){
            cout << setw(3);
            aux=1;flag1= true;
            for(int j =0; j< entrada;j++){
                cout << aux<<setw(4);
                if(entrada-j==limit)flag1=false;
                if(aux<limit and flag1==true)aux++;
                if(!flag1)aux--;
            }
            if(flag) limit++;
            else limit--;
            if(i==floor(entrada/2)-1){
                if(entrada%2==0 and flag==true) limit--;
                flag=false;
            }
            cout << endl;
        }
        cin >> entrada;
        cout << endl;
    }
    return 0;
}