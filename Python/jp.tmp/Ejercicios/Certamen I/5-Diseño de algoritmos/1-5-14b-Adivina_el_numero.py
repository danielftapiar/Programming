#! /usr/bin/env python

intentos = 0
n = 50
respuesta = 'none'
superior = 101
inferior = 0

while respuesta != '=':
	intentos += 1
	
	print 'Intento '+str(intentos)+':', n
	respuesta = raw_input()

	if respuesta == '>':
		inferior = n
		n = (n + superior)/2
	elif respuesta == '<':
		superior = n
		n = (n + inferior)/2

print 'Adivine en', intentos, 'intentos B-)'

