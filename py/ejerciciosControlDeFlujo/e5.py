i = 0
ns = [None] * 10
print 'Debes ingresar los numeros enteros del 0 al 9'
while i<10:
    ns[i] = int(input('Ingresa el numero: '))
    if ns[i] == i:
        print 'Valor ingresado correctamente'
        i += 1
    else:
        print 'El valor ingresado es incorrecto'
print 'Ejercicio terminado. Numeros ingresados:'
for n in ns:
    print n