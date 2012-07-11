#! /usr/bin/env python
#encoding: utf-8

puntos, k = 0, 0

for i in range(7):
	for j in range(i,7):
		puntos += i + j

print 'Puntos:', puntos