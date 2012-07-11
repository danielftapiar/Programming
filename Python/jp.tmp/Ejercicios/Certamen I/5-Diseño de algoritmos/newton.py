#! /usr/bin/env python

x = float(raw_input('x: '))

estimacion = 1
promedio = 1

while abs(estimacion**2-x) > 1e-9:
	estimacion = x/promedio
	promedio = (estimacion + promedio)/2
	
print estimacion