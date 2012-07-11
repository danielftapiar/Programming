#! /usr/bin/env python
#coding: utf-8

lado = int(raw_input('Lado: '))

for i in range(lado):
	print ' '*(lado-i) + '*'*(lado+i*2)

for i in range(lado-2,-1,-1):
	print ' '*(lado-i) + '*'*(lado+i*2)

