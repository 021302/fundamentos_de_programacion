'''
Clase:        Clase 10
Tema:         Manejo de Matrices
Ejercicio:    10.2.1. Diagonal principal y secundaria
Descripción:  Dada una matriz, comprobar si es simetrica con respecto a la diagonal principal

Autor:        Emma Daniela Palacios Rodriguez
Fecha:        2025-06-14
Estado:       [ Terminado ]
'''
a = int(input())

b = []

for i in range(a):
    t = input().split(' ')
    b.append(t)
#print(b)

c = []

for i in range(len(b)):
    d = (b[i][0]) #primer numero de cada fila
    c.append(d)
    #print(c)

#print (b[0])

f = []

for i in range(len(b)):
    e = (b[i][-1]) #ultimo numero de la fila
    f.append(e)
    #print(f)


if c == b[0] and f == b[-1]:
    print ("La matriz es simetrica")
else:
    print("La matriz no es simetrica")