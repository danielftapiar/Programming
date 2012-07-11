#include <stdio.h>
#include <stdlib.h>
#include "grafico3.c"
#define True 1
#define False 0

int suma(int list[], int size, int *instrucciones); /* SUMA LINEAL */
bool cuadradoMagico(int tmp[], int size, int *instrucciones); /* CUADRADO MAGICO */
int search(int list[], int size, int num, int *instrucciones); /* BUSQUEDA BINARIA */
int fibo(int n, int *instrucciones); /* FIBONACCI */


int main(int argc, char *argv[]) {
	FILE *entrada = fopen("Entrada.txt", "r");
	FILE *salida = fopen("Salida.txt", "w");
	int casos;
	int i, j;
	int size, find;
	int *tmp;
	int instrucciones;
	int *a1, *a2, *a3, *a4; /* estos guardaran los valores de tamaños e instruccioens */
	/* ver si el archivo de entrada se abio o no */
	int alto = 15; /* CASI SIEMPRE CONSTANTE... 15 esta bien */
	int ancho = 50; /* CASI SIEMPRE CONSTANTE... 50 esta bien (min es 33) */
	int escala = 100;
	
	
	if (!entrada) {
		printf("El archivo no se ha podido abrir\n");
		return 1;
	}
	
	fscanf(entrada, "%d", &casos); /* leemos la cantidad de veces
									que los algiritmos se ejecutaran */
									
	a1 = (int *)malloc(sizeof(int)*casos*2);
	a2 = (int *)malloc(sizeof(int)*casos*2);
	a3 = (int *)malloc(sizeof(int)*casos*2);
	a4 = (int *)malloc(sizeof(int)*casos*2);
	
	for (i = 0; i < casos; i++) { /* segun eso ejecutamos n-veces */		
		/* PRIMER ALGORITMO */		
		fscanf(entrada, "%d", &size); /* leemos el tamaño */
		
		tmp = (int *)malloc(sizeof(int)*size); /* alocamos la memoria */
		
		for (j=0; j<size; j++)
			fscanf(entrada, "%d", &tmp[j]); /* llenamos el arreglo nuevo */
		instrucciones = 0;
		suma(tmp, size, &instrucciones);
		//printf("Tamanno: %d\n", size);
		//printf("Instrucciones Suma: %d\n", instrucciones);
		a1[2*i] = size;
		a1[2*i+1] =  instrucciones;
		free(tmp); /* liberamos la memoria */
		
		
		/* SEGUNDO ALGORITMO */
		instrucciones = 0;
		fscanf(entrada, "%d", &size); /* leemos el tamaño */

		tmp = (int *)malloc(sizeof(int)*(size*size)); /* alocamos la memoria */
		
		for (j=0; j<(size*size); j++)
			fscanf(entrada, "%d", &tmp[j]); /* llenamos el arreglo nuevo */
		cuadradoMagico(tmp, size, &instrucciones);
		//printf("Tamanno: %d\n", size);
	//	printf("Instrucciones Magico: %d\n", instrucciones);
		a2[2*i] = size;
		a2[2*i+1] =  instrucciones;
		free(tmp); /* liberamos la memoria */
		
		
		/* TERCER ALGORITMO */
		instrucciones = 0;
		fscanf(entrada, "%d", &size); /* leemos el tamaño */
		fscanf(entrada, "%d", &find); /* leemos cual buscar */
		
		tmp = (int *)malloc(sizeof(int)*(size)); /* alocamos la memoria */
		
		for (j=0; j<(size); j++)
			fscanf(entrada, "%d", &tmp[j]); /* Llenamos este arreglo nuevo */
		
		search(tmp, size, find, &instrucciones); /* ejecutamos el tercer algoritmo */
	//	printf("Tamanno: %d\n", size);
		//printf("Instrucciones binaria: %d\n", instrucciones);
		a3[2*i] = size;
		a3[2*i+1] =  instrucciones;
		free(tmp);
		
		/* CUARTO ALGORITMO */
		instrucciones = 0;
		fscanf(entrada, "%d", &find); /* leemos el numero */
		fibo(find, &instrucciones);
		//printf("Tamanno: %d\n", find);
		//printf("Instrucciones Fibo: %d\n\n", instrucciones);
		a4[2*i] = find;
		a4[2*i+1] =  instrucciones;
	}
	
	fclose(entrada);
	
	if (salida == NULL){
		printf("No se ha podido abrir el archivo salida.txt\n");
		return 1;
	}
	
	/* generar la salida */
	fprintf(salida, "Algoritmo 1\n");
	fprintf(salida, "Tamanno\t\tN medio Instrucciones\n");
	for (i = 0; i<casos*2; i++){
		fprintf(salida, "%d\t\t", a1[i]);
		if ((i+1)%2 == 0)
	
			fprintf(salida, "\n");
	}
	fprintf(salida, "\nAlgoritmo 2\n");
	fprintf(salida, "Tamanno\t\tN medio Instrucciones\n");
	for (i = 0; i<casos*2; i++){
		fprintf(salida, "%d\t\t", a2[i]);
		if ((i+1)%2 == 0)
			fprintf(salida, "\n");
	}
	fprintf(salida, "\nAlgoritmo 3\n");
	fprintf(salida, "Tamanno\tN medio Instrucciones\n");
	for (i = 0; i<casos*2; i++){
		fprintf(salida, "%d\t\t", a3[i]);
		if ((i+1)%2 == 0)
			fprintf(salida, "\n");
	}
	fprintf(salida, "\nAlgoritmo 4\n");
	fprintf(salida, "Tamanno\t\tN medio Instrucciones\n");
	for (i = 0; i<casos*2; i++){
		fprintf(salida, "%d\t\t", a4[i]);
		if ((i+1)%2 == 0)
			fprintf(salida, "\n");
	}
	printf("\n");
	free(a1); free(a2); free(a3); free(a4);
	
	fclose(salida);
	
	/* grafico */
	initscr();
	for (i = 0; i<casos; i++){
		escala = max(a1, a2, a3, a4, casos);
		
		crearGrafico(alto, ancho, escala);
	
		barra(50, 1, alto, ancho, escala);
		barra(10, 2, alto, ancho, escala);
		barra(75, 3, alto, ancho, escala);
		barra(23, 4, alto, ancho, escala);
	
		move(alto+2, ancho+2);
	
		refresh();
		getch();
	}
	
	endwin();
	/* fin grafico */
	return 0;
}

