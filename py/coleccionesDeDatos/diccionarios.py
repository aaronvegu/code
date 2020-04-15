# Diccionarios
# Los diccionarios son conjuntos de datos almacenados
# mediante una estructura mapeada de su contenido, 
# donde cada elemento de la coleccion se encuentra 
# identificado mediante una clave unica.  
# En otros lenguajes podrian ser similares a los 
# arreglos asociativos

# Los diccionarios son estructuras DESORDENADAS

# sintaxis:
# nombre = {clave:dato}

# podemos acceder a los datos mediante la clave
# nombre[clave] = dato

# diccionario vacio
dicVacio = {}

# podemos comprobar que es un diccionario con la
# funcion type()
print type(dicVacio) # output = dict

# creando un diccionario
colores = {'amarillo':'yellow', 'azul':'blue', 'rojo':'white'}

# accediendo al valor mediante su clave
print colores['azul']

# modificando valores mediante su clave
colores['rojo'] = 'red'
print colores

# eliminado mediante su clave
del(colores['amarillo'])
print colores

# podemos hacer operaciones algebraicas con sus valores
edades = {'Juan':24, 'Maria':32, 'Hector':39}
total = 0
for edad in edades:
    total += edades[edad]
print 'Total de edades:', total

# Se usa items() para obtener la clave y el valor de cada
# elemento en un diccionario. La sintaxis es la siguiente:
# for <clave>,<valor> in <diccionario>.items():
for c,v in edades.items():
    print c, v

# Estructuras complejas con diccionarios
# Podemos combinar listas con diccionarios para guardar
# datos de manera compleja. Por ejemplo una lista de 
# personajes con atributos:
personajes = []
p1 = {'Nombre':'Gandalf', 'Clase':'Mago', 'Raza':'Humano'}
p2 = {'Nombre':'Legolas', 'Clase':'Arquero', 'Raza':'Elfo'}
p3 = {'Nombre':'Gimli', 'Clase':'Guerrero', 'Raza':'Enano'}
personajes.append(p1)
personajes.append(p2)
personajes.append(p3)
print '\nLista de personajes:'
for p in personajes:
    print p['Nombre'], 'el', p['Clase'], p['Raza']