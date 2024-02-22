#include <iostream>
#include <vector>

void generateCombinations(std::vector<int>& elements, std::vector<int>& combination, int start, int k) {
    int n = elements.size();
    int r = combination.size();

    if (r == k) {
        for (int i = 0; i < k; i++) {
            std::cout << combination[i] << " ";
        }
        std::cout << std::endl;
        return;
    }

    for (int i = start; i < n; i++) {
        combination.push_back(elements[i]);
        generateCombinations(elements, combination, i + 1, k);
        combination.pop_back();
    }
}

int main() {
    std::vector<int> elements = {1, 2, 3, 4};
    int k = 4; // tamanho da combinação

    std::vector<int> combination;
    generateCombinations(elements, combination, 0, k);

    return 0;
}