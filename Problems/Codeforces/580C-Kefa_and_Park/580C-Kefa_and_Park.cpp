#include<bits/stdc++.h>
using namespace std;
typedef long long       ll;
const int MAXN = 1e7 + 1;
#include <iostream>
#include <vector>
using namespace std;

class Tree {
public:
    int n;  // Número de vértices (nodos)
    vector<vector<int>> adj;  // Lista de adyacencia para almacenar el árbol
    vector<int> cat;  // Vector para marcar los nodos visitados
    vector<bool> visited;
    vector<int> ncats;
    Tree(int n) {
        this->n = n;
        adj.resize(n);  // Lista de adyacencia de tamaño n+1 (1-indexado)
        visited.resize(n, false);
        cat.resize(n);
        ncats.resize(n);
    }
    
    void addEdge(int padre, int hijo) {
        adj[padre].push_back(hijo);
        adj[hijo].push_back(padre);  
    }
    void dfs(int padre, int ncatsp, int m) {
        visited[padre] = true;
        if(ncatsp != 0 && cat[padre] != 0)ncats[padre] = cat[padre] + ncatsp;  
        else ncats[padre] = cat[padre];
        //cout << "ncats " << padre + 1 << ": " << ncats[padre] << "\n";
        if(ncats[padre] > m){
            //cout << "ncats " << padre + 1 << ": " << ncats[padre] << "\n";
            return;
        }
        for (int hijo : adj[padre]) {
            if (!visited[hijo]) {
                dfs(hijo, ncats[padre], m);
            }
        }
    }
    void mostrar(){
        for(int i = 0; i < n; i++){
            cout << "i : " << i + 1 <<" - " << ncats[i] << "\n"; 
        }
    }
    void startDFS(int root, int m) {
        dfs(root, 0, m);  // Inicia el DFS desde la raíz del árbol
    }
    int countLeafNodes(int m) {
        int leafCount = 0;
        for (int i = 0; i < n; ++i) {
            // Un nodo es hoja si solo tiene un vecino y no es la raíz
            if (adj[i].size() == 1 && i != 0 && ncats[i] <= m && visited[i]) {
                leafCount++;
            }
        }
        return leafCount;
    }
};


void solve(){
    int n, m; cin >> n >> m;
    Tree arb(n);
    for(int i = 0; i < n; i++){
        int n; cin >> n;
        arb.cat[i] = n;
    }
    for(int i = 0; i < n - 1; i++){
        int p, h; cin >> p >> h;
        p--, h--;
        arb.addEdge(p, h);
    }
    arb.startDFS(0, m);
    //arb.mostrar();
    cout << arb.countLeafNodes(m) << "\n";
}

int main(){
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    int t; t = 1;
    while(t--)solve();
    return 0;}
    