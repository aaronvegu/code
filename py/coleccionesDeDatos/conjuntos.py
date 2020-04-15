# Conjuntos (Sets)
# Son colecciones desordenadas de elementos
# UNICOS.
# Lo cual sirve para eliminar elementos 
# duplicados o comprobar pertenencia de
# elementos a grupos

# sintaxis:
# nombre = set()   Usando la funcion
# tambien puede ser mediante:
# nombre = {datos}

# Cuando decimos que un conjunto es 
# desordenado nos referimos al hecho de
# que los datos dentro del conjunto se
# agregan sin un orden establecido

# Pertenencia a grupos
grupo = {'Brayan', 'Bryan', 'Eduardo', 'Quintero', 'Aaron'}
# Verificamos si existe en el conjunto:
print 'Juan' in grupo # Devolviendo True o False
print 'Juan' not in grupo # Negacion

# Propiedad de componerse de elementos UNICOS
# Podriamos eliminar facilmente los elementos
# repetidos en una lista al castearla a conjunto
# o set, lo cual eliminaria los repetidos, y 
# volviendola a castear como lista:
l = [1, 2, 3, 3, 4, 4, 4, 5, 6]
print 'Lista repetida:',l
l = list(set(l))
print 'Lista sin repetidos',l