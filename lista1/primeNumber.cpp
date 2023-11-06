#include <bits/stdc++.h>

using namespace std;
bool prime_number(int num) {
    bool flag = false;
    int aux = 2;
    int limit = (num / 2) + 1;  // Correção aqui
    while (aux < limit) {
        if (num % aux == 0) {
            flag = true;
            break;
        } else {
            limit = (num / aux) + 1;  // Correção aqui
            aux++;
        }
    }
    return flag;
}

int main(){
    int test_case=0;
    int number;

    cin >> test_case;

    while(test_case!=0){
        cin >> number;
        if(prime_number(number)) printf("%d nao eh primo\n", number);
        else printf("%d eh primo\n", number);
    }

    return 0;
}