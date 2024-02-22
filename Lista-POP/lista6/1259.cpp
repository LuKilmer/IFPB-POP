#include <bits/stdc++.h>

using namespace std;


int partition(vector<int>& numeros, int esquerda, int direita) {
    int pivo = numeros[direita];
    int i = esquerda;
    
    for (int j = esquerda; j < direita; j++) {
        if (numeros[j] <= pivo) {
            swap(numeros[i], numeros[j]);
            i++;
        }
    }

    swap(numeros[i], numeros[direita]);
    return i;
}

void quick_sort(vector<int>& numeros, int esquerda, int direita) {
    if (esquerda < direita) {
        int pivo = partition(numeros, esquerda, direita);
        quick_sort(numeros, esquerda, pivo - 1);
        quick_sort(numeros, pivo + 1, direita);
    }
}


int main(int argc, char *argv[]) {
    
    int counter = std::stoi(argv[1]);
    std::string path = "../output/1259/output" + std::to_string(counter) + ".txt";
    std::ofstream outputFile(path);
    std::ostream& out = outputFile;

    int test_case, num;
    cin >> test_case;
    vector<int>numeros_odd;
    vector<int>numeros_even;
    while(test_case--){
        cin >> num;
        if(num%2==0 && num!=0){
            numeros_odd.push_back(num);      
        }else{
            numeros_even.push_back(num);
        }
        
    }
    quick_sort(numeros_odd,0, numeros_odd.size()-1);
    quick_sort(numeros_even,0, numeros_even.size()-1);
    int odd_size = numeros_odd.size();
    int even_size = numeros_even.size();
    for(int i =0; i < odd_size; i ++){
        out << numeros_odd[i]<<endl;
    }
    for(int i = even_size-1; i>=0; i--){
        out << numeros_even[i] << endl;
    }
    return 0;
}