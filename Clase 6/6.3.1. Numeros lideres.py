a = list(map(int, input("Ingrese una serie de numeros: ").split(" ")))

c = []  #lista vacia donde se iran agragando los numeros lideres

while len(a) > 1: #mientras la longitud de la lista sea mayor a 1, es decir, que no está vacia.
    d = a[0] #posicion 1
    b = int(a[1]) #posicion dos
    if d >  b: #si el primer numero es mayor que el segundo
        c.append(d) #agregarlo a la lista
    a = a[1:] #se le quita el primer numero a la lista y se regresa
e = " ".join(map(str, c)) #se convierten los numeros de lista a un string
print (e) #se imprime el resultado

#a = (int(a.split(" ")))

