#! /usr/bin/env python
#coding: utf-8

monto = float(raw_input('Monto: '))
t = int(raw_input('Años: '))
interes = float(raw_input('Tasa de interés: '))

for i in range(1,t+1):
	monto *= (1 + interes)
	print i, monto

