#!/usr/bin/env python

# Porfavor, si van a ejecutar estos ejemplos,
# cambien el nombre de funciones de numeros primos
# a este:
from Funciones_de_numeros_primos import *

n = int(raw_input('Cuantos primos de Mersenne: '))
i = 1
k = 0
while k<n:
	if es_primo(2**i-1):
		print 2**i - 1
		k += 1
	i += 1