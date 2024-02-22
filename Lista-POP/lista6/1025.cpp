#include <bits/stdc++.h>

using namespace std;

int partition(vector<int> &alunos, int esquerda, int direita)
{
    int pivo = alunos[direita];
    int i = esquerda;
    for (int j = esquerda; j < direita; j++)
    {
        if (alunos[j] < pivo)
        {
            swap(alunos[i], alunos[j]);
            i++;
        }
    }
    swap(alunos[i], alunos[direita]);
    return i;
}

void quick_sort(vector<int> &alunos, int esquerda, int direita)
{
    if (esquerda < direita)
    {
        int pivo = partition(alunos, esquerda, direita);
        quick_sort(alunos, esquerda, pivo - 1);
        quick_sort(alunos, pivo + 1, direita);
    }
}

void show(vector<int> &aux)
{
    cout << endl;
    for (int in : aux)
    {
        cout << in << endl;
    }
}
int find_local(vector<int> &aux, int key){
    int answer = -1;

    vector<int>::iterator index = lower_bound(aux.begin(), aux.end(), key);

    if(index != aux.end()  ){
        answer = distance(aux.begin(), index) + 1;
    }
    return answer;
}

int main(int argc, char *argv[])
{
    /*int counter = std::stoi(argv[1]);
    std::string path = "../output/1025/output" + std::to_string(counter) + ".txt";
    std::ofstream outputFile(path);
    std::ostream& out = outputFile;*/

    int test_case, tentativa, aux, case_number, result;
    cin >> test_case >> tentativa;
    case_number = 1;
    while (test_case != tentativa != 0)
    {

        vector<int> bolinhas(test_case);
        for (int i = 0; i < test_case; i++){
            cin >> aux;
            bolinhas[i] = aux;
        }
        cout << "CASE# " << case_number << ":\n";
        quick_sort(bolinhas, 0, bolinhas.size() - 1);
        for (int i = 0; i < tentativa; i++){
            cin >> aux;
            result = find_local(bolinhas,aux);
            if(result==-1){
                cout << aux << " not found"<< endl;
            }else{
                cout << aux<<" found at "<< result<< endl;
            }
        }
        cin >> test_case >> tentativa;
        case_number++;
    }

    return 0;
}