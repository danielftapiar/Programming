#! /usr/bin/env python

numero = int(raw_input('Ingrese un numero: '))

inverso = numero%10 * 100
# Cuando usamos el n % 10, estamos sacando el ultimo
# digito de el numero n.
# asi el primero digito de el numero inverso
# es el ultimo de el numero original

numero = numero/10
# cuando dvidimos un numero entero por 10,
# le estamos quitando el ultimo digito a
# el numero

inverso += numero%10 * 10
# Repetimos el proceso...

numero = numero/10
inverso += numero%10

print inverso