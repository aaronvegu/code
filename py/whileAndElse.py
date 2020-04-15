# Python nos permite usar la sentencia While
# y ademas, agregar acciones para cuando esta
# sentencia ha terminado su ejecucion, mediante
# un else que va al final del While:
n = 0
while n < 3:
	print n
	n += 1
else:
	print 'La iteracion ha terminado'

# Y al igual que con otros lenguajes, podemos
# utilizar break para romper la iteracion y 
# pass para solo saltarla
print 'Hola, bienvenido al menu interactivo :)'
while(True):
	print('''Que quieres hacer? Elige una opcion:
		1) Dame amor
		2) Quiero hacer una suma
		3) Volver a ver el menu
		4) Salir
	 ''')
	o = int(input())
	if o == 1:
		print 'Eres arte <3'
	elif o == 2:
		n1 = float(input('Ingresa el primer valor: '))
		n2 = float(input('Ingresa el segundo valor: '))
		print 'El resultado de la suma es: ', n1 + n2
	elif o == 3:
		pass
	elif o == 4:
		print 'bai bai'
		break
	else:
		print 'Opcion no reconocida, intentalo nuevamente'