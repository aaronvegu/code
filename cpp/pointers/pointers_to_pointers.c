// pointers to pointers
#include <stdio.h>

int main()
{
    /*  == Declaraciones ==  */

    // Variable de entero.  M = 504
    int x = 5;

    // Apuntador de entero
    // Apuntador a dir de var x | p apunta a 504
    // M = 807
    int* p = &x;

    // Apuntador de apuntador de entero
    // Apuntador a dir de apuntador p
    // Apunta a 807
    // M = 405
    int** q = &p;

    // Apuntador de apuntador de apuntador a entero
    // Apuntador a dir de apuntador q
    // Apunta a 405
    // M = 643
    int*** r = &q; 

    /*  == Operaciones ==  */

    // Lo que tenga la direccion contenida en 
    // apuntador p, cambiarlo a 6
    // datos en 504 = 6 | 5 = 6
    *p = 6;

    // Imprimir el contenido de la direccion
    // a la que apunta el apuntador p
    // *p = 504 | 504 = 6
    printf("%d\n", *p);

    // Imprimir el contenido de la direccion
    // a la que apunta el apuntador q
    // **q es apuntador de apuntador p que
    // apunta a x.
    printf("%d\n", *q);

    printf("%d\n", **q);

    printf("%d\n", **r);

    printf("%d\n", ***r);

    ***r = 10;

    printf("x = %d\n", x);

    **q = *p + 2;

    printf("x = %d\n", x);

    /**
     * Podemos observar que cuando des-referenciamos
     * un apuntador con los mismos asteriscos con los
     * que fue declarado, se esta llegando al contenido
     * de la variable a la que apunta el primer apuntador
     * de la cadena de apuntadores.
     *   ***r = x, ya que r***   */

    return 0;
}