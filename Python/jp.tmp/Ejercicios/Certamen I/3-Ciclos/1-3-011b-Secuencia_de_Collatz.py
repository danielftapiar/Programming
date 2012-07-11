#! /usr/bin/env python
#coding: utf-8

num = int(raw_input('n: '))

for i in range(1,num+1):
	tmp = i
	print i, '*',
	while tmp>1:
		print '*',
		if tmp%2==0:
			tmp = tmp/2
		else:
			tmp = tmp*3+1
	print