#!/usr/bin/env python


from math import pi, sin, cos

def factorial_r(n):
	fact = long(1.0)
	for i in range(1,n+1):
		fact *= i
	return 1/fact

def signo(n):
	return (-1.0)**n
	
def seno_aprox(x, m):
	sin = long(0.0)
	
	for i in range(1,m+1):
		sin += x**(2*i-1)*signo(i+1)*factorial_r(i)
	return sin
	
def coseno_aprox(x, m):
	sin =long(0.0)

	for i in range(0,m+1):
		sin += x**(2*i)*signo(i)*factorial_r(i)
	return sin

def error(f_exacta, f_aprox, m, x):
	return abs(f_exacta(x) - f_aprox(x, m))
	
	
print error(sin, seno_aprox, 20, 2)
