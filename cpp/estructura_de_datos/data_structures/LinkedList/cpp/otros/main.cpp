#include <iostream>
#include "LinkedList.h"

using namespace std;

int main() {

	LinkedList lista;
	cout << lista.isEmpty() << endl;
	lista.insertFirst(5);
	cout << lista.isEmpty() << endl;
	lista.insertFirst(6);
	cout << lista.extract() << endl;
	cout << lista.extract() << endl;

	return 0;
}