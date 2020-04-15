//
//  main.cpp
//  contador_fecha
//
//  Created by Aaron Vegu on 07/03/20.
//  Copyright © 2020 Aaron Vegu. All rights reserved.
//

#include <iostream>

using namespace std;
/*
bool esBisiesto(int anio) {
    if ((anio%4 == 0 &&))
    
    return true;
}
*/
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

int calcularDias(int d, int m) {
    int total = 0;
    if (m <= 12) {
        for (int i = m-1; i > 0; i--) {
            if (i == 2) {
                total += 28;
                continue;
            }
            if (i < 8 && i % 2 != 0) {
                total += 31;
                continue;
            }
            else if (i < 8 && i % 2 == 0) {
                total += 30;
                continue;
            }
            else if (i > 7 && i % 2 != 0) {
                total += 30;
                continue;
            }
            else {
                total += 31;
                continue;
            }
        }
        return total + d;
    } else return total;
}

int diasPorAnio(int anioNac, int anioClase) {
    if (anioNac > anioClase) return 0;
    int total, diferencia = anioClase - anioNac;
    return total = (diferencia * 365) + contarBisiestos(anioNac, anioClase);
}

int main(int argc, const char * argv[]) {
    // Declaracion de variables locales
    int anioNac, mesNac, diaNac, anioClase, mesClase, diaClase, diasAnioClase, diasAnioNac, diasTotales;
    
    // Peticion de datos al usuario
    cout << "// Iniciamos con la fecha de nacimiento //" << endl;
    cout << "Ingresa el dia de nacimiento (formato dd): ";
    cin >> diaNac;
    cout << "Ingresa el mes de nacimiento (formato mm): ";
    cin >> mesNac;
    cout << "Ingresa el año de nacimiento (formato aaaa): ";
    cin >> anioNac;
    if (anioNac)
    cout << endl;
    cout << "// Continuamos con la fecha de la clase //" << endl;
    cout << "Ingresa el dia de la clase (formato dd): ";
    cin >> diaClase;
    cout << "Ingresa el mes de la clase (formato mm): ";
    cin >> mesClase;
    cout << "Ingresa el año de la clase (formato aaaa): ";
    cin >> anioClase;
    
    // Calculo de los dias
    diasAnioNac = calcularDias(diaNac, mesNac);
    diasAnioClase = calcularDias(diaClase, mesClase);
    diasTotales = diasAnioClase - diasAnioNac;
    diasTotales += diasPorAnio(anioNac, anioClase);
    
    // Impresion del resultado
    cout << endl;
    cout << "Han pasado " << diasTotales << " dias" << endl;
    
    return 0;
}
