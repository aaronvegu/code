
#include <iostream>
#include "ListaEnlazada.cpp"
using namespace std;

int main(){
	
	ListaEnlazada<char> l;
	l.insertFirst('z');
	l.insertFirst('r');
	cout<<l.peek()<<"\n";
	l.extract();
	cout<<l.peek()<<"\n";
	cout<<l.search('z');
	


	return 0;
}

