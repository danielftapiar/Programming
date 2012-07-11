#! /usr/bin/env python

mensaje = raw_input('Mensaje: ')

precio = 0

for i in mensaje:
	if 'z'>=i>='a' or 'Z'>= i >='A':
		precio += 10
	elif '9'>= i >='0':
		precio += 20
	elif i == ' ':
		continue
	else:
		precio += 30
	
print 'Su mensaje cuesta $' + str(precio)