#include <bits/stdc++.h>

using namespace std;

ofstream outputFile("output.txt");
ostream& out = outputFile;

vector<string> split(const string& input, char delimiter) {
    vector<string> tokens;
    istringstream stream(input);
    string token;
    while (getline(stream, token, delimiter)) {
        tokens.push_back(token);
    }
    return tokens;
}

vector<pair<int, int>> stringToTime(const string& time) {
    vector<pair<int, int>> request;
    pair<int, int> turno = {0, 0};
    vector<string> horarios1 = split(split(time, '|')[0], ' ');
    vector<string> horarios2 = split(split(time, '|')[1], ' ');
    horarios2.erase(horarios2.begin());
    turno.first = stoi(split(horarios1[0], ':')[0]) * 60 + stoi(split(horarios1[0], ':')[1]);
    turno.second = stoi(split(horarios1[1], ':')[0]) * 60 + stoi(split(horarios1[1], ':')[1]);
    request.push_back(turno);
    turno.first = stoi(split(horarios2[0], ':')[0]) * 60 + stoi(split(horarios2[0], ':')[1]);
    turno.second = stoi(split(horarios2[1], ':')[0]) * 60 + stoi(split(horarios2[1], ':')[1]);
    request.push_back(turno);

    return request;
}

vector<int> stringToTime2(const string& time) {
    vector<int> request;
    vector<string> horarios1 = split(split(time, '|')[0], ' ');
    vector<string> horarios2 = split(split(time, '|')[1], ' ');
    horarios2.erase(horarios2.begin());
    request.push_back(stoi(split(horarios1[0], ':')[0]) * 60 + stoi(split(horarios1[0], ':')[1]));
    request.push_back(stoi(split(horarios1[1], ':')[0]) * 60 + stoi(split(horarios1[1], ':')[1]));
    request.push_back(stoi(split(horarios2[0], ':')[0]) * 60 + stoi(split(horarios2[0], ':')[1]));
    request.push_back(stoi(split(horarios2[1], ':')[0]) * 60 + stoi(split(horarios2[1], ':')[1]));
    return request;
}

string intToTimeFormat(int time) {
    string result;
    if (time <= 0) { 
        result += "+ ";
        time *= -1;
    } else {
        result += "- ";
    }
    int horas = time / 60;
    int minutos = time % 60;
    if (horas < 10)
        result += "0" + to_string(horas);
    else
        result += to_string(horas);
    result += ":";
    if (minutos < 10)
        result += "0" + to_string(minutos);
    else
        result += to_string(minutos);
    return result;
}

int main() {
    int test_case, days, answer;
    string subtime;
    cin >> test_case;
    pair<int,int>periodo1 = {480, 720};
    pair<int, int>periodo2 = {840,1080};
    while (test_case-- != 0) {
        cin >> days;
        answer = 0;

        // Consumir a quebra de linha restante após a leitura do número de dias
        cin.ignore();

        for (int i = 0; i < days; i++) {
            getline(cin, subtime);
            vector<int> titulos = stringToTime2(subtime);
            titulos[0] = titulos[0] - periodo1.first;
            titulos[1] = periodo1.second - titulos[1];
            titulos[2] = titulos[2] - periodo2.first;
            titulos[3] = periodo2.second - titulos[3];
            for (int i = 0; i < titulos.size(); i++) {
                if (titulos[i] > 5 || titulos[i] < -5) {
                    answer += titulos[i];
                }
            }
        }
        cout << intToTimeFormat(answer) << endl;
    }

    return 0;
}
