#!/usr/bin/env python

def predicado(p, q, r):
	return (not p) and (q or r)

def tabla_verdad(predicado):
	print 'p' + ' '*5 + 'q' + ' '*5 + 'r' + ' '*5 + 'predicado'
	print '='*5 + ' ' + '='*5 + ' '+'='*5+' '+'='*9
	
	for i in [True, False]:
		for j in [True, False]:
			for k in [True, False]:
				print "%5s" % bool(i),
				print "%5s" % bool(j),
				print "%5s" % bool(k),
				print "%5s" % bool(predicado(i, j, k))
				
tabla_verdad(predicado)