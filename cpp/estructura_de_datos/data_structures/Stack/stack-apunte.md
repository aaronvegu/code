---
title: "Pila o Stack"
tags: ""
---
###### Clase #6 - 10/febrero/20

## Pilas (stack)

### Introduccion a las Pilas

Basan su funcionamento en la **Operacion o Metodo Push**, lo cual lo convierte en un metodo **LIFO** (Last In First Out), donde el primer dato en ingresar será el ultimo en salir.

Podemos manejar cuatro metodos basicos en una Pila:

-   push()	// Para ingresar un nuevo dato
-   pop()		// Para sacar el dato de arriba
-   isEmpty()		// Devuelve un booleano true si esta vacia la pila
-   peek()	// Imprime el valor superior de la pila

Y estos otros dos para volver más completa nuestra estructura:

-   clear()	// Elimina todos los elementos de la pila
-   toString()	// Imprime el contenido de la pila, sin eliminarlo

## Pseudocodigos de cada metodo

### isEmpty()

    bool isEmpty() {
    	if (top == null) return true;
        else return false;
    }

### peek()

    int peek() {
    	return top->data;
    }

### clear()

    // Manera incorrecta de implementarlo, pues no se limpia la memoria
    void clear() { 
    	top = null;
    }

    // Manera correcta de implementarlo, pues ademas de eliminar el apuntador, tambien los datos se limpian de la memoria
    void clear() {
    	while(top != null) pop();
    }

### push()

    void push(int dato) {
    	if (isEmpty() == true) {
        	Nodo nuevoNodo = new Nodo(dato);
            top = nuevoNodo;
        } else {
        	Nodo nuevonodo = new Nodo(dato);
            Nodo *temporal = top;
            top = nuevoNodo;
            nuevoNodo->next = temporal;
        }
    }

### pop()

    int pop() {
    	
    }
