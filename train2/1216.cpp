#include <bits/stdc++.h>
using namespace std;

int main()
{
    int test_case;
    double total, contador = 0;

    string sup;
    regex integerPattern("^-?\\d+$");
    while (getline(cin, sup)) {

        if(regex_match(sup, integerPattern)){
            total+=stoi(sup);
            contador++;
        }
  
    }
    
    cout << fixed << setprecision(1) << total / contador << endl;

    return 0;
}