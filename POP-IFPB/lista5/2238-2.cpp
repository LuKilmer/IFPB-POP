#include <bits/stdc++.h> 

using namespace std;


int main() {
    auto start = std::chrono::high_resolution_clock::now();
    int a, b, c, d;
    cin >> a >> b >> c >> d;

    int answer = -1;

    for (int aux = a; aux <= c; aux += a) {
        if (aux % b != 0 && c % aux == 0 && d % aux != 0) {
            answer = aux;
            break;
        }
    }

    cout << answer << endl;
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
    std::cout << "Tempo de execucao: " << duration.count() << " microssegundos." << std::endl;

    return 0;
}
