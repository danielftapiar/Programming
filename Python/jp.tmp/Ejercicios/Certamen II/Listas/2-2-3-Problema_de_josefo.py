#! /usr/bin/env python

def sobreviviente(m, n):
	personas = range(1, m+1)
	i = 0
	
	while len(personas)>1:
		i = (i+n-1)%len(personas)
		del personas[i]
		
	print personas[0]
	
sobreviviente(12, 3)