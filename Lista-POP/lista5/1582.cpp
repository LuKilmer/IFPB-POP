#include <bits/stdc++.h>

using namespace std;

bool checkPrimeNerfed(int x, int y, int z){
    int max_number = sqrt(z);
    for(int i = 2; i < max_number; i++){
        if(x%i==0 && y%i==0 && z%i==0){
            return false;
        }
    }
    return true;
}

int main()
{
    int x, y, z, aux;
    while(cin >> x >> y >> z){
        if(x>z){
            aux= z;
            z = x;
            x = aux;
        };
        if(y>z){
            aux= z;
            z = y;
            y = aux;
        };
        if(pow(x,2)+pow(y,2)!=pow(z,2)){
            cout << "tripla"<< endl;
        }else{
            if(checkPrimeNerfed(x,y,z)){
                cout << "tripla pitagorica primitiva" << endl;
            }else{
                cout << "tripla pitagorica" << endl;
            }
        }
    }
    return 0;
}