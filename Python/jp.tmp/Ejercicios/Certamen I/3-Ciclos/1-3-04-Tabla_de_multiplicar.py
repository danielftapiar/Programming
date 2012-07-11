#! /usr/bin/env python
#coding: utf-8

for i in range(1,11):
	for j in range(1,11):
		print repr(i*j).rjust(3),
	print
	
# NOTA
# repr y rjust son metodos para alinear 
# texto. asi lo que esta dentro de repr()
# es alineado rjust (right justify) o ljust 
# (left justify) y el numero es cuantos espacios
# alinear, en este caso es tres, por que el mayor 
# digito en la tabla de multiplicar
# de 10x10 es 100, y tiene 3 digitos