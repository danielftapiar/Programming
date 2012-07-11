#! /usr/bin/env python
#encoding: utf-8

print 'Ingrese varios valores, temrine con cero:'

positivos, negativos = 0, 0
while True:
	num = int(raw_input())
	if num>0:
		positivos+=1
	elif num<0:
		negativos+=1
	else:
		break

print 'Positivos: ' + '*' * positivos
print 'Negativos: ' + '*' * negativos

