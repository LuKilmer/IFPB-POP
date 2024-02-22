#include <bits/stdc++.h>

using namespace std;

int answer = 1;



void Hanoi(int N, char Orig, char Dest, char Temp) {
    if (N == 1) {
        answer++;
        std::cout << "Move the "<< N <<" smaller disc from pin " << Orig << " to pin " << Dest << std::endl;
    } else {
        Hanoi(N - 1, Orig, Temp, Dest);
        answer++;
        std::cout << "Move the " << N << "th lower disc from pin " << Orig << " to pin " << Dest << std::endl;
        Hanoi(N - 1, Temp, Dest, Orig);
    }
}

int fastPow(int base, int num){
    if(num==0){
        return 1;
    }
    int res = fastPow(base, num/2);
    res *= res;
    if (num%2!=0){
        res*=base;
    }
    return res;

}

int main(int argc, char *argv[]) {
    
    int counter = std::stoi(argv[1]);
    std::string path = "../output/2251/output" + std::to_string(counter) + ".txt";
    std::ofstream outputFile(path);
    std::ostream& out = outputFile;
    char Orig = 'A'; // Assuming three pins are labeled A, B, C
    char Dest = 'C';
    char Temp = 'B';

    int entrada;
    int contador=1;
    cin >> entrada;
    while(entrada!=0){
      
        //Hanoi(entrada, Orig, Dest, Temp);
        //Hanoi(entrada);
        out << "Teste "<<contador<<endl;
        out << fastPow(2,entrada)-1 << endl<<endl;;
        answer=0;
        cin >> entrada;
        contador++;
    }


    return 0;
}