---
title: "Linked-List"
tags: ""
---
## Lista Enlazada

Una Linked-List o Lista Enlazada es una estructura de datos lineal que basicamente consiste en la union de varios nodos enlazados mediante punteros, ya que no hacen uso de espacios de memoria contiguos.

Una de las grandes ventajas que tiene una Lista enlazada contra, por ejemplo, un arreglo es el hecho de que la distribucion de los datos puede distribuirse en distintos puntos de memoria y crecer dinamicamente, a diferencia de los arreglos, donde es necesario declarar el espacio de memoria que contendra, lo cual lleva a reservar un espacio de memoria continuo que podria no ser aprovechado en su totalidad o requerir de mayor espacio, cuando no es posible aumentar el tamaño de un arreglo ya creado.

Cuando un arreglo alcanza su valor maximo de memoria, una solucion seria crear un nuevo arreglo de mayor tamaño, copiar el arreglo anterior en el nuevo arreglo y liberar el espacio de memoeria del arreglo viejo, lo cual es costoso en tiempos de ejecucion y aprovechamiento de memoria. Por el lado de las listas enlazadas, esta crece dinamicamente conforme se necesita mayor espacio, pues lo unico que se hace es crear un nuevo nodo y añadirlo a la lista con el puntero, lo cual nos da los siguientes rendimientos:

-   Acceso a elementos = O(n)
-   Insercion = O(n)

Ya que acceder e insertar elementos toma el tiempo en base a el numero de elementos que conforman la estructura, lo cual nos da O(n), donde n es el numero de elementos.

Para su implementacion se necesita crear un nodo con un puntero al siguiente nodo y un espacio para la carga del nodo, quedando de la siguiente manera (expresado en c++):

```cpp
struct Node {
    int load; // Carga
    Node *next; // Puntero al siguiente nodo
}
```

Y ya en su implementacion, de manera visual se tendria algo como lo siguiente:

    HEAD--> [3][x03202]-->[4][x0097]-->[5][x8764]--> Ground

Donde se tiene primero la carga y despues el puntero al siguiente nodo, asi como tambien es necesario contar con un puntero a la Cabeza o Head de la lista, desde el cual se inicia el recorrido por la lista enlazada y sus distintos nodos.

En el sitio del NIST no existen especificaciones sobre los metodos con los que debe contener una lista enlazada, sin embargo, tiene documentacion en C++ que establece los siguientes metodos para la estructura:

    1. int NumItems();
    2. bool Empty();
    3. void InsertFront();
    4. void InsertRear();
    5. void InsertInOrder();
    5. ItemType RemoveFront();
    6. ListNodePtr Find();

Tal informacion se obtuvo del siguiente sitio: <https://cis.stvincent.edu/html/tutorials/swd/lists/lists.html>
