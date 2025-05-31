'''
Clase:        Clase 5
Tema:         Bucles For y While
Ejercicio:    5.4.2. Sumador de valores posicionales
Descripción:  Crear un programa que dsume todos los digitos de un numero ingresado, repetidamente, hasta llegar a un solo dígito.

Autor:        Emma Daniela Palacios Rodriguez
Fecha:        2025-05-31
Estado:       [ Terminado ]
'''

a = list(map(int,input("Ingrese un numero")))
#print(a)

l = []

while a != []: #mientras la lista no este vacia:
    b = 0       #se estabece 0 como el inicio
    for i in a: #recorre todos los valores dentro de la lista
        b += i  #se van sumando los digitos
    l.append(b) #se agregan a una nueva lista
    print(b)    #se imprimen todas las sumas que se han hecho
 
    if b < 10 : #si la lista tiene solo un caracter:
        break   #se rompe el bucle

    a = list(map(int, str(b))) #se devuelve la variable a, con los nuevos digitos

print(f"El resultado final es: {b}") #se imprime el resultado final 