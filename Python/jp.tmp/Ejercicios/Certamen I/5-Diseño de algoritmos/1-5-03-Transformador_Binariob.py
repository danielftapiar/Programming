#! /usr/bin/env python


def dec2bin(decimal):
	i = 0
	binario = 0

	while decimal!=0:
		binario += decimal%2 * (10)**i
		i+=1
		decimal/=2

	return binario
	
print dec2bin(10)