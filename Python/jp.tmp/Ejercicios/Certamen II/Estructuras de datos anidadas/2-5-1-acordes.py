#! /usr/bin/env python

def acorde(nota, tipo='mayor'):
	acordes = {
	'mayor': (4, 3),
	'menor': (3, 4),
	'aumentado': (4, 4),
	'disminuido': (3, 3),
	'sus 2': (2, 5),
	'sus 4': (5, 2),
	'5': (7,),
	'menor 7': (3, 4, 3),
	'mayor 7': (4, 3, 4),
	'7': (4, 3, 3),
	}

	notas = ['do', 'do#', 're', 're#', 'mi', 'fa', 'fa#', 'sol', 'sol#', 'la', 'la#', 'si']
	
	result = []
	if nota in notas:
		result.append(nota)
		where = notas.index(nota)
		for num in acordes[tipo]:
			result.append(notas[(num+where)%12])
			where = (num+where)%12
	return result
	
def main():
	print 'Escriba exit para salir'
	while True:
		nota = raw_input('Nota: ')
		if nota == 'exit':
			break;
		tipo = raw_input('Tipo: ')
		if tipo == 'exit':
			break;
		else:
			print acorde(nota, tipo)
		
if __name__ == '__main__':
	main()