#! /usr/bin/env python

c1 = int(raw_input('Ingrese nota certamen 1: '))
c2 = int(raw_input('Ingrese nota certamen 2: '))
nl =  int(raw_input('Ingrese nota laboratorio: '))

# Es un simple despeje matemático
necesitas = ((60 - nl*0.3) * 3/0.7) - c1 - c2

necesitas = int(necesitas)

print 'Necesitas nota', necesitas, 'en el certamen 3'