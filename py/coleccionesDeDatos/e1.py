# Instrucciones:
#   Realiza un programa que siga las siguientes instrucciones:

#   Crea un conjunto llamado usuarios con los usuarios Marta, David, Elvira, Juan y Marcos
#   Crea un conjunto llamado administradores con los administradores Juan y Marta.
#   Borra al administrador Juan del conjunto de administradores.
#   Anade a Marcos como un nuevo administrador, pero no lo borres del conjunto de usuarios.
#   Muestra todos los usuarios por pantalla de forma dinamica, ademas debes indicar cada usuario es administrador o no.

usuarios = {'Marta', 'David', 'Elvira', 'Juan', 'Marcos'}
administradores = {'Juan', 'Marta'}

administradores.discard('Juan')
administradores.add('Marcos')

for usuario in usuarios:
    if usuario in administradores:
        print usuario, 'es Administrador(a)'
    else:
        print usuario, 'no es Administrador(a)'