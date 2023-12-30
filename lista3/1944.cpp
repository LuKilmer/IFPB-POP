#include <bits/stdc++.h>

using namespace std;

int main(){
    int test_case, answer, flag;
    string total, aux;
    string l1,l2,l3,l4;
    cin >> test_case;
    while(test_case!=0){ 
        cin >> l1 >> l2 >> l3 >> l4;
        aux= l1+l2+l3+l4;
        
        if(total.length()==0){
            total+="FACE";
        }
        flag=0;
        for(int i=1; i <= 4;i++){
            if(aux[i-1]==total[total.length()-i]){
                flag++;
            }else{
                break;
            }
        }
        if(flag==4){
            answer++;
            total=total.substr(0,total.length()-4);
            if(total.length()==0){
                total+="FACE";
            }   
        }else{
            total+=aux;
        }   
        test_case--;
    }
    cout << answer << endl;
    return 0;
}

//F A C E E C F A A C F E A C E F
//F A C E E C F A A C F E 