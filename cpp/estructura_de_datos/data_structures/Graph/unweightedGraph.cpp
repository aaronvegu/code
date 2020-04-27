// Implementacion de un Grafo indirecto sin peso
#include <iostream>
#include <vector>

using namespace std;

/**
 * Unweighted Graph
 * Se creara un grafo indirecto sin peso haciendo uso
 * de un arreglo de vectores, donde cada indice del 
 * vector representa a un Vertice y el tamanio del 
 * arreglo depende del numero de Vertices V (Array [V]),
 * y cada vector ira almacenando el Edge, donde el
 * vector inicial estara dictado por el indice del 
 * array (osea el vertice) y el valor contenido en 
 * el vector sera el vertice final, quedando asi
 * representado el Edge. 
 **/

// Encontrar la posicion de un valor especifico en el
// vector n (vertice)
int find(vector<int> list[], int vertice, int valor)
{
    int contador = 0;
    for (int i = 0; i < list[vertice].size(); i++)
    {
        if(list[vertice].at(i) == valor) return contador;
        contador++;
    }
    return -1;
}

// Agregar Edge al Grafo
void agregarEdge(vector<int> list[], int primerVertice, int segundoVertice)
{   // Como es bidireccional, por ser un grafo indirecto:
    // Creamos el Edge de vector 1 -> vector 2
    list[primerVertice].push_back(segundoVertice);
    // Creamos el Edge de vector 2 -> vector 1
    list[segundoVertice].push_back(primerVertice);
}

// Eliminar Edge del Grafo
void eliminarEdge(vector<int> list[], int vertice, int valor)
{
    /**
     * Primero obtenemos la posicion en que se encuentra el valor
     * a eliminar, y de no encontrarlo, imprimir valor y terminar
     * funcion.
     **/
    if(find(list, vertice, valor) == -1)
    {
        cout << "Error. Valor no encontrado" << endl;
        return;
    }
    // De encontrarse la posicion:
    // Eliminamos el edge de manera bidireccional
    list[vertice].erase(find(list, vertice, valor));
    list[valor].erase(find(list, valor, vertice));
}

// Imprimir Edges del Grafo por Vertice
void imprimirGrafo(vector<int> list[], int v) // v = numero de vertices
{
    cout << "== Grafo indirecto sin peso | Adjacency List ==" << endl;
    for (int i = 0; i < v; i++)
    {
        cout << "Vertice " << i << ":";
        for (int u = 0; u < list[i].size(); u++)
            cout << " -> " << list[i].at(u);
        cout << "\n";   
    }
}

int main()
{

    const int v = 4; // Numero de Vertices del Grafo
    vector<int> adjacencyList[v]; // Declaramos nuestro array de Vectores

    agregarEdge(adjacencyList, 0, 1);
    agregarEdge(adjacencyList, 0, 2);
    agregarEdge(adjacencyList, 0, 3);
    agregarEdge(adjacencyList, 1, 3);
    agregarEdge(adjacencyList, 2, 3);

    imprimirGrafo(adjacencyList, v);

    eliminarEdge(adjacencyList, 3, 4);

    return 0;
}