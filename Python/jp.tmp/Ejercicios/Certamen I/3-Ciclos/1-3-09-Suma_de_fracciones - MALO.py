#! /usr/bin/env python
#coding: utf-8

frac = 2
i = 1
suma = 0.0

print 'Potencia\tFraccion\t\tSuma'

while frac > 1e-6:
	frac = 1.0/2**i
	suma = suma + frac
	
	print i,'\t\t', round(frac,4), '\t\t\t', suma
	i = i+1