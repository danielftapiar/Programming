#! /usr/bin/env python


def bin2dec(binario):
	decimal = 0
	i = 0

	while binario:
		decimal = decimal + (binario%10)*(2**i)
		i = i + 1
		binario = binario/10

	return decimal

print bin2dec(101001)