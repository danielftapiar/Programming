#! /usr/bin/env python
#encoding: utf-8

puntaje = int(raw_input('Ingrese puntaje: '))

combinaciones = 0
for i in range(1,7):
	for j in range(1,7):
		if i+j==puntaje:
			combinaciones += 1

print 'Hay', combinaciones, 'combinacion(es) para obtener', puntaje

