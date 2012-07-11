#!/usr/bin/env python

def largo_listas(a, b):
	if len(a)>len(b):
		print 'La lista mas larga', a, 'por', len(a)-len(b), 'elementos.'
	elif len(b)>len(a):
		print 'La lista mas larga', b, 'por', len(b)-len(a), 'elementos.'
	else:
		print 'Listas iguales'
	
a = []
b = []
largo_listas(a, b)