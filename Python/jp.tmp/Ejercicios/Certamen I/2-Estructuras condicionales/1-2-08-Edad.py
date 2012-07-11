#! /usr/bin/env python
#coding: utf-8
from time import localtime

t = localtime()

print 'Ingrese su fecha de nacimiento.'
dia = int(raw_input('Dia: '))
mes = int(raw_input('Mes: '))
anno = int(raw_input('Año: '))

years = t.tm_year - anno

if t.tm_mon<mes: #Si el mes en el que estamos, es menor que en el que nacio
	print t.tm_year - anno - 1
elif t.tm_mon>=mes and t.tm_mday>dia: #si el mes en el que estamos es mayor
	print t.tm_year - anno - 1        #o igual al que nacio, y el dia en que nacio
else:								  #es menor que el dia en el que estamos
	print t.tm_year - anno