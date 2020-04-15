# Recorriendo un arreglo 
print 'Recorriendo un arreglo'
numeros = [1,2,3,4,5,6,7,8,9,10]

for numero in numeros:
    print(numero)

# Modificar una lista en ejecucion
print 'Modificando una lista en ejecucion'
numeros2 = [1,2,3,4,5,6,7,8,9,10]

i = 0
for numero in numeros2:
    numeros2[i] *= 10
    i += 1

for numero in numeros2:
    print(numero) 

# Modificacion mediante Enumerate

# Podemos realizar la accion anterior
# de manera mas sencilla mediante
# enumerate, que nos devuelve un indice,
# lo incrementa automaticamente y enumera
# los valores del arreglo.
# la sintaxis es la siguiente:
#   for <indice>, <variableSingular> in enumerate(<arreglo>):

print 'Modificacion mediante Enumerate'

for indice, numero in enumerate(numeros):
    numeros[indice] *= 10

for numero in numeros:
    print(numero) 

# Range
# En otros lenguajes el ciclo For se realiza
# mediante un rango de valores que se van reco
# rriendo, algo que en Python se hace mediante
# un conjunto o arreglo de datos. Pero igual en
# Python podemos hacer uso de un rango de numeros
# mediante la funcion range()
# Esta recibe como parametro el numero final del
# rango, y de manera dinamica o en ejecucion, se
# crea este objeto que contiene un rango de numeros
# especificado, sin realmente tomar memoria del sistema
# range(n) = range(0, n)
print 'Range'
for i in range(6):
    print i
