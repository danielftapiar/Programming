#! /usr/bin/env python
#coding: utf-8
a = float(raw_input('Ingrese a: '))
b = float(raw_input('Ingrese b: '))

if a == b == 0:
	print 'No hay solución única.'
elif a == 0 != b:
	print 'Sin solución'
else:
	print 'Solución única:', -b/a