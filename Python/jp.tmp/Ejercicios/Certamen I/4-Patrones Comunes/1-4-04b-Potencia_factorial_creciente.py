#! /usr/bin/env python
#encoding: utf-8

n = int(raw_input('n: '))
m = int(raw_input('m: '))

pfc = 1

for i in range(m):
	pfc *= (n + i) # lo mismo que pfc = pfc * (n + i)

print 'Potencia Factorial Creciente:', pfc