# Filename: if.py

number = 23

print 'Juguemos, intenta adivinar el numero'
guess = int(raw_input('Ingresa un entero: '))

if guess == number:
    print 'Felicidades, has acertado el numero' # Nuevo bloque inicia aqui
    print 'Sin embargo, no has ganado por esto xd' # Bloque finaliza aqui
elif guess < number:
    print 'No acertaste, el numero es mayor'
else:
    print 'No acertaste, el numero es menor'

print 'Programa terminado'
# A diferencia de los otros statements, este ultimo siempre es ejecutado debido a que no 
# esta ligado a ninguna estructura de control o condicion
