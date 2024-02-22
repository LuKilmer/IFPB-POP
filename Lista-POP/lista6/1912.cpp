#include <bits/stdc++.h>

using namespace std;

double answer;
int binary_search(const vector<int>& A, int esquerda, int direita, int valor) {
    if (esquerda > direita) {
        return -1;
    }
    int meio = (esquerda + direita) / 2;
    if (A[meio] == valor) {
        return meio;
    } else if (A[meio] > valor) {
        return binary_search(A, esquerda, meio - 1, valor);
    } else {
        return binary_search(A, meio + 1, direita, valor);
    }
}


int partition(vector<int>& alunos, int esquerda, int direita) {
    int pivo = alunos[direita];
    int i = esquerda;
    
    for (int j = esquerda; j < direita; j++) {
         if (alunos[j] < pivo) {
            swap(alunos[i], alunos[j]);
            i++;
        }
    }

    swap(alunos[i], alunos[direita]);
    return i;
}

void quick_sort(vector<int>& alunos, int esquerda, int direita) {
    if (esquerda < direita) {
        int pivo = partition(alunos, esquerda, direita);
        quick_sort(alunos, esquerda, pivo - 1);
        quick_sort(alunos, pivo + 1, direita);
    }
}

int main(int argc, char *argv[]) {
    
    int counter = std::stoi(argv[1]);
    std::string path = "../output/1912/output" + std::to_string(counter) + ".txt";
    std::ofstream outputFile(path);
    std::ostream& out = outputFile;
    
    int test_case, limit, num, total, maior;
    vector<int>papelao;
    cin>>test_case >> limit;
    while(test_case!=0 && limit!=0){
        total =0;
        maior = 0;
        papelao.clear();
        while(test_case--){
            cin>>num;
            total+=num;
            if(maior<num)maior = num;
            papelao.push_back(num);

        }
        if(total==limit){
            out << ":D\n";
        }else if(total<limit){
            out << "-.-\n";
        }else{
            quick_sort(papelao,0, papelao.size()-1);
            out << answer << endl;
        }

        cin>>test_case >> limit;
    }


    return 0;
}