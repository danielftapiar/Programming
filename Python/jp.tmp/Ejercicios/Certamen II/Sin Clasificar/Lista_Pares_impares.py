#! /usr/bin/env python
#coding: utf-8
 
from random import randrange

lista = []
for i in range(20):
	lista.append(randrange(-100,101))

print 'Lista original:'
print lista
for i in range(0, len(lista), 2):
	for j in range(0, len(lista), 2):
		# Ordenar pares
		if lista[i]<lista[j]:
			tmp = lista[i]
			lista[i] = lista[j]
			lista[j] = tmp

		#ordenar impares
		if lista[i+1]>lista[j+1]:
			tmp = lista[i+1]
			lista[i+1] = lista[j+1]
			lista[j+1] = tmp
print 'Lista ordenada:'
print lista