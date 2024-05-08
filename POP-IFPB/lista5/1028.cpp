#include <bits/stdc++.h>  


using namespace std;


ofstream outputFile("output.txt");
ostream& out = outputFile;

int main() {
    int test_case, aux;
    cin >> test_case;

    while (test_case-- > 0) {
        int num1, num2;
        cin >> num1 >> num2;
        

        while (num2!=0){
            aux = num1%num2;
            num1= num2;
            num2 = aux;
        };
        cout << num1 << endl;

    }

    return 0;
}