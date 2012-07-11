#! /usr/bin/env python

p1 = raw_input('Palabra 1: ')
p2 = raw_input('Palabra 2: ')

l1 = len(p1)
l2 = len(p2)

if l1>l2:
	print 'La palabra', p1, 'tiene', l1-l2, 'letras mas que', p2
elif l1<l2:
	print 'La palabra', p2, 'tiene', l2-l1, 'letras mas que', p1
else:
	print 'las dos palabras tiene el mismo largo'