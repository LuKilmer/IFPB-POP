#include <bits/stdc++.h>

using namespace std;

int first_try(const vector<int>& days, int limit) {
    int aux=0;int bigger = 0;
    for (int i = 0; i < days.size(); i++) {
        for (int j = i ; j <= days.size(); j++) {
      
            aux = 0;
            for (int w = i; w < j; w++) {aux += days[w];}
            aux= aux + limit*(j-i)*-1;
            if (aux > bigger) {
                bigger = aux;
            }
        }
    }
    return bigger;
}
int second_try(const vector<int>& days, int limit){
    
    int maxSumSoFar=0;
    for(int i=0; i<days.size(); i++){
        int aux=0;
        for(int j=i; j<days.size(); j++){
            aux+=days[j];
            aux-=limit;
            if(aux>maxSumSoFar){
                maxSumSoFar=aux;

            }
        }
}
    return maxSumSoFar;

}
int main(int argc, char *argv[]){
    int test_case,aux, limit;
  
    while(cin>>test_case){
        cin >> limit;
        vector<int> days(test_case);

        for (int i = 0; i < test_case; i++) {
            cin >> aux;
            days[i] = aux;
        }
        cout << second_try(days, limit) << endl;
    }
    
    return 0;
}