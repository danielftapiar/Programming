#! /usr/bin/env python

for i in range(1,2000):
	for j in range(i,2000):
		for k in range(j,2000):
			if (i**3 + j**3 + k**3) == 100:
				print i, j, k
			if (i**3 + j**3 - k**3) == 100:
				print i, j, k
			if (i**3 - j**3 + k**3) == 100:
				print i, j, k
			if (i**3 - j**3 - k**3) == 100:
				print i, j, k
			if (-i**3 + j**3 + k**3) == 100:
				print i, j, k
			if (-i**3 + j**3 - k**3) == 100:
				print i, j, k
			if (-i**3 - j**3 + k**3) == 100:
				print i, j, k
			if (-i**3 - j**3 - k**3) == 100:
				print i, j, k