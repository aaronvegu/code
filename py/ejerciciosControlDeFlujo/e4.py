n = int(input('Cuantos numeros desea introducir?\n'))
s = 0
for i in range(n):
    s += float(input('Numero: '))
print 'Se introdujeron ', n, ' numeros, que la suma total fue ', s, ' y la media aritmetica es ', s/n