#include <bits/stdc++.h>

using namespace std;

int imprimirCombinacoes(const vector<int> &vetor)
{
    int n = vetor.size();
    if (n <= 3)
        return 0;
    for (int i = 0; i < n - 2; ++i)
    {
        for (int j = i + 1; j < n - 1; ++j)
        {
            for (int k = j + 1; k < n; ++k)
            {
                cout << "(" << vetor[i] << ", " << vetor[j] << ", " << vetor[k] << ")" << endl;
            }
        }
    }
    return 1;
}

int imprimirSubsequenciaTamanhoNaoFixo(const vector<int>& vetor, int tamanhoSubarray) {
    int n = vetor.size();
    if (n < tamanhoSubarray) return 0;
    for (int i = 0; i <= n - tamanhoSubarray; ++i) {
        for (int j = i + 1; j <= n - tamanhoSubarray + 1; ++j) {
            for (int k = i; k < i + tamanhoSubarray; ++k) {
                cout << vetor[k] << " ";
            }
            cout << endl;
        }
    }
    return 1;
}

void imprimirSubsequencias(const vector<int> &array)
{
    int n = array.size();
    for (int i = 0; i < n; ++i)
    {
        for (int j = i; j < n; ++j)
        {
            for (int k = i; k <= j; ++k)
            {
                cout << array[k] << " ";
            }
            cout << endl;
        }
    }
}

void imprimirSubsequenciasRecursivo(const vector<int> &array, vector<int> &subsequencia, int index)
{
    for (int i = 0; i < subsequencia.size(); ++i)
    {
        cout << subsequencia[i] << " ";
    }
    cout << endl;
    for (int i = index; i < array.size(); ++i)
    {
        subsequencia.push_back(array[i]);
        imprimirSubsequenciasRecursivo(array, subsequencia, i + 1);
        subsequencia.pop_back();
    }
}

void imprimirSubsequenciasV2(const vector<int> &array)
{
    vector<int> subsequencia;
    imprimirSubsequenciasRecursivo(array, subsequencia, 0);
}

int main()
{
    vector<int> aux;
    aux = {1, 2, 3, 4, 5};
    imprimirCombinacoes(aux);
    cout << endl;
    imprimirSubsequencias(aux);
    cout << endl;
    imprimirSubsequenciasV2(aux);
    cout << endl;
    cout << endl;
    imprimirSubsequenciaTamanhoNaoFixo(aux,4);
    return 0;
}