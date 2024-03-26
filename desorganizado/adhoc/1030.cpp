#include <bits/stdc++.h>

using namespace std;

int processo(int quantidade, int passos)
{
    int answer = 0;
    vector<int> mortos(quantidade);
    int kills = quantidade - 1;
    int ponteiro = -1;
    for (int i = 1; i <= quantidade; i++)
    {
        mortos[i - 1] = i;
    }
    while (kills != 0)
    {
        if (ponteiro > mortos.size())
            ponteiro = mortos.size() % passos;
    }

    return answer;
}

int main()
{
    int test_case;
    int quantidade, passos;
    cin >> test_case;
    while (test_case--)
    {
        cin >> quantidade >> passos;
        cout << processo(quantidade, passos) << endl;
    }
    return 0;
}