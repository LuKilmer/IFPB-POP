#include <bits/stdc++.h>

using namespace std;

bool compararConteudoArquivos(const string& nomeArquivo1, const string& nomeArquivo2) {
    ifstream arquivo1(nomeArquivo1);
    ifstream arquivo2(nomeArquivo2);

    if (!arquivo1.is_open() || !arquivo2.is_open()) {
        cerr << "Erro ao abrir os arquivos." << endl;
        return false;
    }

    string linhaArquivo1, linhaArquivo2;

    while (getline(arquivo1, linhaArquivo1) && getline(arquivo2, linhaArquivo2)) {
        if (linhaArquivo1 != linhaArquivo2) {
            cout << "output:"<<endl;
            cout << "\033[1;31m"+linhaArquivo1+"\033[0m" << endl;
            cout << "correct answer:"<<endl;
            cout << "\033[1;32m"+linhaArquivo1+"\033[0m" << endl;
            return false;  
        }
    }

    return arquivo1.eof() && arquivo2.eof();
}
int main(int argc, char *argv[]) {
    string questao = to_string(stoi(argv[1]));
    string index = to_string(stoi(argv[2]));
    cout << questao << " "<< index << endl;
    string nomeArquivo1 = "../output/"+questao+"/output"+index+".txt";
    string nomeArquivo2= "../answer/"+questao+"/answer"+index+".txt";


    if (compararConteudoArquivos(nomeArquivo1, nomeArquivo2)) {
        cout << "\033[1;32mOs arquivos têm o mesmo conteúdo.\033[0m" << endl;
    } else {
        cout << "\033[1;31mOs arquivos têm conteúdo diferente.\033[0m" << endl;
    }

    return 0;
}
