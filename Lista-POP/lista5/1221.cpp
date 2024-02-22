#include <bits/stdc++.h>

using namespace std;

ofstream outputFile("output.txt");
ostream& out = outputFile;

bool checkPrime(unsigned long long num) {
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
    int test_case;
    unsigned long long num;
    bool flag;
    cin >> test_case;
    while(test_case--!=0){
        cin >> num;
        flag=true;
        
        flag=checkPrime(num);
        if(flag)cout << "Prime\n";
        else cout <<"Not Prime\n";
    }

    return 0;
}