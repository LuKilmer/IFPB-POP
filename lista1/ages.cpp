#include <iostream>
#include <iomanip>
using namespace std;

int main(){
    int number;
    int count = 0;
    float total = 0;
    cin >> number;
    while(number > 0){
        total += number;
        count++;
        cin >> number;
    }
    cout << fixed << setprecision(2) << total/count << endl; 
    return 0;
}