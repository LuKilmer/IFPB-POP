#include <iostream>
#include <algorithm>
#include <vector>

// Função para imprimir o array
void printArray(const std::vector<int>& arr) {
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}

int main() {
    const int size = 5;

    // Criar um array de 1 a 400
    std::vector<int> array(size);
    for (int i = 0; i < size; ++i) {
        array[i] = i + 1;
    }

    // Usar a função next_permutation para gerar todas as permutações
    do {
        // Processar a permutação atual, por exemplo, imprimir
        printArray(array);
    } while (std::next_permutation(array.begin(), array.end()));

    return 0;
}
