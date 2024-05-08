#include <bits/stdc++.h>

using namespace std;

void combinationsloucas(vector<int>& elements, vector<int>& combination, int start, int k) {
    int n = elements.size();
    int r = combination.size();

    if (r == k) {
        for (int i = 0; i < k; i++) {
            cout << combination[i] << " ";
        }
        cout << endl;
        return;
    }

    for (int i = start; i < n; i++) {
        combination.push_back(elements[i]);
        combinationsloucas(elements, combination, i + 1, k);
        combination.pop_back();
    }
}

int main(int argc, char *argv[]){
    int counter = stoi(argv[1]);string path = "../output/1310/output" + to_string(counter) + ".txt";
    ofstream outputFile(path);ostream &out = outputFile;

    int test_case,aux, limit;
    vector<int>days;
    vector<int>combination;
    cout << endl;
    while(cin>>test_case){
        cin >> limit;
        days.clear();
        while(test_case--){
            cin >> aux;
            days.push_back(aux);
        }
        for(int i = 0; i < days.size(); i++){
            combinationsloucas(days,combination, 0,i);
        }
        

    }
    

    return 0;
}