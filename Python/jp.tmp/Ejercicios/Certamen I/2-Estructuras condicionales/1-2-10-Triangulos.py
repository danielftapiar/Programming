#! /usr/bin/env python
#coding: utf-8

a = float(raw_input('Ingrese a: '))
b = float(raw_input('Ingrese b: '))
c = float(raw_input('Ingrese c: '))

if a<b+c and b<c+a and c<b+a:
	if a==b==c:
		print 'El triángulo es equilátero.'		
	elif a!=b!=c:
		print 'El triángulo es escaleno.'
	else:
		print 'El triángulo es isoceles.'
else:
	print 'no es un triángulo válido.'
		
	