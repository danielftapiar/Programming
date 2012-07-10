/*
 PROPUESTA GRAFICO 1
 
 Este es el tipo de grafico mas simple
 que pude hacer...
 para probarlo deben tener la libreria 
 curses.h (se llama Ncurses)
 
 para compilar lo hacen asi:
 
 gcc grafico.c -o a -Wall -lncurses
 
 las constantes ALTO_MAX, ANCHO_MAX y ESCALA
 son constantes que definen como se vera el grafico generado
 
 la funcion barra recive 2 parametros, el primero es el
 numero en si, y el segundo corresponde a el algoritmo
 al que se le asocia.
 
 asi barra(50, 4) le asocia al algoritmo 4, una barra de tamaño 50
 en una escala de ESCALA (100) u otra.
 
 ojala la prueben para que me digan si les funciona como a mi,
 o se les ve deforme, manden un screenshot.
 
 */
#include <curses.h> 
#include <stdio.h> 
#define ALTO_MAX 15
#define ANCHO_MAX 50
#define ESCALA 100

void barra(int total, int algoritmo);
 
int main(void) {
	int i;
	char c;
   	initscr(); //????
	
	c=95;
	
	for(i = 1; i <= ANCHO_MAX ;i++) {
		move(ALTO_MAX-1,i);
		printw("%c",c);
	}
	
	for(i=1; i<=4; i++){
		move(ALTO_MAX, (ANCHO_MAX-5)/4*i);
		printw("%d", i);
	}

	c='|' ;
	for(i = 0; i < ALTO_MAX; i++) {
		move(i,1); 
		printw("%3d%c", ESCALA - i*ESCALA/ALTO_MAX, c);
	}
	
	move(ALTO_MAX+2, ANCHO_MAX/2);
	printw("Algoritmos");

	barra(50, 1);
	barra(75, 3);
	barra(23, 4);
	barra(92, 2);

	refresh();
	getch();
	endwin();
	return 0;
}

void barra(int total, int algoritmo) {
	int porcentaje;
	int i;
	
	porcentaje = ALTO_MAX*total/ESCALA;
	
	for(i = porcentaje; i>=1; i--){
		move(ALTO_MAX-i, (ANCHO_MAX-5)/4*algoritmo-2);
		if (i==porcentaje)
			printw("+");
		else
			printw("|");
	}
	
	move(ALTO_MAX - porcentaje, (ANCHO_MAX-5)/4*algoritmo-1);
	printw("---");
   	
	for(i = porcentaje; i>=1; i--){
		move(ALTO_MAX-i, (ANCHO_MAX-5)/4*algoritmo+2);
		if (i==porcentaje)
			printw("+");
		else
			printw("|");
	}
	move(0,0);
	
}
