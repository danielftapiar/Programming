#! /usr/bin/env python

from Tkinter import *

def acorde():
	nota = notaEntry.get().lower() #En vez de pasarlas por el
	tipo = tipoEntry.get().lower() #argumento de la funcion acorde(nota, tipo)
	
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
	
	if tipo not in acordes:
		acorde.set('Tipo no existe')
		return
	
	if nota not in notas:
		acorde.set('Nota no existe')
		return
	
	result = []
	if nota in notas:
		result.append(nota)
		where = notas.index(nota) #donde esta la nota
		for num in acordes[tipo]:
			result.append(notas[(num+where)%12])
			where = (num+where)%12 #a donde le sumo el acorde correspondiente
			                       #y saco el modulo %12 por que da vueltas...
	
	result = 'Acorde: '+'-'.join(result)
	acorde.set(result)
	
	
if __name__ == '__main__':
	root = Tk()
	root.title('Acordes')
	root.geometry('320x100+50+50')
	
	#Ingrese nota - Texto
	notaTexto = Label(root, text='Nota:')
	notaTexto.grid(row=0, column=0, sticky=E)
	
	#Ingrese tipo - Texto
	tipoTexto = Label(root, text='Tipo:')
	tipoTexto.grid(row=1, column=0, sticky=E)
	
	#Ingrese nota - Entrada
	nota = StringVar()
	notaEntry = Entry(root, textvariable=nota, width=25)
	notaEntry.grid(row=0, column=1, sticky=W)
	
	#Ingrese tipo - Entrada
	tipo = StringVar()
	tipoEntry = Entry(root, textvariable=tipo, width=25)
	tipoEntry.grid(row=1, column=1, sticky=W)
	
	#Boton
	ver = Button(root, text='Ver Acorde', command=acorde)
	ver.grid(row=2, column=0, sticky=W)
	
	#Mostrar Acorde
	acorde = StringVar()
	acordeLabel = Label(root, textvariable=acorde)
	acordeLabel.grid(row=2, column=1, sticky=W)
	
	
	root.mainloop()