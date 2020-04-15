lista_1 = ["h",'o','l','a',' ', 'm','u','n','d','o']
lista_2 = ["h",'o','l','a',' ', 'l','u','n','a']

lista_3 = []

for l in lista_1:
    if l in lista_2 and l not in lista_3:
        lista_3.append(l)

print lista_3