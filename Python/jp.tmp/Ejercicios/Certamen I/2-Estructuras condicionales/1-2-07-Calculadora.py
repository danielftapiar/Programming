#! /usr/bin/env python

op1 = int(raw_input('Operando: '))
operador = str(raw_input('Operador: '))
op2 = int(raw_input('Operando: '))

if operador=='+':
	print op1, operador, op2, '=', op1+op2
elif operador=='-':
	print op1, operador, op2, '=', op1-op2
elif operador=='*':
	print op1, operador, op2, '=', op1*op2
else:
	print op1, operador, op2, '=', op1/op2