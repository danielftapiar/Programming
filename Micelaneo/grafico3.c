/*
 PROPUESTA GRAFICO 1
 
 Este es el tipo de grafico mas simple
 que pude hacer...
 para probarlo deben tener la libreria 
 curses.h (se llama Ncurses)
 
 para compilar lo hacen asi:
 
 gcc grafico.c -o a -Wall -lncurses
 
 las constantes alto, ancho y escala
 son constantes que definen como se vera el grafico generado
 
 la funcion barra recive 2 parametros, el primero es el
 numero en si, y el segundo corresponde a el algoritmo
 al que se le asocia.
 
 asi barra(50, 4) le asocia al algoritmo 4, una barra de tamaño 50
 en una escala de escala (100) u otra.
 
 ojala la prueben para que me digan si les funciona como a mi,
 o se les ve deforme, manden un screenshot.
 
 */
#include <curses.h> 
#include <stdio.h>

void barra(int total, int algoritmo, int alto, int ancho, int escala);
void crearGrafico(int alto, int ancho, int escala) ;
 
void barra(int total, int algoritmo, int alto, int ancho, int escala) {
	int porcentaje;
	int i;
	
	/* Calculo de el porcentaje (alto de la barra) segun
	   el alto y la escala de el grafico: */
	porcentaje = alto*total/escala;
	
	init_pair(2, 7, 4);
	attron(COLOR_PAIR(2));
	
	for(i = porcentaje; i>=1; i--){
		move(alto-i, (ancho-5)/4*algoritmo-2);
			printw("     ");
	}
	move (alto-1,(ancho-5)/4*algoritmo-1 );
	printw("%3d", total);
}

void crearGrafico(int alto, int ancho, int escala) {
	int i, j;
	
	if (has_colors()) start_color();
	init_pair(1, COLOR_BLACK, COLOR_WHITE);
	attron(COLOR_PAIR(1));
	for (i = 0; i <= alto+2; i++)
		for (j = 0; j <= ancho+2; j++){
			move(i,j);
			printw(" ");
		}
	
	for(i = 1; i <= ancho ;i++) {
		move(alto-1,i);
		printw("_");
	}
	
	for(i=1; i<=4; i++){
		move(alto, (ancho-5)/4*i);
		printw("%d", i);
	}

	for(i = 0; i < alto; i++) {
		move(i,1);
		/* FORMA 1: */
		if (i % 2 == 0) 
			printw("%3d%c", escala - i*escala/alto, '|');
		else
			printw("%4c", '|');

		/* FORMA 2: 
		printw("%3d%c", escala - i*escala/alto, '|');
		descomentar para ver... y comentar la otra... */
		
	}
	
	move(alto+2, ancho/2);
	printw("Algoritmos");
}