# En Python, a diferencia de otros lenguajes SI
# podemos guardar distintos tipos de datos en un
# arreglo, sean flotantes, enteros, cadenas, etc

arreglo = [1,2,3,4,5,6]
arregloMultiDatos = [1, 2.15, -15, "Una cadena", 400, "Otra cadena"]

print("Arreglo convencional:")
print(arreglo)
print("Arreglo con distintos tipos de datos")
print(arregloMultiDatos)

# Asignacion de datos mediante indices
pares = [2,4,5,8,10]
print("Arreglo incorrecto:")
print(pares)
pares[2] = 6;
print("Arreglo corregido mediante asginacion por indice:")
print(pares)

# Asignacion mediante metodos
#	Metodo append()
pares.append(12)
print(pares)

pares.append(7*2)
print(pares)

# Asignacion mediante Slicing
pares[:3] = ['dos', 'cuatro', 'seis']
print(pares)

# Arreglos Anidados
# Podemos contener arreglos dentro de otros arreglos
# tal como si se tratara de matriz
a = [1,2,3]
b = [4,5,6]
c = [7,8,9]
d = [a,b,c] # Aqui estamos aninando los arreglos a,b y c
# en el arreglo d
print('// Listas Anidadas //')
print(d)

# Y podemos acceder a ellas tal como si se tratara de una
# Matriz, pues es justamente lo que son:
print("El valor 1,1 de la matriz d (3x3):")
print(d[1][1]) 

# Longitud de arreglos
print("Longitud del arreglo d")
print(len(d))