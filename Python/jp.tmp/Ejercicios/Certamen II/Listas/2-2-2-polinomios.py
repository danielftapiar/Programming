#! /usr/bin/env python

def grado(p):
	return len(p)-1

def evaluar(p, x):
	resultado = 0
	for i in range(len(p)):
		resultado += p[i] * x**i
	return resultado

def derivar_polinomio(p):
	resultado = []

	for i in range(2,len(p)+1):
		resultado.append(grado(p[:i])*p[i-1])
	
	return resultado

def sumar_polinomios(p1, p2):
	resultado = []
	for i in range(min(len(p1), len(p2))):
		resultado.append(p1[i] + p2[i])
		
	if len(p1)>len(p2):
		x = len(p1)-len(p2)
		resultado += p1[x:]
	elif len(p1)<len(p2):
		x = len(p2)-len(p1)
		resultado += p2[x:]
		
	return resultado

	
p = [1, 2, 1]
q = [4, -17]
r = [-1, 0, 0, -5, 0, 3]

print derivar_polinomio(r)

