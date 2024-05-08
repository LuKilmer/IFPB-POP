#include <bits/stdc++.h>

using namespace std;


struct aluno {
    string nome;
    char regiao;
    int distancia;
};

int partition(vector<aluno>& alunos, int esquerda, int direita) {
    aluno pivo = alunos[direita];
    int i = esquerda;
    
    for (int j = esquerda; j < direita; j++) {
         if (alunos[j].distancia < pivo.distancia || 
            (alunos[j].distancia == pivo.distancia && alunos[j].regiao < pivo.regiao)||
            (alunos[j].distancia == pivo.distancia && alunos[j].regiao == pivo.regiao && alunos[j].nome < pivo.nome )) {
            swap(alunos[i], alunos[j]);
            i++;
        }
    }

    swap(alunos[i], alunos[direita]);
    return i;
}

void quick_sort(vector<aluno>& alunos, int esquerda, int direita) {
    if (esquerda < direita) {
        int pivo = partition(alunos, esquerda, direita);
        quick_sort(alunos, esquerda, pivo - 1);
        quick_sort(alunos, pivo + 1, direita);
    }
}


int main(int argc, char *argv[])
{
    int counter = std::stoi(argv[1]);
    std::string path = "../output/2693/output" + std::to_string(counter) + ".txt";
    std::ofstream outputFile(path);
    std::ostream &out = outputFile;
    string name;
    char position;
    int num;
    int test_case;
    aluno aux;
    vector<aluno> alunos;

    while(cin>>test_case){
        while(test_case--){
        cin >> aux.nome >> aux.regiao >> aux.distancia;
        alunos.push_back(aux);
        }
        quick_sort(alunos,0, alunos.size()-1);
        for(aluno sup: alunos){
            out << sup.nome << endl;
        }
        alunos.clear();
    }
    
    return 0;
}