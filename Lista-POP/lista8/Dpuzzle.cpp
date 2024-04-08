#include <bits/stdc++.h>

using namespace std;

int search(vector<int> &avioes, int index) {
    int a = index;
    int b = avioes[a];
    int c = avioes[b];
    if (avioes[c] == a)
        return 1;
    return 0;
}

int amorTrinagular(vector<int> &avioes) {
    int n = avioes.size();
    for (int i = 1; i < n; i++) {
        if (search(avioes, i))
            return 1;
    }
    return 0;
}

int main() {
    int n;
    cin >> n;
    vector<int> avioes(n + 1); 
    for (int i = 1; i <= n; i++) {
        cin >> avioes[i];
    }
    if (amorTrinagular(avioes))
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}
