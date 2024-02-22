//https://judge.beecrowd.com/en/problems/view/2243
#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[]) {

    std::string path = "../output/2243/output" + std::to_string(std::stoi(argv[1])) + ".txt";
    std::ofstream outputFile(path);std::ostream& out = outputFile;std::string aux;

    std::cin >> aux;
    out << aux + " questão" << std::endl;

    return 0;
}