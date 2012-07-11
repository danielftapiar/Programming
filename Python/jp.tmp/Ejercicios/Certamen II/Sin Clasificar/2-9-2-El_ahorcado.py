#! /usr/bin/env python

partes = ['piedra derecha', 'pierna izquerda', 'brazo derecho', 'brazo izquerdo', 'tronco', 'cabeza']

def llenar(char, word, guess):
	new_guess = ''
	for i in	range(len(word)):
		if word[i] == char:
			new_guess += char
		else:
			new_guess += guess[i]
			
	return new_guess
			
def imprimir(palabra):
	print '"',
	for i in palabra:
		print i,
	print '"'

word = raw_input('Ingrese la palabra: ')
print 'Comienza el juego!'
guess = '_' * len(word)
pierde = -1

while True:
	char = raw_input('Ingrese letra: ')
	
	if char not in word:
		pierde += 1
		print 'Pierde "' + partes[pierde] + '"'
		
		if pierde == len(partes)-1:
			print '\nHas perdido el juego!'
			break
			
	guess = llenar(char, word, guess)
	imprimir(guess)
	
	if guess == word:
		print '\nHas ganado!'
		break
	
