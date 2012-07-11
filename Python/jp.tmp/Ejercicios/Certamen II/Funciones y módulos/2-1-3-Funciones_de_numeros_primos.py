#!/usr/bin/env python

def es_divisible(n, d):
	return bool(n % d == 0)
	
def es_primo(n):
	i = 2
	if n<=1:
		return False
	while i<n:
		if es_divisible(n, i):
			return False
		i += 1
	return True

def i_esimo_primo(n):
	k = 0
	i = 1
	while k<n:
		i += 1
		if es_primo(i):
			k += 1
		
	return i
	
def primeros_primos(m):
	i = 1
	primos = []
	while i<=m:
		primos.append(i_esimo_primo(i))
		i += 1
	return primos

def primos_hasta(m):
	i = 1
	primos = []
	while i_esimo_primo(i)<=m:
		primos.append(i_esimo_primo(i))
		i += 1
	return primos
	
if __name__ == '__main__':
	print primeros_primos(20)