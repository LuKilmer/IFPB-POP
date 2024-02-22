#include <bits/stdc++.h>

using namespace std;

//ofstream outputFile("output.txt");
//ostream& out = outputFile;

int main() {
    int value, test_case = 0;
    while (cin >> value) {
        test_case++;
        vector<int> answer;

        int contador = 1; 
        answer.push_back(0);
        for (int i = 1; i <= value; i++) {
            for (int j = 0; j < i; j++) {
                answer.push_back(i);
            }
        }

        if (answer.size() == 1)
            cout << "Caso " << test_case << ": 1 numero\n";
        else
            cout << "Caso " << test_case << ": " << answer.size() << " numeros\n";

        for (int i = 0; i < answer.size(); i++) {
            cout << answer[i];
            if (i == answer.size() - 1)
                cout << endl;
            else
                cout << " ";
        }
        cout << endl;
    }

    return 0;
}
