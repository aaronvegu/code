# Filename: while.py

number = 23;
flag = True; # Es importante que el valor booleano se escriba con mayuscula al principio

print 'Intenta adivinar el numero'

while flag:
    guess = int(raw_input('Ingresa un numero: '))

    if guess == number:
        print 'Has acertado, gracias por jugar :)'
        flag = False # Esto detendra el while loop
    elif guess < number:
        print 'Upss, el numero por adivinar es mayor, suerte para la proxima'
    else:
        print 'Nop, te has pasado, el numero es menor, sigue intentando'
else:
    print 'El juego ha terminado'
