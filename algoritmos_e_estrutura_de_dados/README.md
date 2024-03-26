Todas as possíveis combinações dentro de um array
```c++
void imprimirSubsequenciasRecursivo(const vector<int>& array, vector<int>& subsequencia, int index) {
    for (int i = 0; i < subsequencia.size(); ++i) {
        cout << subsequencia[i] << " ";
    }
    cout << endl;
    for (int i = index; i < array.size(); ++i) {
        subsequencia.push_back(array[i]);
        imprimirSubsequenciasRecursivo(array, subsequencia, i + 1);
        subsequencia.pop_back();
    }
}

void imprimirSubsequenciasV2(const vector<int>& array) {
    vector<int> subsequencia;
    imprimirSubsequenciasRecursivo(array, subsequencia, 0);
}
```
imprime um subarray de tamanho requirido
```cpp
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
```

```cpp

```