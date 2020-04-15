from collections import deque
# Pilas y Colas en Python
# En otros lenguajes se cuetan con estas estructuras
# integradas en librerias propias del lenguaje, pero 
# en Python no es asi, por lo tanto es necesario imple-
# mentarlas mediante listas

pila = [3,4,5]
pila.append(6)
pila.append(7)

print '// Pilas //'
print 'Pila:',pila
print 'Pop:',pila.pop()
print 'Pop:',pila.pop()
print 'Pop:',pila.pop()
print 'Pila:',pila

# Aqui podemos ver que las listas de Python ya nos
# permiten trabajarlas como si fueran una pila me-
# diante su metodo pop(), que tienen el mismo com-
# portamiento que las pilas
print '// Colas //'
# Colas (Queue)
# Para su utilizacion es necesario importar el objeto
# deque desde collections, tal como lo hemos hecho en
# la primera linea.

# Ya solo restaria implementarla de la siguiente manera:
cola = deque(['Juan', 'Aldo', 'Christian'])

print cola

# E ingresarle datos con append()
cola.append('Maria')
cola.append('Antonio')

print cola

# Ahora bien, para realiar un Dequeue, tal como debe
# de ser para una cola, siguiendo el orden FIFO, ha-
# cemos uso del metodo propio de deque: popleft()

print cola.popleft()
print cola.popleft()
print cola.popleft()