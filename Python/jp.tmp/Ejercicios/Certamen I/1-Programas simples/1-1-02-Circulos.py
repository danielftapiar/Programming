#! /usr/bin/env python
#encoding: utf-8

from math import pi  #Usamos pi mas exacto...

radio = float(raw_input('Ingrese el radio: '))
# El radio es un float... Luego con el radio podemos obtener el area y el 
# perímetro
perimetro = 2 * pi * radio
area = pi * (radio**2)

print 'Perímetro: %.1f' % (perimetro)
print 'Área: %.1f' % (area)
# Para definir el numero de decimales es necesario
# usar print de esta forma, %.1f donde el .1 define el numero
# de decimales a mostrar truncando el resultado.
# podriamos escribir todo en una linea asi:

#print 'Perímetro: %.1f \nÁrea: %.1f' % (perimetro, area)

# el primer %.1f es el valor de la primera variable en parentesis
# y asi sucesivamente.

 