#include <bits/stdc++.h>


using namespace std;


int main(){
    int test_case;
    cin>>test_case;
    while(test_case--){
        int array_size; 
        cin>>array_size;

        vector<int> procaria(array_size); 
        for(int i=0;i<array_size;i++){
            cin>>procaria[i];
        } 
        int i=1;
        while(procaria[i]<=procaria[i-1] && i<array_size){
            i++;
        } 
        while(procaria[i]>=procaria[i-1] && i<array_size){
            i++;
        } 
        if(i==array_size){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }
        
    }
    return 0;
}