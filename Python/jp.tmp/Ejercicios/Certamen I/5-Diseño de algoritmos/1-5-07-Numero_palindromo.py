#! /usr/bin/env python
#coding: utf-8

numero = int(raw_input('Ingrese un número: '))

revez = 0
original = numero #Guardamos el numero original para compararlo mas tarde

while numero != 0:
	revez = (revez*10 + numero % 10)
	# n % 10 devuelve el ultimo digito de n
	# asi 12345 % 10 = 5
	# tambien funciona con 100, 1000, etc
	# 12345 % 100 = 45
	
	numero /= 10

if original == revez:
	print original, 'Si es palindromo'
else:
	print original, 'No es palindromo'
