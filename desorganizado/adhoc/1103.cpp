#include <bits/stdc++.h>

using namespace std;


int main(){
    int hd,md,ha,ma, answer = 0;
    cin>>hd>>md>>ha>>ma;
    while(hd+md+ha+ma!=0){
        answer=0;
        if((hd<=ha && md <= ma)){
            answer=(ha*60+ma)-(hd*60+md);
        }else if((hd>=ha && md >= ma)||(hd>=ha && md <= ma)){
            answer = (24*60)-(hd*60+md) + (ha*60+ma);
        }else if(hd<=ha && md >= ma){
            answer=(ha*60+ma)-(hd*60+md);
        }
        if(hd==ha && md == ma){
            answer = 60*24;
        }

        cout << answer << endl;
        cin>>hd>>md>>ha>>ma;
    }

    return 0;
}