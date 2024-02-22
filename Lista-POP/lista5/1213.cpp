#include <bits/stdc++.h>

using namespace std;

ofstream outputFile("output.txt");
ostream &out = outputFile;

bool divisaomanual2(const std::string& numero, int divisor) {
    int resto = 0;

    for (char digito : numero) {
        int digitoInt = digito - '0';
        resto = (resto * 10 + digitoInt) % divisor;
    }

    return (resto== 0);
}

int divisaoInvesar(int divisor) {
    int resto=1;
    int comprimento=1;

    while(resto != 0){
        resto=(resto*10+1)%divisor;
        comprimento++;
    }

    return comprimento;
}

bool divisaomanual(const string& numero, int divisor) {
    string resultado;
    int resto = 0;

    for (char digito : numero) {
        int digitoInt = digito - '0'; 
        int quociente = (resto * 10 + digitoInt) / divisor;
        resto = (resto * 10 + digitoInt) % divisor;
        resultado.push_back(quociente + '0'); 
    }
    if(resto==0){
        return true;
    }else{
        return false;
    }
}

int main(){
    auto inicio = chrono::high_resolution_clock::now();
    string numero = "";
    int divisor;

   
    while(cin >> divisor){
        numero="2";
        while(true){
            if(divisaomanual(numero, divisor)){
                out << numero.length() << endl;
                break;
            }else{
                numero+='2';
            }
        }
    }
    auto fim = chrono::high_resolution_clock::now();

    auto duracao = chrono::duration_cast<chrono::microseconds>(fim - inicio);
    double duracaoEmSegundos = duracao.count() / 1e6;
    cout << "Tempo de execução: " << duracao.count() << " microssegundos " <<duracaoEmSegundos << " segundos"<< endl;

    return 0;
}