#! /usr/bin/env python
#coding: utf-8
def media_aritmetica(a):
	#return float(sum(a))/len(a) Forma facil...
	
	suma = 0.0
	for i in a:
		suma += i
		
	return suma/len(a)
	
def media_armonica(a):
	abajo = 0.0
	for i in a:
		abajo += 1.0/i
	
	return len(a)/abajo
	
def mediana(a):
	i = len(a)/2
	b = sorted(a)
	if len(b)%2 == 0:
		med = (b[i-1] + b[i] )/2
	else:
		med = b[i]
			
	return med

def modas(a):
	modas = []
	veces1=0
	for i in a:
		veces = 0
		for j in a:
			if i == j:
				veces += 1
			veces1 = max(veces1, veces)
			
	for i in a:
		veces2 = 0
		for j in a:
			if i == j:
				veces2 += 1
			if veces2 == veces1 and i not in modas:
				modas.append(i)
	return sorted(modas)

def main():
	cuantos = int(raw_input('Cuantos datos ingresar?: '))

	lista = []
	for i in range(cuantos):
		val = float(raw_input('valor'+str(i+1)+': '))
		lista.append(val)

	print 'Media Aritmetica:', media_aritmetica(lista)
	if 0 not in lista:
		print 'Media Armónica:', media_armonica(lista)
	print 'Mediana:', mediana(lista)
	print 'Modas: ', modas(lista)

if __name__ == '__main__':
	main()