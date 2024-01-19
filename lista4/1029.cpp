#include <bits/stdc++.h>

using namespace std;

int fibonnaci(int num){
    if(num==1 || num == 0){
        return 1;
    }else{
        return 1 + fibonnaci(num-1) + fibonnaci(num-2);
    }
}



int fibonnaci2(int num){
    if(num==1){
        return 1;
    }
    if(num==0){
        return 0;
    }
    return fibonnaci2(num-1) + fibonnaci2(num-2);
}


int main(){
    
    int test_case, num;
    cin >> test_case;
    while(test_case--!=0){
        cin >> num;
        int answer1 = fibonnaci(num);
        int answer2 = fibonnaci2(num);
        cout << "fib("<<num<<") = "<<answer1-1<<" calls = "<<answer2<<endl;
    }
    

    return 0;
}