# Filename: continue.py

while True :
    s = raw_input('Escribe algo: ')
    if s == 'salir' :
        break
    if len(s) < 3 :
        continue    # La iteracion se salta solo cuando es menor a 3 
    print 'La longitud de lo escrito es igual o mayor a 3'
print 'Programa Terminado'
