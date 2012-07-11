 #!/usr/local/bin/python
 # coding: utf-8


a = int(raw_input("Ingrese Año: "))

if a % 400 == 0:
	print "El Año es Bisiesto"
elif a % 4 == 0:
	print "El Año es Bisiesto"
else:
	print "El Año no es Bisiesto"

