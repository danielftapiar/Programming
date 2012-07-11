#! /usr/bin/env python
#coding: utf-8

num = int(raw_input('n: '))

print num,

while num > 1:
	if num%2 == 0:
		num = num/2
	else:
		num = num*3+1
	print num,