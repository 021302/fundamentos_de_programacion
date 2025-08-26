'''
Clase:        Clase 10
Tema:         Manejo de Matrices
Ejercicio:    10.2.1. Diagonal principal y secundaria
Descripción:  Dada una matriz, crear dos listas, una con los elementos de la diagonal principal y la otra con los elementos de la diagonal secundaria.

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

def num(b):
    for i in range(len(b)):
        if len(b[i]) > i: 
            b[i] = b [i][i:] 
            #print(b[i][0]) 
        c.append(b[i][0])                 


nueva = [i[::-1] for i in b]
#print(nueva)

num(b)
num(nueva)


print(c[0:4])
print(c[4:8])