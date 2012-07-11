#! /usr/bin/env python

rol = int(raw_input('Rol: '))

original = rol

suma = 0
n = 2
while rol != 0:
	if n > 7:
		n=2
	suma = suma + ( rol%10 )*n
	rol /= 10
	n += 1
	
suma = suma%11
suma = 11 - suma

if suma == 10:
	suma = 'k'
	
print str(original)+'-'+str(suma)