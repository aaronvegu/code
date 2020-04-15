a = input('Ingrese un numero entero: ')
b = input('Ingrese un segundo numero entero: ')
o = 0

print '''// Menu //
1. Sumas ambos numeros
2. Restar ambos numeros
3. Multiplicar ambos numeros'''

o = int(input('Elige una opcion del menu: '))

if o == 1:
    print 'La suma es: ', a + b
elif o == 2:
    print 'La resta es: ', a - b
elif o == 3:
    print 'La multiplicacion es: ', a * b
else:
    print 'Opcion no valida'