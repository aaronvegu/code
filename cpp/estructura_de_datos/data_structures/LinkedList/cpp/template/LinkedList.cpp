#include "ListaEnlazada.h"

template <typename d>
ListaEnlazada<d>::ListaEnlazada(){
	
	head=NULL;
	tail=NULL;
}

template <typename d>
bool ListaEnlazada<d>::isEmpty(){
	
	if(head==NULL) return true;
	else return false;
}

template <typename d>
void ListaEnlazada<d>::insertFirst(d l){
	

	Nodo<d>* n_nuevo = new Nodo<d>(l);
	if(isEmpty()){
		
		head=n_nuevo;
		tail=n_nuevo;
	} else{	
			n_nuevo->setNext(head);
			head=n_nuevo;
	}
}

template <typename d>
void ListaEnlazada<d>::insertLast(d l){
	
	Nodo<d>* n_nuevo= new Nodo<d>(l);
	if(isEmpty()){
		
		head=n_nuevo;
	} else{
		
			tail->setNext(n_nuevo); 	
	}
	tail=n_nuevo;
}

template <typename d>
d ListaEnlazada<d>::peek(){
	
	return head->getLoad();
}

template <typename d>
d ListaEnlazada<d>::extract(){
	
	if(!isEmpty()){
		Nodo<d>* temp=head;
		d retornar=temp->getLoad();
		head=head->getNext();
		free(temp);
		return retornar;
		
		} else{
				
			return 'e';
		}
}

template <typename d>
bool ListaEnlazada<d>::search(d l){
	
	Nodo<d>* temp=head;
	d Sload=temp->getLoad();
	while(temp->getNext()!=NULL && Sload!=l){
		
		temp=temp->getNext();
		Sload=temp->getLoad();
	}
	if(Sload==l) return true;
	else return false;
}

template <typename d>
void ListaEnlazada<d>::toString(){
	
	std::cout<<"hola";
	
}
