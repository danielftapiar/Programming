#! /usr/bin/env python
#encoding: utf-8

total = int(raw_input('Cantidad de palabras: '))

larga = float('-inf')
corta = float('inf')
for i in range(1,total+1):
	palabra = raw_input('Palabra'+str(i)+': ')
	if len(palabra)<corta:
		chica = palabra
		corta = len(palabra)
	elif len(palabra)>larga:
		grande = palabra
		larga = len(palabra)
	
print 'La palabra mas larga es', grande
print 'La palabra mas corta es', chica