#! /usr/bin/env python
#coding: utf-8

char = raw_input('Ingrese caracter: ')

char = char[0]

if 'z'>=char>='a':
	print 'Es letra minúscula'
elif 'Z'>=char>='A':
	print 'Es letra mayúscula'
elif '9'>=char>='0':
	print 'Es número'
else:
	print 'No es letra ni número'