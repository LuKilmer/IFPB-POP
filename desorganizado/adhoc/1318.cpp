#include <bits/stdc++.h>

using namespace std;

int main(){

    int  pessoas, limit, num = 0, answer;
    bool flag;
    cin>>limit >> pessoas;
    while( pessoas != 0){
        answer= 0;
        vector<pair<int,bool>>ingressos;
        for(int i=0 ; i < pessoas; i++){
            cin >> num;
            //cout << num;
            if(num<=limit){
                flag=true;
                for(int i = 0; i < ingressos.size(); i++){
                    if(ingressos[i].first==num){
                        flag=false;
                        //cout << ingressos[i].first << ingressos[i].second << endl;
                        if(!ingressos[i].second){

                            //cout << ingressos[i].first << ingressos[i].second << endl;
                            ingressos[i].second=true;
                            answer++;
                        }
                        break;
                    }
                }
                if(flag){
                    pair<int,bool> aux = {num, false};
                    ingressos.push_back(aux);
                }
            }
        }
       cout << answer << endl;
        
        cin>>limit >> pessoas;
    }

    return 0;
}