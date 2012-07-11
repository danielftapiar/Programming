#! /usr/bin/env python
#encoding: utf-8

n = int(raw_input('Ingrese n: '))
mayor = float('-inf')
for i in range(n):
	num = int(raw_input('Ingrese número: '))
	
	#mayor = max(mayor,num) # Esta es otra forma de hacerlo
	#en vez de el if num > mayor:...
	
	if num > mayor:
		mayor = num

print 'El mayor es', mayor