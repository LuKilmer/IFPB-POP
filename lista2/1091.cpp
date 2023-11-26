#include <bits/stdc++.h>

using namespace std;

struct cordenada{
        int x;
        int y;
    };

int main(){
    int teste_case;
    cordenada central={0,0};
    cordenada house={0,0};
    cin >> teste_case;
    while(teste_case!=0){
        cin >> central.x >> central.y;
        for(int i=0; i < teste_case;i++){
            cin >> house.x >> house.y;
            if(house.x==central.x or house.y==central.y){
                cout << "divisa\n";
            }
            else if(house.x>central.x and house.y<central.y){
                cout << "SE\n";
            }
            else if(house.x>central.x and house.y>central.y){
                cout << "NE\n";
            }
            else if(house.x<central.x and house.y<central.y){
                cout << "SO\n";
            }
            else if(house.x<central.x and house.y>central.y){
                cout << "NO\n";
            }
        }
        
        cin >> teste_case;
    }
    return 0;
}