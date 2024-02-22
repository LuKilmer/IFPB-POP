#include <bits/stdc++.h>

using namespace std;

int main(){
    const char* arqui = "answer.txt";
    ofstream arquivoSaida(arqui);
    streambuf* backup = cout.rdbuf(arquivoSaida.rdbuf());
    cout.rdbuf(backup);
    return 0;
    
}