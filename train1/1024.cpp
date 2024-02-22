//https://judge.beecrowd.com/en/problems/view/1024
#include <bits/stdc++.h>

using namespace std;


int main(int argc, char *argv[]) {
    
    int counter = std::stoi(argv[1]);
    std::string path = "../output/1024-output" + std::to_string(counter) + ".txt";
    std::ofstream outputFile(path);
    std::ostream& out = outputFile;
    std::string aux;
    std::cin >> aux;
    out << aux + " questão 1024" << std::endl;

    return 0;
}