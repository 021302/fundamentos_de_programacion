'''
Clase:        Clase 5
Tema:         Bucles For y While
Ejercicio:    5.4.1. !Adivina el número!
Descripción:  Crear un programa que genere un numero random, y que el usuario tenga que adivianrlo. Por cada intento, el programa avisará si el número ingresado es mayor o menor al número secreto.

Autor:        Emma Daniela Palacios Rodriguez
Fecha:        2025-05-31
Estado:       [ Terminado ]
'''

import random #se importa para poder generar un número random sin necesidad de pedirlo al usuario

a = random.randint(1,100) #se establece que el número debe de estar dentro del rango de 1 a 100
print(a)

b = int(input("Ingresa un número entre 1 y 100"))
while b != a:
    if b > a:
        print("El número secreto es menor")
        b = int(input("Ingresa un número entre 1 y 100"))
    elif b < a: 
        print("El número secreto es mayor")
        b = int(input("Ingresa un número entre 1 y 100"))
if b == a:
    print(f"¡Felicidades! Has acertado el número correcto: {b}")