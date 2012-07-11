#! /usr/bin/env python
#coding: utf-8

num = int(raw_input('Ingrese número: '))

for i in range(1,num+1):
	if num % i == 0:
		print i,