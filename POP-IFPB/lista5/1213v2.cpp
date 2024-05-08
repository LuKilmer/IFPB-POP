#include <bits/stdc++.h>

using namespace std;

ofstream outputFile("output.txt");
ostream &out = outputFile;


bool divisaomanual(const std::string& numero, int divisor) {
    int resto = 0;

    for (char digito : numero) {
        int digitoInt = digito - '0';
        resto = (resto * 10 + digitoInt) % divisor;
    }

    return (resto== 0);
}

int divisaoManualParticionada(int divisor) {
    int resto=1;
    int answer=1;

    while(resto != 0){
        resto=(resto*10+1)%divisor;
        answer++;
    }

    return answer;
}

int main() {
    int divisor, answer;
    
    while (cin >> divisor) {
        if(divisor==1) answer = 1;
        else answer = divisaoManualParticionada(divisor);
        out << answer << endl;
    }

    return 0;
}