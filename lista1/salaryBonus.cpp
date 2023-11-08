#include <bits/stdc++.h>

using namespace std;

int main(){
    string name;
    double salary, selled;
    cin >> name;
    cin >> salary >> selled;
    cout << "TOTAL = R$ "<< fixed << setprecision(2) << salary + selled * 0.15 << endl;
    return 0;
}