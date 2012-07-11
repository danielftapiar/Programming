#! /usr/bin/env python

num = []

for i in range(0, 4):
	num.append(int(raw_input('Ingrese un numero: ')))

#Bubble Sort
for i in range(0, 4):
	for j in range(0, 3-i):
		if(num[j]>num[j+1]):
			tmp = num[j+1]
			num[j+1] = num[j]
			num[j] = tmp

print num