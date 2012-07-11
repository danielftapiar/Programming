#! /usr/bin/env python

n = int(raw_input('Factorial n: '))

factorial = 1.0
for i in range(1,n+1):
	factorial*=i

print 'n! =', factorial

# El factorial debe comenzar en 1.0 ya que es
# una multiplicacion, si fuese 0, estaria multiplicando
# siempore por 0.