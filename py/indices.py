# En python podemos trabajar las cadenas o string como
# lo que son: un array de caracteres, y acceder a su contenido
# mediante el uso de indices, e incluso aun mas potente,
# usar slicing para mostrar ciertas longitudes de caracteres
# dentro de su arreglo

s = "Python"

print(s)

# Accedemos a un indice especifico
print(s[0])

# O a varios indices y los concatenamos
print(s[0] + s[1])

# Para ello podemos utilizar slicing, que toma el primer
# indice y lo recorre hasta el -n del ultimo indicado
# Por ejemplo:
print(s[0:2]) # = a [0] + [1], donde [1] es igual a [2-1]

# Usando slicing, podemos dejar indices vacios para indicar
# que queremos que inicie desde el principio o termina al final:
print(s[:4]) # Inicia desde 0 y termina hasta el indice 4
print(s[2:]) # Inicia desde el indice 2 y termina hasta el final

# En Python las cadenas son inalterables mediante asignacion de
# valores, lo que significa que no podemos cambiar el indice 0
# por "N" asi: s[0] = "N"
# Pero si podriamos hacerlo mediante concatenacion y omision de
# indices:
print("N" + s[1:]) # ;)