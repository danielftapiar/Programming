#!/usr/bin/env python

n = 0
while ( n < 1 ) or ( n > 9 ) :
  n = int ( raw_input ( 'Ingrese n : ' ) )

for i in range ( 1, n + 1 ) :
  for j in range ( n, i, - 1 ) :
      print '   ',
  for j in range ( 1, i + 1 ) :
    print j, ' ',
  for j in range ( i - 1, 0, - 1 ) :
    print j, ' ',
  print

for i in range ( n - 1, 0, - 1 ) :
  for j in range ( n, i, - 1 ) :
      print '   ',
  for j in range ( 1, i + 1 ) :
      print j, ' ',
  for j in range ( i - 1, 0, - 1 ) :
    print j, ' ',
  print

raw_input ( 'Presione enter' )