//
//  main.cpp
//  Practica3
//
//  Created by Sebastian Fuentes on 10/03/20.
//  Copyright © 2020 El Sebas S.A de C.V. All rights reserved.
//

#include <iostream>

using namespace std;

// Definimos estructura que alojara fechas
struct fecha { // Aqui guardaremos las fechas ingresadas por el usuario
    int dia, mes, anio;
} f [3];

// Crear funcion que determine si el anio es o no bisiesto
bool esBisiesto(int anio) {
    if ((anio%4==0 && anio%100!=0) || anio%400==0) {
        return true;
    }
    return false;
};

// Crear Funcion que nos calcule el numero de dias que han transcurrido
// del anio, en base a una fecha dada
int contarDias(int dia, int mes, int anio) {
    int total = 0; // Inicializamos variable a retornar
    
    for (int ms = 1; ms < mes; ms++) {
    
        if (mes > 12 || dia > 31 || anio <= 0 || anio >= 2021) {
            cout << "Buen intento, no me engañas" << endl;
            exit(1);
        } else {
            if (mes == 2) { // Si es febrero
                total += 28;
                continue;
            }
            if (mes>=1 && mes<8) { // Si es Enero o de Marzo a Julio
                if (mes%2==0) { // si es par
                    total += 30;
                    continue;
                } else {
                    total += 31;
                    continue;
                }
            }
            if (mes>7 && mes<=12) { // Si es de Agosto a Diciembre
                if (mes%2==0) { // si es par
                    total += 31;
                    continue;
                } else {
                    total += 30;
                    continue;
                }
            }
        }
        
    }
    
    total += dia;
    
    return total;
}

int contarBisiestos(int a, int b) {
    int t = 0;
    for(int i = a; i <= b; i++) {
        if (i <= 100) {
            if (i%4==0) t++;
        } else {
            if ((i%4==0 && i%100!=0)||i%400==0) t++;
        }
    }
        
    return t;
}

int diasPorAnio(int anioNac, int anioClase) {
    if (anioNac > anioClase) {
        exit(1);
        return 0;
    }
    int total, diferencia = anioClase - anioNac;
    return total = (diferencia * 365) + contarBisiestos(anioNac, anioClase);
}

int main(int argc, const char * argv[]) {
    
    // Definimos la fecha de la clase, que sera alojada en el indice 0
    f[0].dia = 4;
    f[0].mes = 3;
    f[0].anio = 2020;
    
    // Solicitar la fecha de nacimiento, que guardaremos en el indice 1
    cout << "Dame el dia de tu cumpleaños: " << endl;
    cin >> f[1].dia;
    cout << "Dame el mes de tu cumpleaños: " << endl;
    cin >> f[1].mes;
    cout << "Dame el anio de tu cumpleaños: " << endl;
    cin >> f[1].anio;
    
    // Comprobamos que el dia exista
    if (f[1].mes == 2 && f[1].dia > 28 && !esBisiesto(f[1].anio)) {
        cout << "Fecha no valida" << endl;
        exit(1);
    }
    
    // Obtener diferencia de Anios. Que seran alojados en el indice 2
    f[2].anio = f[0].anio - f[1].anio;
        // diferenciaAnios = aniosClase - aniosNacimiento = f[0].anio - f[1].anio

    int diasNac = contarDias(f[1].dia, f[1].mes, f[1].anio);
    int diasClase = contarDias(f[0].dia, f[0].mes, f[0].anio);
    int diasTotales = diasClase - diasNac;
    diasTotales += diasPorAnio(f[1].anio, f[0].anio);
    int anios = diasTotales / 365;
    diasTotales -= (anios * 365);
    int meses = diasTotales / 30;
    diasTotales -= (meses * 30);

    cout << "Han pasado " << anios << " año(s) " << meses << " mes(es) " << diasTotales << " dias." << endl;
}
