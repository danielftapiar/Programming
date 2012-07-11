#! /usr/bin/env python

print 'Ingrese coordenadas del caballo.'
fila = int(raw_input('Fila: '))
columna = int(raw_input('Columna: '))

print
print 'El caballo puede saltar de', fila, columna, 'a:'

for i in range(-2, 3):
	x = fila + i
	for j in range(-2, 3):
		y = columna + j

		if 1<=x<=8 and 1<=y<=8 and abs(j) != abs(i) and i != 0 and j != 0:	
			print x, y