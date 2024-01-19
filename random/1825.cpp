#include <bits/stdc++.h>

using namespace std;

class grafo {
private:
    int numVertices;
    vector<list<int>> lista;

public:
    grafo(int vertices) : numVertices(vertices), lista(vertices) {
     
    }
    void adicionarAresta(int origem, int destino) {
        lista[origem -1].push_back(destino -1);
        lista[destino -1].push_back(origem -1); 
    }
    void imprimirGrafo() {
        for (int i = 0; i < numVertices; ++i) {
            cout << "Vertice " << i+1 << ": ";
            for (const auto& vizinho : lista[i]) {
                cout << vizinho+1 << " ";
            }
            cout <<endl;
        }
    }
    int todosVerticesConectados() {
        std::vector<bool> visitado(numVertices, false);

        // Escolha um vértice como ponto de partida (assumindo que o grafo não é vazio)
        int verticeInicial = 0;

        std::queue<int> fila;
        fila.push(verticeInicial);
        visitado[verticeInicial] = true;

        while (!fila.empty()) {
            int atual = fila.front();
            fila.pop();

            for (const auto& vizinho : lista[atual]) {
                if (!visitado[vizinho]) {
                    fila.push(vizinho);
                    visitado[vizinho] = true;
                }
            }
        }
        
        // Verifica se todos os vértices foram visitados
       
        int falta = 0;
        for (bool visit : visitado) {

            if (!visit) {
                falta++; 
            }
        }

        return falta;}
};
int main(){
    int test_case, base;
    int answer, ways, promise;
    pair<int,int>way;
    cin >> test_case;
    base = test_case;
    
    while(test_case--!=0){
        cin >> promise;
        grafo graf = grafo(promise);
        cin >> ways;
        while(ways>0){
            cout << ways << endl;
            cin>> way.first >> way.second;
            graf.adicionarAresta(way.first ,way.second );
            ways--;
        }
      
        graf.imprimirGrafo();
        answer =  graf.todosVerticesConectados();
        if(answer==0){
            cout << "Caso #" << (base-test_case ) << ": a promessa foi cumprida\n";
        }else{
            cout << "Caso #" << (base-test_case ) << ": ainda falta(m) "<< answer<<" estrada(s)\n";
        }
    }
    return 0;
}