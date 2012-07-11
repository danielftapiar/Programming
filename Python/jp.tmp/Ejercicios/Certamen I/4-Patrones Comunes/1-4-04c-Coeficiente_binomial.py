#! /usr/bin/env python
#encoding: utf-8

n = int(raw_input('n: '))
k = int(raw_input('k: '))

arriba = 1
for i in range(k):
	arriba *= (n-i)

abajo = 1
for i in range(1,k+1):
	abajo *= i

print 'Coeficiente Binomial: ', arriba/abajo
