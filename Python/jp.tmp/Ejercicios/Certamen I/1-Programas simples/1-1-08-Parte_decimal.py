#! /usr/bin/env python

# Leemos un numero real
numero = float(raw_input('Ingrese un numero: '))

parteEntera = int(numero)
# Sacamos la parte entera, transformando el numero
# a entero, haciendo un cast:
# entero = int(numero)

decimal = abs(numero - parteEntera)
# Luego la parte decimal es el valor
# absoluto de la diferencia de el numero
# original sin su parte entera

print decimal