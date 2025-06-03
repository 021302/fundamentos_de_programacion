'''
Clase:        Clase 7
Tema:         Numpy
Ejercicio:    Guia de trabajo
Descripción:  Resolucion de todos los pasos y preguntas de la guia de trabajo

Autor:        Emma Daniela Palacios Rodriguez
Fecha:        2025-06-03
Estado:       [ Terminado ]
'''

import numpy as np

#//////////////////1.4. Creacion de matrices en NumPy
#Crear matriz de una lista:
my_list = [1, 2, 3, 4, 5]
arr = np.array(my_list)
print (arr)

#Crear matriz de ceros
zeros = np.zeros(5)
print(zeros)

#Crear matriz de unos
ones = np.ones(5)
print(ones)

#/////////////////1.5. Operaciones con matrices
#Suma
arr1 = np.array([1, 2, 3])
arr2 = np.array([4, 5, 6])
resultado = arr1 + arr2

#Multiplicacion
resultado = arr1 * arr2

#/////////////////1.6. Broadcasting
#Bradcasting con un escalar:
arr = np.array([1, 2, 3])
result = arr + 5

#Difusion de matrices unidimensionales y bidimensionales
arr1 = np.array([1, 2, 3])
arr2 = np.array([[10], [20], [30]])
result = arr1 + arr2
#Esto fue lo que copie de la parte 1.


#//////////////2. Caso de estudio: Consumo energetico
consumo = np.array([
    [12.5, 13.2, 11.9, 14.0, 13.5, 15.0, 14.3],
    [10.1, 10.5, 10.0, 11.2, 11.5, 12.0, 11.8],
    [14.0, 14.2, 13.9, 15.5, 15.1, 16.0, 15.8],
    [9.0, 9.2, 8.9, 9.5, 9.8, 10.0, 9.7],
    [16.2, 16.5, 16.0, 17.1, 17.4, 18.0, 17.8],
    [11.0, 11.3, 11.1, 12.0, 12.4, 12.8, 12.5],
    [13.5, 13.8, 13.2, 14.1, 14.6, 15.0, 14.9],
    [10.8, 11.0, 10.6, 11.5, 11.8, 12.2, 12.0],
    [15.1, 15.5, 15.0, 16.0, 16.4, 17.0, 16.7],
    [8.5, 8.7, 8.4, 9.0, 9.2, 9.5, 9.3],
])

#Exploracion inicial de los datos:
print("Dimensiones:", consumo.ndim) #dimensiones de la matriz
print("Forma:", consumo.shape) #numero de filas y columnas
print("Tipos de datos:", consumo.dtype) #tipo de dato
print("Consumo primer hogar:", consumo[0]) 
print("Consumo el miercoles (dia 3)", consumo [:, 2]) #todos los datos de la columna 2

#///////////// 3. Introduccion al Analisis Estadistico
#------Calculo de promeido y sumas:
#Promedio de consumo por hogar
promedio_por_hogar = np.mean(consumo, axis=1)

#Promedio de consumo diario de todos los hogares
promedio_por_dia = np.mean(consumo, axis=0)

#Suma total de consumo en la semana de los 10 hogares
total_consumo = np.sum(consumo)

print(promedio_por_hogar)
print(promedio_por_dia)
print(total_consumo)

#------Minimos, maximos y desviacion:
#Maximo por hogar
maximos = np.max(consumo, axis=1)

#Minimo por dia
minimos = np.min(consumo, axis=0)

#Desviacion estandar global
desviacion = np.std(consumo)

print(maximos)
print(minimos)
print(desviacion)

#------Comparacion de hogares
#Suma por hogar (semana)
consumo_total_hogar = np.sum(consumo, axis=1)

#Indice del hogar con mayor consumo
hogar_mayor_consumo = np.argmax(consumo_total_hogar)

#Indice del hogar con mejor consumo
hogar_mas_eficiente = np.argmin(consumo_total_hogar)

print(consumo_total_hogar)
print(hogar_mayor_consumo)
print(hogar_mas_eficiente)

#//////////////// 4. Transformaciones y filtros
#-------Filtrando hogares de alto consumo
#Suma por hogar (semana)
consumo_total_hogar = np.sum(consumo, axis=1)
print(f"Consumo total de cada hogar durante la semana: {consumo_total_hogar}")

#Compara cada hogar con un valor mayor a 100
altos = consumo_total_hogar > 100
#Filtrando hogares que cumplen con la condicion
consumo_mayor_100 = np.where(altos)[0]

print(f"Ids de hogares con consumo mayor a 100: {consumo_mayor_100}")

#-------Normalizacion de datos
#Aplicando normalizacion MinMax al conjunto de datos
consumo_normalizado = (consumo - consumo.min()) / (consumo.max() - consumo.min())

print(consumo_normalizado)

#////////////////////////////////////////////
#///////////////////////////////////////////
#//////////     5. Cuestionario de trabajo
#1. Cual es el consumo del hogar 5 el viernes (dia 5)?
con_5 = consumo[4,4]
print("Consumo del hogar 5 el dia viernes: ", con_5)

#2. Usando indexacion, muestra el consumo de los ultimos 3 hogares el domingo.
con_dom = consumo[7:, 6]
print("Consumo de los ultimos 3 hogares el domingo: ", con_dom)

#3. Calcula el promedio de ocnsumo los fines de semana (sabado y domingo, columnas 5 y 6)
fin = consumo [:, [5, 6]]

prom = np.mean(fin)
print("Promedio de consumo en fines de semana: ", prom)

#4. Que dia de la semana tiene la mayor desviacion estandar entre hogares? Explica
des = np.std(consumo, axis=0)
mayor = np.argmax(des)

print("Desviacion estandar por dia:", des)
print("El dia con mayor desviacion estandar es es el dia", mayor,)

#   Explicación:
#   Que exista una desviación estándar más alta, implica una mayor variabilidad entre los hogarres
#   El consumo entre los hogares fue muy diferente ese día

#5. Indentifica los 3 hogares con menor consumo total durante la semana. Muestra los índices y los valores.
contot = np.sum(consumo, axis=1)
men_ind = np.argsort(contot)[:3]
men_val = contot[men_ind]

print("Indices de los 3 hogares con menor consumo: ", men_ind)
print("Valores de consumo de esos hogares: ", men_val)

#6. Si el hogar 3 aumenta su consumo en un 10% cada dia, cual seria su nuevo consumo total semanal?
nuevo = consumo[2] * 1.10
total3 = np.sum(nuevo)

print("Nuevo consumo diario del hogar 3, 10%: ", nuevo)
print("Nuevo consumo total del  hogar 3: ", total3)

#
# appdata\local\programs\python\python39\lib\site-packages
#