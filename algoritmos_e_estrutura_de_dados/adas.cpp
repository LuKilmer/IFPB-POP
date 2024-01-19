#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

// Estrutura para representar uma aresta do grafo
struct Aresta {
    int destino;
    int peso;
};

// Função para imprimir o menor caminho a partir do vértice de origem
void imprimirMenorCaminho(const vector<int>& distancia, int origem, int destino) {
    cout << "Menor caminho de " << origem << " para " << destino << ": ";
    if (distancia[destino] == INT_MAX) {
        cout << "Caminho inexistente" << endl;
        return;
    }

    vector<int> caminho;
    for (int i = destino; i != origem; i = distancia[i])
        caminho.push_back(i);

    caminho.push_back(origem);

    for (int i = caminho.size() - 1; i >= 0; --i) {
        cout << caminho[i];
        if (i != 0) cout << " -> ";
    }

    cout << endl;
}

// Algoritmo de Dijkstra
void dijkstra(const vector<vector<Aresta>>& grafo, int origem) {
    int vertices = grafo.size();
    vector<int> distancia(vertices, INT_MAX);
    vector<bool> visitado(vertices, false);

    distancia[origem] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, origem});

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        if (visitado[u]) continue;

        visitado[u] = true;

        for (const Aresta& aresta : grafo[u]) {
            int v = aresta.destino;
            int pesoUV = aresta.peso;

            if (!visitado[v] && distancia[u] != INT_MAX && distancia[u] + pesoUV < distancia[v]) {
                distancia[v] = distancia[u] + pesoUV;
                pq.push({distancia[v], v});
            }
        }
    }

    // Exemplo: Imprimir as distâncias mínimas de origem para todos os vértices
    cout << "Distâncias mínimas de " << origem << " para todos os vértices:" << endl;
    for (int i = 0; i < vertices; ++i) {
        cout << "Vértice " << i << ": ";
        if (distancia[i] == INT_MAX) cout << "Infinito";
        else cout << distancia[i];
        cout << endl;
    }

    // Exemplo: Imprimir o menor caminho de origem para um vértice específico
    int destino = 3;  // Vértice de destino desejado
    imprimirMenorCaminho(distancia, origem, destino);
}

int main() {
    // Exemplo de um grafo ponderado direcionado
    int vertices = 6;
    vector<vector<Aresta>> grafo(vertices);

    // Adicionando arestas
    grafo[0].push_back({1, 2});
    grafo[0].push_back({2, 4});
    grafo[1].push_back({2, 1});
    grafo[1].push_back({3, 7});
    grafo[2].push_back({4, 3});
    grafo[3].push_back({4, 1});
    grafo[3].push_back({5, 5});
    grafo[4].push_back({5, 2});

    int origem = 0;  // Vértice de origem desejado
    dijkstra(grafo, origem);

    return 0;
}
