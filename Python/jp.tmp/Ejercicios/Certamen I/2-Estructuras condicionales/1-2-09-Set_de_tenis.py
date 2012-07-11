#! /usr/bin/env python
#coding: utf-8


a = int(raw_input('Juegos ganados por A: '))
b = int(raw_input('Juegos ganados por B: '))

if a-b>=2 and (a==6 or a==7>b>=5):
	print 'Gano A'
elif b-a>=2 and (b==6 or b==7>a>=5):
	print 'Gano B'
elif a==b==5 or a==b==6:
	print 'Aun no temrina'
elif a<=5 and b<=5:
	print 'aun no termina'
elif a==6 and b==7:
	print 'Gano B'
elif a==7 and b==6:
	print 'Gano A'
elif a==6 and b==5:
	print 'Aun no termina'
elif b==6 and a==5:
	print 'Aun no termina'
else:
	print 'Inválido'	
