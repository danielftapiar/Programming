#! /usr/bin/env python
#encoding: utf-8

n = int(raw_input('n: '))
k = int(raw_input('k: '))


suma = 0.0
for i in range(k):
	#la combinatoria
	arriba = 1.0
	for j in range(i):
		arriba *= (k-j)

	abajo = 1.0
	for j in range(1, i + 1):
		abajo *= j
		
	combinatoria = arriba/abajo
	#fin combinatoria
	
	suma += (-1)**i * combinatoria *(k-i)**n
	
#factorial de k
factDeK = 1.0
for j in range(1,k+1):
	factDeK *= j
		
suma *= 1.0/factDeK

print suma


