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

    // MIN 6:20
}