'''
Clase:        Clase 2
Tema:         Fortalecimiento
Ejercicio:    Calculo de propina
Descripción:  Calcular propinas mediante operaciones basicas

Autor:        Emma Daniela Palacios Rodriguez
Fecha:        2025-05-22
Estado:       [ Terminado ]
'''

#Pedir al usuario el total de una cuenta y el porcentaje de propina. Calcular y mostrar el total a pagar.

cuenta = int(input("Cual es el total de la cuenta"))
propina = int(input("Ingrese el porcentaje de la propina"))

prop = (cuenta * propina) / 100

final = cuenta + prop

print (f"Total de la cuenta: ${cuenta}")
print (f"Propina: ${prop}")
print (f"Total de la cuenta con propina ({propina}%): ${final}")

