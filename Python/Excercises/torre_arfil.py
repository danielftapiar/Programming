 #!/usr/local/bin/python
 # coding: utf-8


torre_fila = int(raw_input ("fila torre: "))
torre_columna = int(raw_input ("columna torre: "))
arfil_fila = int(raw_input ("fila arfil: "))
arfil_columna = int(raw_input ("columna arfil: "))

if int(torre_columna) > 1000 or int(torre_fila) > 1000 or int(arfil_columna) >1000 or int(arfil_fila) > 1000 :
	print "valores exeden el tablero 1"
elif int(torre_columna) < 0 or int(torre_fila) < 0 or int(arfil_columna) < 0 or int(arfil_fila) < 0:
	print "valores exeden el tablero 2"
else:
	if torre_columna == arfil_columna:
		print "Torre caputa Arfil"

	if torre_fila == arfil_fila:
		print "Torre caputa Arfil"

	if int(arfil_fila) - int(arfil_columna) == int(torre_fila) - int(torre_columna):
		print "Arfil captura Torre"

count = 1

for x in range(int(arfil_fila) ):
	if arfil_fila-count == torre_fila and arfil_columna+count == torre_columna:
		print "Arfil Captura Torre"
	count = count + 1

count = 1

for x in range(int(arfil_columna) ):
	if arfil_fila+count == torre_fila and arfil_columna-count == torre_columna:
		print "Arfil Caputra Torre"
	count = count + 1
