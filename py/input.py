# Tomar valores introducidos por medio del teclado
# En Python se usa la funcion input() para tomar 
# valores que el usuario ingresa por el teclado

valor = input("Ingresa un numero entero o flotante: ")

print(valor)

# Los valores guardados mediante la funcion print()
# son tomados como conjunto de caracteres, es por 
# eso que si queremos utilizar el valor como entero
# o flotante, debemos convertirlos a ese tipo de dato

# Entero
int(valor)
print 'valor + 5 =', valor + 5 # Podemos usarlo asi
# sin hacer uso de los parentesis

# Flotante
float(valor)
print(valor + 4.5)