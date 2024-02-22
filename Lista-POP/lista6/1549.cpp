#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[]) {
    
    int counter = std::stoi(argv[1]);
    std::string path = "../output/1549/output" + std::to_string(counter) + ".txt";
    std::ofstream outputFile(path);
    std::ostream& out = outputFile;
    
    return 0;
}