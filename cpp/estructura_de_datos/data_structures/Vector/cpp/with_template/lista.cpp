#include "list.h"
#include <stdlib.h>
 
using namespace std;

template<typename T>
List<T>::List(){
	head = NULL;
	tail = NULL;
}

template<typename T>	
void List<T>::newNode(T value){
	Node<T> *node = new Node<T>();
	node->setValue(value);
	node->setNext(NULL);
	if(head==NULL){
		head = node;
		tail = node;
	}else{
		tail->setNext(node);
		tail = node;
	}
}

template<typename T>
void List<T>::buildVector(){
	for(int i=0;i<10;i++){
		newNode(-1);
	}
}

template<typename T>
int List<T>::capacity(){
	int i = 0;
	Node<T> *current = head;
	while(current!=NULL){
		i++;
		current = current->getNext();
	}
	return i;
}

template<typename T>
int List<T>::size(){
	int i = 0;
	Node<T> *current = head;
	while(current!=NULL){
		if(current->getValue()!=-1){
			i++;	
		}
		current = current->getNext();
	}
	return i;
}

template<typename T>
int List<T>::freeAt(){
	int i = 1;
	Node<T> *current = head;
	while(current!=NULL){
		if(current->getValue()==-1){
			return i;
		}
		i++;
		current = current->getNext();
	}
	return i;
}

template<typename T>
bool List<T>::isFull(){
	Node<T> *current = head;
	while(current!=NULL){
		if(current->getValue()==-1){
			return false;	
		}
		current = current->getNext();
	}
	Node<T> *node = head;
	while(node!=NULL){
		if(node->getNext()==NULL){
			for(int i=0;i<5;i++){
				newNode(-1);
			}
			break;
		}
		node = node->getNext();
	}
	return true;
}

template<typename T>
bool List<T>::contains(T value){
	Node<T> *current = head;
	while(current!=NULL){
		if(current->getValue()==value){
			return true;
		}
		current = current->getNext();
	}
	return false;
}

template<typename T>
bool List<T>::add(T value){
	if(isFull()){
		if(contains(value)){
			cout<<"\nYour value has not been add, because there exists."<<endl;
			return false;
		}else{
			Node<T> *current = head;
			while(current!=NULL){
				if(current->getValue()==-1){
					current->setValue(value);
					break;
				}
				current = current->getNext();
			}
			cout<<"\nYour value has been successfully added."<<endl;
			return true;
		}
	}else{
		if(contains(value)){
			cout<<"\nYour value has not been add, because there exists."<<endl;
			return false;
		}else{
			Node<T> *current = head;
			while(current!=NULL){
				if(current->getValue()==-1){
					current->setValue(value);
					break;
				}
				current = current->getNext();
			}
			cout<<"\nYour value has been successfully added."<<endl;
			return true;
		}
	}
}

template<typename T>
T List<T>::get(T i){
	int var = 0;
	Node<T> *current = head;
	while(current!=NULL){
		if(var==i){
			return current->getValue();
		}
		var++;
		current = current->getNext();
	}
	return NULL;
}

template<typename T>
bool List<T>::remove(T value){
	if(contains(value)){
		Node<T> *current = head;
		while(current!=NULL){
			if(current->getValue()==value){
				current->setValue(-1);
				break;
			}
			current = current->getNext();
		}
		cout<<"\nYour value has been successfully removed."<<endl;
		return true;
	}else{
		cout<<"\nYour value has not been removed, because there is not exists."<<endl;
		return false;
	}
}

template<typename T>
bool List<T>::removeAt(T i){
	int var = 0;
	Node<T> *current = head;
	while(current!=NULL){
		if(var==i){
			if(current->getValue()!=-1){
				current->setValue(-1);
				cout<<"\nYour value has been successfully removed."<<endl;
				return true;
			}else{
				cout<<"\nYour value has not been removed, because there is not exists."<<endl;
				return false;
			}
		}
		var++;
		current = current->getNext();
	}
	cout<<"\nYour value has not been removed, because there is not exists."<<endl;
	return false;
}

template<typename T>
void List<T>::toString(){
	Node<T> *current = head;
	if(current->getNext()==NULL){
		cout<<"\nThe value of the Vector is: \n\n{";
	}else{
		cout<<"\nThe values of the Vector are: \n\n{";
	}
	while(current!=NULL){
		if(current->getNext()==NULL){
			cout<<current->getValue();
		}else{
			cout<<current->getValue()<<",";
		}	
		current = current->getNext();
	}
	cout<<"}\n";
}	

template<typename T>
void List<T>::clear(){
	while(head!=NULL){
		Node<T> *current = head;
		head = head->getNext();
		free(current);
	}
	buildVector();
	cout<<"\nThe Vector is clear successfully."<<endl;
}
