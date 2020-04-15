include <iostream>

// Filename: node.cpp

using namespace std;

struct nodo {
	char dato;
	nodo *next;
};

int main(int argc, char const *argv[]) {
	// Se crean los nodos y se les da contenido mediante 
	// la variable dato que existe en el cuerpo del nodo
	nodo a;
	a.dato = '1';
	nodo b;
	b.dato = '2';
	nodo c;
	c.dato = '3';
	// Se enlazan los next hacia los subsiguientes nodos
	a.next = &b;
	b.next = &c;
	// Se enlaza el primer apuntador para iniciar la cadena de nodos
	nodo *algo = &a;
	// Iteramos la continuacion de la cadena hasta que el apuntador next
	// apunte a NULL, osea que ya no existe otra direccion
	while(algo->next != NULL) {
		cout << algo->dato << '\n';
		algo = algo->next;
	}

	return 0;
}
