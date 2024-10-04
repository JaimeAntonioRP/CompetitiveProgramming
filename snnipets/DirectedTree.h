#include <iostream>
#include <vector>
using namespace std;

class Tree {
public:
    int n;  // Número de vértices (nodos)
    vector<vector<int>> adj;  // Lista de adyacencia para almacenar el árbol
    vector<bool> visited;  // Vector para marcar los nodos visitados

    Tree(int n) {
        this->n = n;
        adj.resize(n);  // Lista de adyacencia de tamaño n+1 (1-indexado)
        visited.resize(n, false);
    }
    
    void addEdge(int padre, int hijo) {
        adj[padre].push_back(hijo);  
    }
    void dfs(int padre) {
        visited[padre] = true;  
        for (int hijo : adj[padre]) {
            if (!visited[hijo]) {
                dfs(hijo); 
            }
        }
    }
    void startDFS(int root = 1) {
        dfs(root);  // Inicia el DFS desde la raíz del árbol
    }

    int countLeafNodes() {
        int leafCount = 0;
        for (int i = 0; i < n; ++i) {
            // Un nodo es hoja si solo tiene un vecino y no es la raíz
            if (adj[i].size() == 1 && i != 0) {
                leafCount++;
            }
        }
        return leafCount;
    }
};
