#! /usr/bin/env python

hora_actual = int(raw_input('Hora actual: '))
cantidad_horas = int(raw_input('Cantidad de horas: '))

hora_futura = (hora_actual + cantidad_horas) % 12
# Siempre que se refieran a la posicion futura
# de un proceso ciclico, usamos la suma de la
# (posicon actual + avanze), y a esto le sacamos
# el modulo(%) de la cantidad de elementos que tiene
# el ciclo. En este caso, la cantidad de elementos que
# hay en el ciclo antes de que se repita son 12...
# (cada 12 horas, la hora es igual)
 
print 'En', cantidad_horas, 'horas el reloj marcara las', hora_futura