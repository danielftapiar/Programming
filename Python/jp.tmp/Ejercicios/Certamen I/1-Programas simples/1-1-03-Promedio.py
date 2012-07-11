#! /usr/bin/env python

n1 = int(raw_input('Primera Nota: '))
n2 = int(raw_input('Segunda Nota: '))
n3 = int(raw_input('Tercera Nota: '))
n4 = int(raw_input('Cuarta Nota: '))

promedio = (n1+n2+n3+n4)/4.0
# Recuerden que cualquier operacion, si uno de los
# numeros es de tipo float, el resultado es float
# Y si TODOS son int, el resultado es int.

print 'El promedio es', promedio

