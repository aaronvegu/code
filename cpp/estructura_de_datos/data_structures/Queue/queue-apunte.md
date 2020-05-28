---
title: "Colas"
tags: ""
---
###### Clase #3 - 27/enero/20

## Colas

### Estructura basica de una Cola o Queue

De manera basica, una cola necesita dos apuntadores:

    1. Head // Apunta al primer nodo
    2. Tail // Apunta al nodo que su next() apunta a null (ground)

Y tres operaciones

    1. enqueue() // Encolar
    2. dequeue() // Sacar de la cola
    3. clear()

Las colas siguen la modalidad FIFO.

## 

Pasos para agregar un nuevo nodo:

    1. Se crea el nodo con su valor
    2. El *next del nodo anterior apunta al nuevo nodo
    3. El tail se apunta al *next del nuevo nodo (null)
    // Es importante seguir estos pasos, para no perder apuntadores

Pasos para una operacion dequeue(), que elimina un nodo:

    1. Se crea un auxiliar que almacene el apuntador del nodo a borrar
    2. Y head ahora es head.next. Esto significa que el head es ahora el next del nodo a eliminar
    3. Se retorna la carga del nodo mediante el auxiliar guardado
    4. Se elimina el nodo
    5. Se elimina el apuntador auxiliar

#### Nota: En una cola no se puede acceder a un elemento que no este en la cabeza, significa que no podemos saltar valores, pues una cola solo tiene las siguientes tres operaciones: enqueue(), dequeue() y clear(). Asi como no se puede BUSCAR en una cola.

Veremos la estructura y pasos para crear una operacion dequeue()

```c++
// Creacion de la funcion dequeue()
int dequeue() {
	nodo* auxiliar;
    auxiliar = head; // ahora auxiliar es la nueva cabeza de la cola
    head = head.next;
    int r = auxiliar.carga;
    delete *aux; // Elimina de memoria a lo que apunta el apuntador
    return r;
}
```

Creacion de una operacion enqueue()

```cpp
void enqueue(int a) {
	if(head != NULL) { // 
    	nodo n = new nodo(a);
        tail.next = &n;
        tail = n;
    }
    nodo n = new nodo(a);
    head = n;
    tail = n;
}
```
