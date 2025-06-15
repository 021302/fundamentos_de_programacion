'''
Clase:        Clase 10
Tema:         Manejo de Matrices
Ejercicio:    10.3.2. Juego del entorno
Descripción:  Dada una matriz, hacer la suma de cuantos "1" hay alrededor de la celda, en todas las direcciones

Autor:        Emma Daniela Palacios Rodriguez
Fecha:        2025-06-14
Estado:       [ Terminado ]
'''


a = int(input())
b = int(input())

m = []
for i in range(a):
    linea = input()
    partes = linea.split(",")
    fila = []
    for p in partes:
        num = int(p)
        fila.append(num)
    m.append(fila)
#print (m)

res = []
for i in range(a):
    nueva = []
    for j in range(b):
        contador = 0
        for dx in [-1, 0, 1]:
            for dy in [-1, 0, 1]:
                if dx == 0 and dy == 0:
                    continue
                ni = i + dx
                nj = j + dy
                if ni >= 0 and ni < a and nj >= 0 and nj < b:
                    if m[ni][nj] == 1:
                        contador = contador + 1
        nueva.append(contador)
    res.append(nueva)
#print(resultado)


for fila in res:
    print(fila)