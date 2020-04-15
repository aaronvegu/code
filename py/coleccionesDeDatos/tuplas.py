# Tuplas
# Las tuplas, al igual que los arreglos, son estructuras
# que alojan un conjunto de datos, con la diferencia de que
# este conjunto de datos es inmutable. Lo cual nos sirve para
# asegurarnos que tenemos datos que no pueden ser editados

# Sintaxis: nombre = (datos)

tupla = (1, 2, 3, 'String', [9, 8, 7], -50, 2)
# Son capaces de almacenar distintos tipos de datos

# Las tuplas aceptan indexacion y slicing
print tupla[1] # Indexacion
print tupla[2:] # Slicing

# Tambien podemos acceder a su longitud, e incluso a
# la longitud de listas dentro de la tupla
print len(tupla)
print len(tupla[4])

# Podemos buscar elementos dentro de la tupla con index()
print tupla.index('String') # Arroja error de ser false

# Saber si se repite un valor y cuantas veces
print tupla.count(2)