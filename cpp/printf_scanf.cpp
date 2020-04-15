// Filename: printf_scanf.cpp

#include <iostream>
#include <cstdio>

using namespace std;

int main() {
    int i; // integer
    long l; // long
    char c; // char
    float f; // float
    double d; // double

    // Para usar scanf y printf, antes debemos especificar el tipo de valor a recibir o imprimir:
    // Int ("%d"): 32 Bit integer
    // Long ("%ld"): 64 bit integer
    // Char ("%c"): Character type
    // Float ("%f"): 32 bit real value
    // Double ("%lf"): 64 bit real value

    scanf("%d %ld %c %f %lf", &i, &l, &c, &f, &d);
    printf("%d", i);
    cout << "\n";
    printf("%ld", l);
    cout << "\n";
    printf("%c", c);
    cout << "\n";
    printf("%.2f", f);
    cout << "\n";
    printf("%lf", d);
    cout << "\n" << "End" << endl;

    return 0;
}
