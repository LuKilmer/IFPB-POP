#include <bits/stdc++.h>

using namespace std;

bool checkPrime(int num) {
      if(num <= 1) return false;
      if (num <= 3)  return true; 

      int max_number = sqrt(num);
      if (num % 2 == 0 || num % 3 == 0) 
         return false; 

      if (num%max_number == 0){
         return false;
      }

      for (int i = 5; i < max_number; i += 6) 
         if (num % i == 0 || num % (i + 2) == 0) 
            return false; 
        
      return true;
    }

int main(){
    //otimização....
    map<char,bool>checks = {{'0',0},{'1',0},{'2',1},{'3',1},{'4',0},{'5',1},{'6',0},{'7',1},{'8',0},{'9',0}};
    int num;
    bool flag;
    string aux;
    while(cin >> num){
        if(checkPrime(num)){
            aux = to_string(num);
            flag=1;
            for(char letter: aux){
                if(!checks[letter]){
                    flag=0;
                }
            }
            if(flag)cout<<"Super"<<endl;
            else cout<<"Primo"<<endl;
        }else{
            cout << "Nada"<<endl;
        }
        
    }
    return 0;
}