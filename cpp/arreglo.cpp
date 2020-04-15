#include <iostream>

// Filename: arreglos.cpp

using namespace std;

int main(int argc, char const *argv[]) {
	char datos[] = "Aaron Vegu, Estudiante de ICCO"; // Aqui creamos un arreglo de caracteres
	cout << "Este es el contenido del arreglo: " << datos << '\n'; // Muestra el contenido de la variable
	cout << "En realidad, la variable apunta a un: " << *datos << '\n'; // Muestra exactamente lo que contiene hacia donde apunta el dato pasado (A que le apuntas)
	cout << "Ese caracter anterior, esta guardado en: " << &datos << '\n'; // Muestra la ubicacion fisica en memoria de esa variable (A donde apuntas)

	return 0;
}