/* FUNCIONES */

//int max(int *a1, int *a2, int *a3, int *a4, int casos) {
	//int i;
	
	//for (i = 0; i < casos*2; i++){
		/* AQUI VOY */
	//}
//}

int suma(int list[], int size, int *instrucciones) {
	int i;
	int suma;

	for (i = 0; i < size; i++) {
		(*instrucciones) +=  3; // i = 0; i < size; i++
		suma += list[i]; (*instrucciones)++;
		(*instrucciones)++; //GOTO implicito
	}
	
	(*instrucciones)++;
	return suma;
}

bool cuadradoMagico(int tmp[], int size, int *instrucciones) {
	int i, j;
	int filas, filasOld;
	int columnas, columnasOld;
	int diagonalA = 0; (*instrucciones)++;
	int diagonalB = 0; (*instrucciones)++;
	int list[size][size];
	int c = 0; /* Solo la usamos para crear la matriz a partir de un arreglo unidimensional. */
	
	/* Creamos una matriz a partir de un arreglo unidimencional */
	for (i = 0; i<size; i++)
		for (j = 0; j<size; j++, c++) 
			list[i][j] = tmp[c];
	/* fin eso mismo =) */
	
	/* sumamos y comparamos las filas con filas, y columnas con columnas */
	for (i = 0; i < size; i++) {
		(*instrucciones) += 3; /* i = 0; i < size; i++*/
		
		filas = 0; (*instrucciones)++;
		columnas = 0; (*instrucciones)++;
		
		for (j=0; j<size; j++) {
			(*instrucciones) += 3; /* i = 0; i < size; i++*/
			filas += list[i][j];  (*instrucciones)++;
			columnas += list[j][i];  (*instrucciones)++;
		}  (*instrucciones)++; /* Goto implicito */
		
		(*instrucciones)++; /* una comparacion */
		if (i == 0) {
			filasOld = filas; (*instrucciones)++;
			columnasOld = columnas; (*instrucciones)++;
		}
		
		(*instrucciones) += 2;  /* 2 comparaciones en el if*/
		if (filas != filasOld || columnas != columnasOld) {
			return False;  (*instrucciones)++;
		}
		(*instrucciones)++; /* GOTO implicito for */
	}

	/* suammos las diagonales */
	for (i=0; i<size; i++) {
		(*instrucciones) += 3; /* i = 0; i < size; i++*/
		diagonalA += list[i][i];   (*instrucciones)++;
		diagonalB += list[size-(i+1)][size-(i+1)];   (*instrucciones)++;
		(*instrucciones)++; /* GOTO implicito for */
	}
	
	(*instrucciones)++; /* una comparacion */
	if (diagonalA != diagonalB){
		(*instrucciones)++;
		return False;
	}
	
	/* vemos si las filas son igales a las columnas iguales a las diagonales */
	(*instrucciones) += 2;  /* Dos comparaciones */
	if (columnas == filas && filas == diagonalA){
		(*instrucciones)++;
		return True;
	}
	else{
		(*instrucciones)++;
		return False;
	}
}

int search(int list[], int size, int num, int *instrucciones) {
	int isThis;
	int top;
	int piso;
	
	piso = 0;  (*instrucciones)++;
	top = size;  (*instrucciones)++;
	isThis = (size-1)/2;  (*instrucciones)++;  /* inicia en la mitad de el arreglo */
	
	while (num != list[isThis]) {
		(*instrucciones)++; /* comparacion de el while */
		
		(*instrucciones)++; /* Comparacion del if */
		if (list[isThis] < num) { 					  	     /* si el numero es mayor que isThis */
			piso = isThis;  (*instrucciones)++;		 		 /* el mas chico(piso) se transforma en isThis */
			isThis = (isThis + top)/2;   (*instrucciones)++; /* isThis se transforma en la mitad de la distancia
										  entre el ultimo(top) e isThis */
		}
		(*instrucciones)++; /* Comparacion del if */
		if (list[isThis] > num) { 	 						/* si el numero es menor que isThis */
			top = isThis;	(*instrucciones)++;	            /*el mayor se transforma en isThis */
			isThis = (isThis + piso)/2;	(*instrucciones)++;	/* isThis se transforma en la mitad de la distancia
											entre isThis y el mas chico(piso) */
		}
	}
	
	(*instrucciones)++;
	return isThis; /* retorna la posicion en el arreglo de el numero */
}


int fibo(int n, int *instrucciones) {
	(*instrucciones)++; /* Una comparacion*/
	if (n < 2){
		(*instrucciones)++;
		return n;
	}
	else{
		(*instrucciones)++;
		return fibo(n-1, instrucciones) + fibo(n-2, instrucciones);
	}
}
