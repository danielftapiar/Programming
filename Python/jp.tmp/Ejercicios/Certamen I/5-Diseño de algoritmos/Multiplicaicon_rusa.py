#! /usr/bin/env python

ador = int(raw_input('Ingrese multiplicador: '))
ando = int(raw_input('Ingrese multiplicando: '))

suma = 0
while ador>=1:
	if ador%2 != 0:
		suma += ando
	ador /= 2
	ando *= 2

print 'Resultado: ', suma