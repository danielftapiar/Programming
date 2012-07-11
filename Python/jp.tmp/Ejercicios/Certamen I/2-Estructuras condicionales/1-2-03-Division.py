#! /usr/bin/env python
#encoding: utf-8

dividendo = int(raw_input('Dividendo: '))
divisor= int(raw_input('Divisor: '))

if dividendo%divisor == 0:
	print 'La división es exacta'
else:
	print 'la división no es exacta'
	
#print ''  <-- Linea nueva, igual que '\n'
print '\nCociente:', dividendo/divisor
print 'Resto: ', dividendo%divisor
