#! /usr/bin/env python
#coding: utf-8

n = long(raw_input('n: '))
i = long(1.0)
pi = long(0.0)

print 'Para n muy grandes, esto toma su tiempo...'
while i<n:
	pi += (-1)**(i+1)*(1.0/(2*i-1))
	i += 1
	
print "%.10f" % (4*pi)

# usamos long, por que sirve para trabajar con numeros muy grandes
