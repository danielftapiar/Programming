#! /usr/bin/env python
#coding: utf-8

distancia = float(raw_input("Ingrese Distancia: "))
angulo = float(raw_input("Ingrese Angulo: " ))

if ( (angulo> 0 and angulo < 90) or (angulo>90 and angulo < 135) or (angulo>180 and angulo<225) or (angulo>270 and angulo <315) ) and (distancia>20 and distancia<35):
	print "Area Verde"
elif (distancia>0 and distancia< 7):
	print "Pileta"
elif( ( angulo > 45 and angulo < 90) and (distancia> 7 and distancia < 47)):
	print "Publico"
else:
	print "Cemento"