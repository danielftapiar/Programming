#! /usr/bin/env python

def primo(numero):
	"""Retorna True si es numero es primo
		False si no lo es
	"""
	for i in range(2, numero, 1):
		if numero%i==0:
			return False
	if numero==1:
		return False
	return True
	
def quePrimo(numero):
	"""Retorna la posicion del numero primo
		ej: el numero primo 1 es el 2
		el numero primo 21 es el 73
	"""
	if primo(numero):
		count = 0
		while numero > 1:
			if primo(numero):
				count += 1
			numero -= 1
		return count
	else:
		return -1

def espejo(numero):
	"""Retorna el numero espejo"""
	new = 0
	while numero > 0:
		new = (new*10 + numero%10)
		numero /= 10
	return new
	
def palindromo(numero):
	"""Retorna True si el numero es palindromo
		retorna False si no lo es
	"""
	return espejo(numero)==numero

def dec2bin(decimal):
	"""Retorna el numero en binario"""
	i = 0
	binario = 0

	while decimal!=0:
		binario += decimal%2*(10)**i
		i+=1
		decimal/=2

	return binario

def multMembers(numero):
	"""Retorna la multiplicacion de los digitos
		del numero
	"""
	mult = 1
	while numero!=0:
		if numero%10 != 0:
			mult *= numero%10
		numero /= 10
	return mult

def sheldon(numero):
	a = espejo(quePrimo(numero)) == quePrimo(espejo(numero))
	b = quePrimo(numero) == multMembers(numero)
	c = palindromo(dec2bin(numero))
	
	return a and b and c


count = 0
i=8447
sheldons = [73]
while True:
	if sheldon(i):
		sheldons.append(i)
		count += 1
		print i
	i += 1
	print i, '-', sheldons

print sheldons
	