#!/usr/bin/env python
#coding: utf-8

def es_escala(mano):
	if len(mano)<4:
		return False
	verdad = 0
	a, b, c, d, e = mano
	z = [a[0], b[0], c[0], d[0], e[0]]
	z = sorted(z)
	for i in range(4):
		if z[i]==z[i+1]+1:
			verdad += 1
	print verdad
	if a[1] == b[1] == c[1] == d[1] == e[1]:
		return True
	return False
	
mano = {(1, 'T'), (2, 'C'), (5, 'P'), (3, 'C'), (4, 'T')}
print es_escala(mano)