#! /usr/bin/env python
#coding: utf-8

tramo = 1
total = 0
while tramo!=0:
	tramo = int(raw_input('Duración tramo: '))
	total += tramo

print 'Tiempo total de viaje: ', str(total/60)+':'+str(total%60).zfill(2), 'horas'

# cuando digo
# total += tramo
# es exactamente lo mismo que escribir
# total = total + tramo
# esto sirve para todas las operaciones matematicas
# /=, *=... etc

# .zfill(n) es un metodo que rellena de ceros un numero
# que en teoria podria ser de 1 o 2 cifras.
# asi si los minutos son 8, imprime 08.
# con .zfill(10) y los minutos 20, quedaria:
# 0000000020
