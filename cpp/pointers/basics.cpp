#include <iostream>

using namespace std;

int main() {

    // Un puntero o pointer es un tipo de variable que almacena
    // la direccion de otra variable
    int a = 10; // Entero 10
    int *p;     // Puntero de variable int

    p = &a;     // El & nos permite acceder a la ubicacion de la
                // variable, con eso le pasamos la direccion a p

    cout << "Variable a: " << a << endl;
    cout << "Direccion de a desde puntero: " << p << endl;
    cout << "Direccion de a: " << &a << endl;
    cout << "Valor de hacia donde apunta p: " << *p << endl;
    // Esto ultimo que hicimos fue 'des-referenciar' al puntero
    // pues pasamos de su direccion a lo que contiene tal direccion
    cout << "\n";
    // Aritmetica en Apuntadores
    /* Es posible incrementar o decrementar los valores de un pointer,
    con esto lo que se hace aumentar o decrementar la direccion alojada 
    en el puntero, solo que este valor cambiara en el orden del tamanio
    del tipo de dato que es la variable. Por ejemplo un int *p es un puntero
    de tipo int, por lo tanto su tamanio en memoria es de 4 bytes, aumentar
    este puntero en +1 daria como resultado aumentar la direccion en 4
    que son los espacios de memoria de un entero.

    Ejemplo:
    puntero int p = 2000568
    puntaro int p + 1 = 2000572
    */
    int b = 6;
    int *p0 = &b;
    
    cout << "Direccion de p0 es: " << p0 << endl;
    cout << "El tamanio de un entero es " << sizeof(int) << " bytes" << endl;
    cout << "Direccion de p0 + 1 es: " << p0+1 << endl; // Aumenta la ubicacion en +4 bytes

    cout << "\n";

    char c = 'c';
    char *p1 = &c;

    cout << "Direccion de p1 es: " << p1 << endl;
    cout << "El tamanio de un char es " << sizeof(char) << " bytes" << endl;
    cout << "Direccion de p0 + 1 es: " << p1+1 << endl; // Aumenta la ubicacion en +4 bytes

    return 0;
}