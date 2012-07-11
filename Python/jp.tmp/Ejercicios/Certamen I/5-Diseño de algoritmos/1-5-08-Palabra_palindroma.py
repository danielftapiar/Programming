#! /usr/bin/env python

palabra = raw_input('Ingrese palabra: ')

# Esta primera parte remueve los espacios de la frase
# Palabra2 es la frase sin espacios
l = len(palabra) - 1
palabra2 = ''
for i in range(l, -1, -1):
	if palabra[i] == ' ': 
		continue
	palabra2 += palabra[i]
	
# Esta da vuelta la frase
l = len(palabra2) - 1
palindroma = ''

for i in range(l, -1, -1):
	palindroma += palabra2[i]

if palabra2 == palindroma:
	print 'es palindromo'
else:
	print 'no es palindromo'