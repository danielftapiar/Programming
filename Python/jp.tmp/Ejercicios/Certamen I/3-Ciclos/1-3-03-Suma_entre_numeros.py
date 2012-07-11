#! /usr/bin/env python
#coding: utf-8

num1 = int(raw_input('Ingrese un num: '))
num2 = int(raw_input('Ingrese un num: '))

sum = 0

for i in range(min(num1,num2)+1,max(num1,num2)):
	sum += i

print 'La suma es', sum