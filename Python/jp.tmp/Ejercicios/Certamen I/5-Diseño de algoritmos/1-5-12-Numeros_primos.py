#! /usr/bin/env python

def primo(numero):
	for i in range(2, numero, 1):
		if numero % i==0:
			return False
	if numero==1:
		return False
	return True
	
cuantos = int(raw_input('Cuantos primos: '))

i=1
while cuantos>0:
	if primo(i):
		print i
		cuantos -= 1
	i += 1