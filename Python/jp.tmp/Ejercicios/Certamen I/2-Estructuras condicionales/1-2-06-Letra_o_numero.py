#! /usr/bin/env python
#coding: utf-8
caracter = raw_input('Ingrese caracter: ')

if caracter.isupper(): #<---- si caracter es mayuscula (Is Upper)
	print 'Es letra mayúscula'
elif caracter.islower(): #<---- si caracter es minuscula (Is Lower)
	print 'Es letra minúscula'
elif caracter.isdigit(): #<---- si caracter es digito (Is Digit)
	print 'Es número'
else:
	print 'No es letra ni número'