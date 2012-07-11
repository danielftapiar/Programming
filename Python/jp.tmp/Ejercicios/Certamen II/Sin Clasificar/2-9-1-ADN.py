#! /usr/bin/env python

dna = ['00000101010101010101', '00101010101101110111', '00100010010000001001']
nombres = ['Pedro', 'Juan', 'Diego']

def parentezco(secuencia):
	porcentaje = -1

	for i in range(len(dna)):
		sumPorcentaje = 0
		for j in range(20):
		
			if dna[i][j] == secuencia[j]:
				sumPorcentaje += 1
				
		if porcentaje < sumPorcentaje:
			porcentaje = sumPorcentaje
			who = nombres[i]
		
	return porcentaje*5, who
	
secuencia = raw_input('Ingrese secuencia: ')

who = parentezco(secuencia)

print 'El culpalbe es', who[1],
print 'con un parentezco de', str(who[0]) +'%'
