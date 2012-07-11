#! /usr/bin/env python
#coding: utf-8

e = 0.0
n = 2
a = 0.9
b = 1

while b-a >= 1e-4:
	b = a
	
	#Calculamos el factorial
	factorial = 1  #iniciado en 1, ya que es una multiplicacion
	for i in range(1,n+1):
		factorial = factorial * i
	#ahora usamos el resultado de el factorial:
	a = 1.0/factorial
	e = e + a
	n = n + 1
	
print e+2

