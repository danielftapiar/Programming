 #!/usr/local/bin/python
 # coding: utf-8


a = int(raw_input("Cuantos Valores ingresara?: "))
lista = []
for x in xrange(1, a+1):
	valores=float(raw_input("Valor "+str(x)+": "))
	lista.append(valores)

maximo = lista[0]

for items in lista:
	if items > maximo:
		maximo = items
print maximo


minimo = lista[0]

for items in lista:
	if items < minimo:
		minimo = items
print minimo

rango = maximo-minimo
print "El rango es "+str(rango)
