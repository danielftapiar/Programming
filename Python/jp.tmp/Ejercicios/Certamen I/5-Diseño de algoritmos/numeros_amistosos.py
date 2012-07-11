#! /usr/bin/env python

for i in range(1000,1501):
	sumA = 0
	for k in range(1,i):
		if i%k == 0:
			sumA += k
	for j in range(i, 1501):
		if i != j:
			sumB = 0
			for k in range(1,j):
				if j%k == 0:
					sumB += k
			if sumA == j and sumB == i:
				print i, j
				