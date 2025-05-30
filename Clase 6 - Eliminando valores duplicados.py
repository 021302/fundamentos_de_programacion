'''
Clase:        Clase 6
Tema:         Listas
Ejercicio:    Eliminar numeros repetidos
Descripción:  Crear un programa que detecte numeros repetidos y que imprima solo el primero de cada uno de estos numeros

Autor:        Emma Daniela Palacios Rodriguez
Fecha:        2025-05-30
Estado:       [ Terminado ]
'''

a = input("Ingrese los numeros")
b = a.split(" ")
a =[]
for i in b:
  if (i not in a):
    a.append(i)

b = " ".join(map(str,a)) #se usa esto para convertirlo a un string, aplica toda la funcion a todos los valores
print(b)
