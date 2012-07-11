#!/usr/bin/env python

def hola(n):
	return 'hola' * n
	
def hola2(n):
	return 'aloh' * n
	
def chao(func, n):
	return func(n)


print chao(hola, 2)
print chao(hola2, 3)
