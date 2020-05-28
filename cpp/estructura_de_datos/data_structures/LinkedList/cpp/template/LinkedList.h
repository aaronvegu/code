#ifndef LISTAENLAZADA_H
#define LISTAENLAZADA_H
#include "Nodo.cpp"

template <class d>
class ListaEnlazada
{	
	
	private:
		Nodo<d>* head;
		Nodo<d>* tail;
		
	public:
		ListaEnlazada();
		bool isEmpty();
		void insertFirst(d l);
		void insertLast(d l);
		d peek();
		d extract();
		bool search(d l);
		void toString();
		
		
	
	
};

#endif
