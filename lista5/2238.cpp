#include <bits/stdc++.h> 

using namespace std;

int main(){
    auto start = std::chrono::high_resolution_clock::now();

    int a, b, c, d,aux,contador, answer = -1;
    cin >> a >> b >> c >> d;
    aux = a;
    while(true){
        if(aux>c)break;
        if(aux%a==0 && aux%b !=0 && c%aux==0 && d%aux!=0){
            answer = aux;
            break;
        }    
        aux+=a;
    }
    cout << answer << endl;

    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
    std::cout << "Tempo de execucao: " << duration.count() << " microssegundos." << std::endl;

    return 0;
}