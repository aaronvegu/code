// Breadth First Search Algorithm
// By: Aaron Vegu 2020

#include <iostream>
#include <list>
#include <vector>

using namespace std;

class Graph // Iniciamos clase del Grafo
{
    private:
    // Numero de Vertices del Grafo
    int V;
    // Puntero a nuestra adjacency list
    vector< list<int> > adj;

    public:
    // Constructor
    Graph(int v);
    // Metodo para agregar un Edge
    void addEdge(int v, int w);
    // Metodo para realizar un recorrido BFS
    void BFS(int s); // s es el punto de inicio de la busq
};

Graph::Graph(int v)
{
    // Se declaran los vertices del Grafo
    V = v;
    // Ordenamos el numero de listas dentro del vector
    adj.resize(v);
}

// Implementacion del metodo addEdges
void Graph::addEdge(int v, int w) { adj[v].push_back(w); }

// Teniendo un vertice de entrada s, se inicia el recorrido BFS
void Graph::BFS(int s)
{
    // Creamos un vector de booleanos, inicializados en False
    vector<bool> visited(V);

    // Creamos una Cola para los vertices que seran visitados
    // por BFS
    list<int> queue;

    // El vertice de inicio s es marcado como visitado en 
    // nuestro vector booleanos de visitados, y ademas lo
    // agregamos a la cola de BFS
    visited[s] = true;
    queue.push_back(s);

    // Iteramos hasta que la cola de BFS este vacia
    while (!queue.empty())
    {
        // Obtenemos y guardamos el frente de la cola y la 
        // eliminamos
        s = queue.front();
        queue.pop_front();

        // Ahora obtenemos todos los vertices adyacentes al
        // vertice obtenido del frente
        cout << "Revisando los vertices adyacentes del vertice " << s << endl;
        for (auto i : adj[s])
        {
            // Solo tomaremos aquellos vertices que no han sido visitados
            if (!visited[i])
            {
                // Lo marcamos como visitado
                cout << i << " | Visitado y agregado a la cola BFS" << endl;
                visited[i] = true;
                // Lo agregamos a la cola de BFS
                queue.push_back(i);
            }
        }
    }
}

int main()
{
    // Creamos un Grafo de 5 vertices
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

    grafo.BFS(2);

    return 0;
}