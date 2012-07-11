#! /usr/bin/env python

cuantos = int(raw_input('Cuantos numeros: '))


h = 0
for i in range(1, cuantos+1):
	n = int(raw_input('n'+str(i)+' = '))
	n = 1.0/n
	h += n

h = cuantos/h

print 'H =', h