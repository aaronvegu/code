// Dijsktra algorithm implementation in C++
// By: Aaron Vegu

#include <iostream>
#include <list>
#include <utility>
#include <vector>
#include <set>

#define INF 1000000

using namespace std;

class Graph
{
private:
    // Numero de Vertices
    int V;
    // Puntero a Lista de Adyacentes con valor y peso
    list<pair<int, int> > *adj;
public:
    // Constructor
    Graph(int v);
    // Metodo para agregar edge's
    void addEdge(int v1, int v2, int weight);
    // Metodo para encontrar el camino mas corto en el grafo
    void shortestPath(int s);
};

// Constructor
Graph::Graph(int v)
{
    // Inicializamos num de vectores
    V = v;
    // Creamos la lista
    adj = new list<pair<int, int> >[v];
}

// Implementacion del metodo para agregar edges
void Graph::addEdge(int v1, int v2, int weight)
{
    adj[v1].push_back(make_pair(v2, weight));
}

// Implementacion del metodo para encontrar la ruta mas corta
void Graph::shortestPath(int s)
{
    // Creamos un conjunto para guardar vertices
    // Este conjunto sera utilizado para extraer
    // la ruta mas corta en el grafo
    set<pair<int, int> > set_vertices;

    // Creamor un vector para alojar las distancias
    // Se inicializa con todas las distancias en un numero
    // grande
    vector<int> distances(V, INF);

    // Ingresamos el punto de entrada en nuestro set de
    // vertices e inicializamos su distancia en 0
    set_vertices.insert(make_pair(0, s));
    distances[s] = 0;

    // Iteramos hasta que terminamos de encontrar todas las
    // distancias mas cortas
    while (!set_vertices.empty())
    {
        // Extraemos las distancias minimos y guardamos la
        // distancia de entrada definida anteriormente en tmp
        pair<int, int> tmp = *(set_vertices.begin());
        set_vertices.erase(set_vertices.begin());

        // Obtenemos el numero de vertice de la distancia
        int u = tmp.second;

        // Iteramos nuestra adjacency list
        for(auto i = adj[u].begin(); i != adj[u].end(); i++)
        {
            // Obtenemos el vertice y su peso
            int v = (*i).first;
            int weight = (*i).second;

            // Revisamos si tenemos un camino mas corto para llegar
            // a v
            if(distances[v] > distances[u] + weight)
            {
                // Eliminamos la distancia actual si se encuentra en el set
                if(distances[v] != INF)
                    set_vertices.erase(set_vertices.find(make_pair(distances[v], v)));

                // Actualizamos la distancia
                distances[v] = distances[u] + weight;
                set_vertices.insert(make_pair(distances[v], v));
            }
        }
    }
    
    cout << "Distancias minimas encontradas desde el vertice: " << s << endl;
    for (int i = 0; i < V; i++)
    {
        cout << "Vertice: " << i << "\tDistancia: " << distances[i] << endl;
    }
    
}

int main()
{
    // Creamos nuestro grafo
    Graph grafo(9);

    // Inicializamos vertices y pesos a cada conexion o edge
    // Nodo 0
    grafo.addEdge(0, 1, 4);
    grafo.addEdge(0, 7, 8);

    // Nodo 1
    grafo.addEdge(1, 0, 4);
    grafo.addEdge(1, 7, 11);
    grafo.addEdge(1, 2, 8);

    // Nodo 2
    grafo.addEdge(2, 1, 8);
    grafo.addEdge(2, 8, 2);
    grafo.addEdge(2, 3, 7);

    // Nodo 3
    grafo.addEdge(3, 2, 7);
    grafo.addEdge(3, 4, 9);
    grafo.addEdge(3, 5, 14);

    // Nodo 4
    grafo.addEdge(4, 3, 9);
    grafo.addEdge(4, 5, 10);

    // Nodo 5
    grafo.addEdge(5, 4, 10);
    grafo.addEdge(5, 3, 14);
    grafo.addEdge(5, 6, 2);

    // Nodo 6
    grafo.addEdge(6, 5, 2);
    grafo.addEdge(6, 8, 6);
    grafo.addEdge(6, 7, 1);

    // Nodo 7
    grafo.addEdge(7, 6, 1);
    grafo.addEdge(7, 8, 7);
    grafo.addEdge(7, 1, 11);
    grafo.addEdge(7, 0, 8);

    // Nodo 8
    grafo.addEdge(8, 2, 2);
    grafo.addEdge(8, 6, 6);
    grafo.addEdge(8, 7, 7);

    // Dijkstra Algorithm method
    grafo.shortestPath(0);

    return 0;
}