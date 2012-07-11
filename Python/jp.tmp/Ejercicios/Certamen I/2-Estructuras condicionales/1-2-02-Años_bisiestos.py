#! /usr/bin/env python
#encoding: utf-8

year = int(raw_input('Ingrese un año: '))

if (year%4==0 and year%100!=0) or year%400==0:
	print year, 'es bisiesto'
else:
	print year, 'no es bisiesto'