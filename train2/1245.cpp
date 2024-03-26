#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <iomanip>      // std::setprecision
using namespace std;
 
int main() {
    int test_case, answer;
    string sup, sup2;
    
    while(cin >> test_case){
        map<string, int> calsados;
        for(int i=30; i <= 60; i++){
            calsados.insert(make_pair(to_string(i)+"E", 0));
            calsados.insert(make_pair(to_string(i)+"D", 0));
        }
        answer = 0;
        while(test_case--){
            cin >> sup >> sup2;
            if(sup2=="D"){
                if(calsados[sup+"E"]>0){
                    answer++;
                    calsados[sup+"E"]-=1;
                }else{
                    calsados[sup+"D"]+=1;
                }
            }else{
                if(calsados[sup+"D"]>0){
                    answer++;
                    calsados[sup+"D"]-=1;
                }else{
                    calsados[sup+"E"]+=1;
                }
            }
        }    
        cout << answer << endl;
    }
    
   
    
 
    return 0;
}