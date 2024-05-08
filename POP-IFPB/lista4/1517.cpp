#include <bits/stdc++.h>

using namespace std;


vector<vector<vector<int>>> apples;
vector<vector<vector<int>>> memo;

int get_apples(int pos_x, int pos_y, int pos_tempo) {
    int quant_apple = 0;

    if (pos_x < 0 || pos_x >= apples.size() || pos_y < 0 || pos_y >= apples[0].size() || pos_tempo >= apples[0][0].size()) {
        return 0;
    }

    if (memo[pos_x][pos_y][pos_tempo] != -1) {
        return memo[pos_x][pos_y][pos_tempo];
    }

    if (apples[pos_x][pos_y][pos_tempo] == 1) {
        //cout <<"x: "<< pos_x <<" y:"<< pos_y <<" tempo:"<<pos_tempo<<endl;
        quant_apple = 1;
    }

    memo[pos_x][pos_y][pos_tempo] = quant_apple + std::max({
        get_apples(pos_x + 1, pos_y, pos_tempo + 1),
        get_apples(pos_x + 1, pos_y + 1, pos_tempo + 1),
        get_apples(pos_x + 1, pos_y - 1, pos_tempo + 1),
        get_apples(pos_x - 1, pos_y, pos_tempo + 1),
        get_apples(pos_x, pos_y + 1, pos_tempo + 1),
        get_apples(pos_x - 1, pos_y + 1, pos_tempo + 1),
        get_apples(pos_x - 1, pos_y - 1, pos_tempo + 1),
        get_apples(pos_x, pos_y - 1, pos_tempo + 1)
    });

    return memo[pos_x][pos_y][pos_tempo];
}


void showapples(){
    for(int i = 0 ; i < apples[0][0].size(); i++){
        cout << "tempo: "<< i << endl;
        for(int j = 0 ; j < apples.size(); j++){
            for(int k = 0 ; k < apples[j].size(); k++){
                cout<<apples[j][k][i]<< " ";
            }
            cout << endl;
        }

    }
}
void showMemo(){
    for(int i = 0 ; i < memo[0][0].size(); i++){
        cout << "tempo: "<< i << endl;
        for(int j = 0 ; j < memo.size(); j++){
            for(int k = 0 ; k < memo[j].size(); k++){
                cout<<memo[j][k][i]<< " ";
            }
            cout << endl;
        }

    }
}

void catchApples(){
    for(int i = 0 ; i < apples[0][0].size(); i++){
        cout << "tempo: "<< i << endl;
        for(int j = 0 ; j < apples.size(); j++){
            for(int k = 0 ; k < apples[j].size(); k++){
                if(apples[j][k][i]==1){
                    cout<<"x: "<< j<<" y:"<<k<< " tempo:"<< i<<endl;
                }
           
            }
        }

    }
}
int main() {
    int x_dim, y_dim, tempo_dim;
    cin >> x_dim >> y_dim >> tempo_dim;

    pair<int, int> position;

    while (x_dim + y_dim + tempo_dim > 0) {
        apples = vector<vector<vector<int>>>(x_dim, vector<vector<int>>(y_dim, vector<int>(tempo_dim*2, 0)));
        memo = vector<vector<vector<int>>>(x_dim, vector<vector<int>>(y_dim, vector<int>(tempo_dim*2, -1)));
        
        for (int i = 0; i < tempo_dim; i++) {
            int x, y, tempo;
            cin >> x >> y >> tempo;
            //cout << x << y << tempo << endl;
            apples[x-1][y-1][tempo] = 1;
        }
        //catchApples();
        cin >> position.first >> position.second;
        
        //catchApples();
        //showapples();
        cout << get_apples(position.first-1,position.second-1,0) << endl;
        //showMemo();
        cin >> x_dim >> y_dim >> tempo_dim;
        
    }

    return 0;
}