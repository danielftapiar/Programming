#! /usr/bin/env python

for i in range(150, 411):
	num = i
	suma = 0
	while num!=0:
		suma += (num%10)**3
		num /= 10
	if suma == i:
		print i
	