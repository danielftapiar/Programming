#! /usr/bin/env python
#encoding: utf-8

n = int(raw_input('Ingrese n: '))

s1 = 0
s2 = n*(n+1)/2

for i in range(1,n+1):
	s1 = s1 + i

print 'S1:', s1
print 'S2:', s2

if s1==s2:
	print 'Son iguales'
else:
	print 'son distintos'