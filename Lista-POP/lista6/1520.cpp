#include <bits/stdc++.h>

using namespace std;


pair<vector<int>::iterator,vector<int>::iterator>answer;

void find_interval(vector<int>&pratileira, int key){
    answer.first=lower_bound(pratileira.begin(), pratileira.end(), key); //          ^
    answer.second= upper_bound(pratileira.begin(), pratileira.end(), key);
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
    std::string path = "../output/1520/output" + std::to_string(counter) + ".txt";
    std::ofstream outputFile(path);
    std::ostream& out = outputFile;
    
    vector<int> prateleira = {1,1,2,4,4,4,4,4,4,4,7,9,11,11,23,32,32,32,45,54,66,66,66,66,66,86};
    
    int test_case;
    pair<int,int>intervalo;
    int key;
    while(cin>>test_case){
        prateleira.clear();
        while(test_case--){
            cin >> intervalo.first >> intervalo.second;
            for(int i = intervalo.first; i <=intervalo.second; i++){
                prateleira.push_back(i);
            }
        }
        cin >> key;
        quick_sort(prateleira,0, prateleira.size()-1);
        

        find_interval(prateleira, key);
        if(*answer.first ==*answer.second){
            out <<key <<" not found\n";
        }else{
            out << key <<" found from "<<(answer.first - prateleira.begin())<< " to "<<(answer.second- prateleira.begin()-1)<<endl; 
        }
        
    }

    return 0;
}