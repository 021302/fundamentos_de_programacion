#Dados tres enteros a, b y k, imprimir el resultado de a/b con k decimales exactos

#a = int(input("Ingrese un numero"))
#b = int(input("Ingrese otro numero"))
#c = int(input("Ingrese un tercer numero"))

a = input("Ingrese una cadena que contenga los dos numeros que desea dividir, y la cantidad de decimales que desea mostrar (separados por espacios)").split(" ")

div = round(int(a[0])/int(a[1]), int(a[2]))
print (div)
