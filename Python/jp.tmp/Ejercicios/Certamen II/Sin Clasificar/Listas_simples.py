#!/usr/bin/env python
#coding: utf-8

lista = []

print 'Ingrese números:'

for i in range(10):
	lista.append(int(raw_input()))
	
print 'Promedio:', float(sum(lista))/len(lista)
print 'Mayor:', max(lista), 'en posicion', lista.index(max(lista))
print 'Menor:', min(lista), 'en posicion', lista.index(min(lista))

count = 0
for i in lista:
	if i>sum(lista)/len(lista):
		count += 1
print 'Sobre promedio:', count
count = 0
for i in lista:
	if i<sum(lista)/len(lista):
		count += 1
print 'Bajo promedio:', count

for i in sorted(lista):
	print i,