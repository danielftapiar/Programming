#! /usr/bin/env python

puntosA = 0
puntosB = 0

while True:
	a = raw_input('A: ')
	b = raw_input('B: ')
	
	if a == 'papel' and b == 'tijera':
		puntosA += 1
	elif a == 'papel' and b == 'piedra':
		puntosB += 1
	elif a == 'piedra' and b == 'tijera':
		puntosA += 1
	elif a == 'piedra' and b == 'papel':
		puntosB += 1
	elif a == 'tijera' and b == 'piedra':
		puntosB += 1
	elif a == 'tijera' and b == 'papel':
		puntosA += 1
	
	if puntosA == 3:
		ganador = 'A'
		break
	elif puntosB == 3:
		ganador = 'B'
		break
	
	print puntosA, '-', puntosB
	print

print
print ganador, 'es el ganador'
