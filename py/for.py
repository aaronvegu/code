# Filename: for.py

number = 23

print '''Vamos a jugar, acierta el numero.
tienes 3 oportunidades para acertar'''

for i in range(1, 4) :
    print('Oportunidad #{0}'.format(i))
    guess = int(raw_input('Ingresa el numero: '))
    
    if guess == number:
        print 'Has acertado!'
        break
    else:
        print 'No acertaste'
else:
    print '''No has acertado, tus oportunidades se terminaron.
Suerte para la proxima'''
