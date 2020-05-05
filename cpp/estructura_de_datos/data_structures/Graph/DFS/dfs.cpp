// Depth First Search Algorithm
// By: Aaron Vegu 2020

#include <iostream>
#include <list>

using namespace std;

class Graph
{
    private:
        // Numero de vertices
        int V;
        // Puntero a lista de adyacencias
        list<int> *adj;
        // DFS recursive helper
        void DFS_helper(int s, bool *visited);

    public:
        // Constructor del Grafo
        Graph(int v);
        // Metodo para agregar un Edge
        void addEdge(int v, int w);
        // Metodo para realizar recorrido DSF
        void DFS(int s);
};

// Constructor tomando los vertices del Grafo
Graph::Graph(int v)
{
    // Guardamos los numeros de vertices
    V = v;
    // Creamos nuestra adjacency list
    adj = new list<int>[v];
}

// Metodo para agregar conexiones
void Graph::addEdge(int v, int w) { adj[v].push_back(w); }

// DFS Helper
void Graph::DFS_helper(int s, bool *visited)
{
    // Marcamos al nodo pasado en argumento como visitado
    cout << s << " | Visitando Nodo" << endl;
    visited[s] = true;

    // Ingresamos a la adjacency list del nodo s
    for (auto i = adj[s].begin(); i != adj[s].end(); i++)
    {
        // De no haber sido visitado, nos adentramos en la
        // adjacency list del nodo i desde el nodo s
        if (!visited[*i])
        {
            cout << "Yendo al vertice " << *i << " desde el vertice " << s << endl;
            // Llamada recursiva. Para ingresar en cada nodo del vertice inicial
            DFS_helper(*i, visited);
        }
    }
}

// Recorrido DSF iniciando en vertice s
void Graph::DFS(int s)
{
    // Creamos un arreglo de booleanos para almacenar el estado
    // de visita de cada vertice, y lo inicializamos con todos sus
    // valores en false
    bool *visited = new bool[V];
    for (int i = 0; i < V; i++)
    {
        visited[i] = false;
    }
    
    // Inicio de la llamada recursiva. Iniciando desde el vertice s
    // nos iremos adentrando en los vertices conectados a el
    DFS_helper(s, visited);
}

int main()
{
    // Creamos el Grafo
    Graph grafo(5);

    // Creamos los edges para cada vertice
    // Vertice 0
    grafo.addEdge(0, 1);
    grafo.addEdge(0, 2);

    // Vertice 1
    grafo.addEdge(1, 0);
    grafo.addEdge(1, 3);
    grafo.addEdge(1, 4);

    // Vertice 2
    grafo.addEdge(2, 0);
    grafo.addEdge(2, 4);

    // Vertice 3
    grafo.addEdge(3, 1);
    grafo.addEdge(3, 4);

    // Vertice 4
    grafo.addEdge(4, 1);
    grafo.addEdge(4, 2);
    grafo.addEdge(4, 3);

    // Recorrido DFS
    grafo.DFS(2);

    return 0;
}