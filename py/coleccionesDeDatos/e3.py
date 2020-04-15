from collections import deque
# Instrucciones: 
#   Durante la planificacion de un proyecto se han acordado una lista de tareas. 
#   Para cada una de estas tareas se ha asignado un orden de prioridad  
#   (cuanto menor es el numero de orden, mas prioridad).

#   Eres capaz de crear una estructura del tipo cola con todas las tareas ordenadas 
#   pero sin los numeros de orden?

tareas = [ 
    [6, 'Distribucion'],
    [2, 'Disenio'],
    [1, 'Concepcion'],
    [7, 'Mantenimiento'],
    [4, 'Produccion'],
    [3, 'Planificacion'],
    [5, 'Pruebas']
]

print("==Tareas desordenadas==")
for tarea in tareas:
    print(tarea[0], tarea[1])

tareas.sort() # Ordenamos la lista de tareas
colaTareas = deque([]) # Creamos una cola vacia

for tarea in tareas:    # Ingresamos las tareas ya ordenadas en la cola
    colaTareas.append(tarea[1])

print '==Pendientes (Por Prioridad)=='
for tarea in colaTareas:
    print tarea