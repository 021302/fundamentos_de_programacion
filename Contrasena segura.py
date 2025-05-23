#Solicitar cadena de texto, y dependiendo de las especificaciones (debe de contener minimo 8 caracteres, una mayuscula y un numero), determinar si es segura o no
contra = input("Ingrese su contrasena")

may = False
num = False

for i in contra:
    if i.isupper():
        may = True
    if i.isdigit():
        num1 = True

if may == True and num1 == True and len(contra)>= 8:
    print("Su contrasena es segura")
else:
    print("Su contrasena no es segura")