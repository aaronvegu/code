#include <stdio.h>

int main()
{

    int a = 1025; // Guardamos un entero
    int* p; // Declaramos un apuntador de entero
    p = &a; // Alojamos la direccion del entero en el pointer p
    printf("El tamanio del entero es %d\n", sizeof(int));
    printf("Adress: %d | Valor: %d\n", p, *p);

    char *p0; // Declaramos un puntero de char
    p0 = (char)p; // Casteamos el puntero de entero a char, lo cual hace que pierda precision de lectura
                  // de 4 bytes a 1 byte
    printf("El tamanio del entero es %d\n", sizeof(char));
    printf("Adress: %d | Valor: %d\n", p0, *p0);


    return 0;
}