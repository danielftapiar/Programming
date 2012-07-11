#! /usr/bin/env python

from random import randrange

n = randrange(100+1) # +1 incluye el 100, desde el 0

intentos = 0
sera = -1

print 'Adivine el numero.'

while sera != n:
	intentos += 1
	sera = int(raw_input('Intento '+str(intentos)+': '))
	
	if sera < n:
		print 'Es mayor que', sera
	if sera > n:
		print 'Es menor que', sera
	

print 'Correcto. Adivinaste en', intentos, 'intentos.'