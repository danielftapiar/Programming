#! /usr/bin/env python

from math import log, pi

tempOriginal = float(raw_input('Ingrese temperatura original del huevo: '))

# es mas facil guardar estos numeros en variables.
# Asi es mas legible el codigo
m = 47
c = 3.7
q = 1.038
k = 5.4e-3

# m**(2/3) daria 0, ya que 2/3 es una division
# de numeros enteros, es por eso que forzamos la operacion
# a float, haciendo uno de los numeros de tipo float
# 2.0/3

arriba = (m**(2.0/3) *c* q**(1.0/3))
abajo = (k * pi**2 * (4*pi/3)**(2.0/3))
logaritmo = log(0.76*(tempOriginal-100)/(70-100))

t = arriba/abajo * logaritmo

print t, 'segundos'