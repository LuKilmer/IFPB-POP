#include <bits/stdc++.h>

using namespace std;


vector<string> split(const string& input, char delimiter) {
    vector<string> tokens;
    istringstream stream(input);
    string token;
    while (getline(stream, token, delimiter)) {
        tokens.push_back(token);
    }
    return tokens;
}


vector<pair<int,int>> stringToTime(const string& time){
    vector<pair<int,int>> request;
    pair<int,int>turno ={0,0};
    vector<string> horarios1 = split(split(time,'|')[0],' ');
    vector<string> horarios2 = split(split(time,'|')[1],' ');
    horarios2.erase(horarios2.begin());
    
    turno.first = stoi(split(horarios1[0],':')[0])*60 + stoi(split(horarios1[0],':')[1]);
    turno.second = stoi(split(horarios1[1],':')[0])*60 + stoi(split(horarios1[1],':')[1]);
    request.push_back(turno);
    turno.first = stoi(split(horarios2[0],':')[0])*60 + stoi(split(horarios2[0],':')[1]);
    turno.second = stoi(split(horarios2[1],':')[0])*60 + stoi(split(horarios2[1],':')[1]);
    request.push_back(turno);

    return request;
}

int main(){
    vector<pair<int,int>>titulo = stringToTime("07:55 12:03 | 13:54 18:02");
    for(pair<int,int>turno : titulo){
        cout << turno.first << " "<< turno.second << endl;
    }
    return 0;
}