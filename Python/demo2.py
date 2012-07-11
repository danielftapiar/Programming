
archivo = open("archivo3.txt", 'r')
buscar_palabra = 'avion'
for linea in archivo:
	a = linea.strip().split(':')
	b = a[0].split(" ")

	for word in b:
		if buscar_palabra==word:
			print "la palabra es:",word,b[1],"significado:",a[1]

archivo2= open('archivo2.txt','v')

for linea2 in archivo2:
	a = linea2.strip().split(' ', 2)
	print a
archivo.close()
