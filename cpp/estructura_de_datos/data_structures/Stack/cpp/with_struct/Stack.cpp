#include <iostream>
#include <string>
//#include <cstdlib> Dependiendo del compilador podriamos necesitar esta libreria
#include "Stack.h"

using namespace std;

Stack::Stack() 
{	// initialize the stack to be empty
	top = NULL;
}

Stack::~Stack()
{	// deconstructor that delete all the dinamic variables
	/*if (top == NULL) cout << "Nada que borrar" << endl;
	else cout << "Se esta realizando la eliminacion de variables dinamicas..." << endl;*/
	while(!isEmpty()) {
		cout << "Se esta por eliminar top" << endl;
		pop();
		cout << "Top se ha eliminado" << endl;
	}
}

bool Stack::isEmpty() 
{
	return (top == NULL);
}

void Stack::push(int d)
{
	Node *temp = new Node; // creamos un nuevo nodo donde guardar la carga
	temp->data = d; // guardamos la carga en el nodo creado
	temp->next = top; // hacemos que el next del nuevo nodo apunte al top
					  // viejo del stack
	top = temp;	// ahora top apunta al nuevo nodo agregado
}

int Stack::pop()
{
	if (!isEmpty())
	{
		int r = top->data;
		Node *aux = top;
		top = aux->next;
		delete aux;
		return r;
	} else {
		return -1;
	}
}

int Stack::peek()
{
	if(isEmpty()) return -1;
	return top->data;
}

void Stack::clear()
{
	while(!isEmpty()) {
		cout << "Se esta por eliminar top" << endl;
		pop();
		cout << "Top se ha eliminado" << endl;
	}
}

string Stack::toString()
{
	string r = "[ ";
	if (isEmpty()) r += "Pila vacia ";
	else {
		Node *current = top;
		while(current != NULL) {
			r += to_string(current->data) + " ";
			current = current->next;
		}
	}
	r += "]";

	return r;
}
