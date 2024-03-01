#include <bits/stdc++.h>

using namespace std;

long long mergesort(vector<string> &arr, long long l, long long m, long long r) {
    long long n1 = m - l + 1;
    long long n2 = r - m;

    vector<string> L(n1), R(n2);

    for (long long i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (long long j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    long long inversions = 0;
    long long i = 0, j = 0, k = l;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++];
            inversions += n1 - i;
        }
    }

    while (i < n1) {
        arr[k++] = L[i++];
    }

    while (j < n2) {
        arr[k++] = R[j++];
    }

    return inversions;
}

long long mergesortinvertion(vector<string> &arr, long long l, long long r) {
    long long inversions = 0;
    if (l < r) {
        long long m = l + (r - l) / 2;
        inversions += mergesortinvertion(arr, l, m);
        inversions += mergesortinvertion(arr, m + 1, r);
        inversions += mergesort(arr, l, m, r);
    }
    return inversions;
}

int main(int argc, char *argv[]) {
    long long test_case;
    string aux;
    string numeros;

    while (cin >> test_case) {
        vector<string> posicoes(test_case);

        for (long long index = 0; index < test_case; index++) {
            cin >> numeros;
            posicoes[index] = numeros;
        }

        long long inversions = mergesortinvertion(posicoes, 0, test_case - 1);
        cout << inversions << endl;
    }

    return 0;
}