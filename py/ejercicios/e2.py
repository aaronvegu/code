cadena = input("Ingrese una cadena de texto: ")
if (len(cadena) >= 3 and len(cadena) < 10):
	print 'La cadena introducida contiene minimo 3 o mas caracteres pero menos de 10'
else:
	print 'La cadena introducida es menor a 3 o tiene mas de 10 caracteres'