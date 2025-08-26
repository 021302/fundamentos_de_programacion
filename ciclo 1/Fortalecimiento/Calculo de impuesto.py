#Calcular el impuesto que debe pagar un usuario por el consumo de energia.

u = int(input("Ingrese las unidades que ha consumido"))

if u >= 0 and  u <= 100:
    print("Sin impuestos")

elif u >= 101 and u <= 200:
    imp = u * 0.5
    tot = u + imp
    print(f"Su impuesto es de: ${tot}")

elif u >= 201:
    imp = u * 0.7
    tot = u + imp
    print(f"Su impuesto es de: ${tot}")

else:
    print("Valores invalidos")
