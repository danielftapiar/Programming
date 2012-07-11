#! /usr/bin/env python
#coding: utf-8

def invertir_digitos(numero):
	revez = 0
	while numero != 0:
		revez = (revez*10 + numero % 10)
		numero /= 10
	return revez


numero = int(raw_input('Ingrese n: '))

if numero == invertir_digitos(numero):
	print 'Es Palíndromo'
else:
	print 'No es Palíndromo'
