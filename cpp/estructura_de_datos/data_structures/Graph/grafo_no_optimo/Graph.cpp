#include <iostream>
#include <vector>

using namespace std;

/**
 * Se creara un Grafo indirecto que almacenara sus Vertices
 * y Edges en dos vectores distintos, uno para los vertices
 * y otro para Edges, donde los vertices seran almacenados
 * en un tipo de dato String y los vertices en su propia
 * estructura EdgeNode que contendra firstVertex y secondVertex
 * para conocer la direccion de los vectores en base a su
 * indice de Vertices en el Vector de Vertices, esto para
 * el caso de los Grafos sin peso, pero si se trata de un Grafo
 * con peso, se agrega al EdgeNode un entero weight para el peso
 * del Edge.
 */ 


// Nodo para almacenar Edges | Grafo sin peso
struct UEdgeNode // UnweightedEdgeNode: Contiene indices del par 
{               //  de vertices que componen un Edge
    int firstVertex; // Indice del primer Vertice
    int secondVertex; // Indice del segundo Vertice
};

// Nodo para almacenar Edges | Grafo con peso
struct WEdgeNode // WeightedEdgeNode
{
    int firstVertex; // Indice del primer Vertice
    int secondVertex; // Indice del segundo Vertice
    int weight; // Peso del Edge
};

// == Estructura basica del Grafo ==
// Creacion de los Vectores para almacenar Vertices y Edges
vector<string> vertices; // Vector de Vertices
vector<UEdgeNode> uEdges; // Vector de Edges para Grafo sin peso
vector<WEdgeNode> wEdges; // Vector de Edges para Grafo con peso

// Representacion Grafica de la Estructura Implementada para el Grafo
/**                       VECTOR DE       VECTOR DE
 *        GRAFO            VERTICES         EDGES     
 *         [A]          Index  Vectice     IV1   IV2    W   
 *        /    \        [ 0 ]   [ A ]     [ 0 ] [ 1 ] [ x ]
 *       /      [D]     [ 1 ]   [ B ]     [ 0 ] [ 3 ] [ x ]
 *      /       /       [ 2 ]   [ C ]     [ 1 ] [ 0 ] [ x ]
 *    [B]---[C]/        [ 3 ]   [ D ]     [ 1 ] [ 2 ] [ x ]
 *                                        [ 2 ] [ 1 ] [ x ]
 *     Donde:                             [ 2 ] [ 3 ] [ x ]
 *     IV1 = Indice Del Primer Vertice    [ 3 ] [ 0 ] [ x ]
 *     IV2 = Indices Del Segundo Vertice  [ 3 ] [ 2 ] [ x ]
 *     IVW = Peso de Edge
 */