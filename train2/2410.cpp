#include <bits/stdc++.h>

using namespace std;

int main()
{

    unordered_set<int> registrosUnicos;
    
    
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    long long  t, aux, answer=0;

    cin >> t;

    long long sup = t;
    while (t--)
    {
        cin >> aux;

        registrosUnicos.insert(aux);
    }
    
    cout << registrosUnicos.size() << endl;
    return 0;
}