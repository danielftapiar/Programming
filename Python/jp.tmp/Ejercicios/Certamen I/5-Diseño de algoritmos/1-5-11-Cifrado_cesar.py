#!/usr/bin/env python

string = raw_input('Frase o numero: ')
key = int(raw_input('Llave: '))

chripted = ''
for i in string:
	if i in "abcdefghijklmnopqrstuvwxyz":
		chripted += chr((ord(i) - (97-key))%26 + 97)
	elif i in "ABCDEFGHIJKLMNOPQRSTUVWXYZ":
		chripted += chr((ord(i) - (65-key))%26 + 65)
	elif i in "0123456789":
		chripted += chr((ord(i) - (48-key))%10 + 48)
	else:
		chripted += i
		
print chripted