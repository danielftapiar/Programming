#! /usr/bin/env python
#coding: utf-8

estatura = float(raw_input('Estatura: '))
edad = int(raw_input('Edad: '))
peso = float(raw_input('Peso: '))

imc = peso/estatura**2

if imc<22.0:
	if edad<45:
		print 'bajo'
	if edad>=45:
		print 'medio'
if imc>=22.0:
	if edad<45:
		print 'medio'
	if edad>=45:
		print 'alto'
