#! /usr/bin/env python
#coding: utf-8

def promedio(l):
	# return sum(l)/len(l) <---Forma floja...
	
	#forma dos:
	suma = 0
	for i in l:
		suma += i
	return suma/len(l)

def cuadrados(l):
	for i in range(len(l)):
		l[i] = l[i]**2
	return l

def mas_largo(palabras):
	longest = ''
	for word in palabras:
		if len(word)>len(longest):
			longest = word
	return longest

if __name__ == '__main__':
	print promedio([7.0, 3.1, 1.7])
	print cuadrados([1, 2, 3, 4, 5])
	print cuadrados([3.4, 1.2])
	print mas_largo(['raton', 'hipopotamo', 'buey', 'jirafa'])