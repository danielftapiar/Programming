#! /usr/bin/env python

def son_anagramas(str1, str2):	
	return bool(set(str1) == set(str2))

def panvocalica(str1):
	pan = 0
	for i in set(str1):
		if i in 'aeiouAEIOU':
			pan += 1
			
	if pan == 5:
		return True
	return False

def cuenta_pv(frase):
	words = frase.split(' ')
	cuantas = 0
	for palabra in words:
		if panvocalica(palabra):
			cuantas += 1
	return cuantas
	
if __name__ == '__main__':
	print son_anagramas('torpes', 'postre')
	print son_anagramas('hola', 'pescado')

	print panvocalica('aeiou')

	print cuenta_pv('el abuelito mordisquea el aceituno con contundencia')