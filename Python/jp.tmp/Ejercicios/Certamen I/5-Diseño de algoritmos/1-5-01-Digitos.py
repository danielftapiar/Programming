#! /usr/bin/env python

num = int(raw_input('Ingrese numero: '))
original = num
digitos = 0
while True:
	num /= 10
	digitos +=1
	if num == 0:
		break

if digitos>1:
	print original, 'tiene', digitos, 'digitos'
else:
	print original, 'tiene', digitos, 'digito'