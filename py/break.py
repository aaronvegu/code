# Filename: break.py

while True :
    s = raw_input('Escribe algo: ')
    if s == 'salir' :
        break
    print 'La longitud de lo escrito es', len(s)
print 'Programa Terminado'
