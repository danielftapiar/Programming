#include <stdio.h>
#include <stdlib.h> /* para malloc */

int menu(void);  /* no necesita argumentos, es un procedimiento */
int *binario(int x);

int main (int argc, char *argv[])
{
	int a, i;
	int *arr;
	
	printf("Ingrese Numero \n");
	printf("The size of %ld \n", sizeof(arr) ); /* <-Esta linea no la entiendo
												 sizeof(arr) = 8 por q el tamaño de un puntero es 8
												 sizeof(*arr) = 4 por q el tamaño de lo que apunta el puntero es un entero,
												 (int) y estos tienen tamaño 4. q tamaño tienes q imprimir??
												*/
	scanf("%d", &a);

	switch(menu()) /* Todo se ejecuta de adentro para afuera, primero menu, luego se evalua switch
					con su valor de retorno
					*/
	{
		case 1:
			arr = binario(a); /* aqui recien arr empieza a apuntar a algo */
			
			for (i = 0; i < 8; i ++)
				printf("%d ", *(arr+i));
			
			printf(" \n");
	
			free(arr); /* Aqui lo liberamos, si no se muere un hada. al igual que
						  al leer mas alla de los limites de un arreglo, lo que
						  se conoce como Segmentation Fault.
						*/
			break;
		case 2:
			printf("=) hexadecimal");
		break;
		case 3:
			break;
	}
return 0;
}

int menu(void)
{
	int verify;
	do
	{
		printf("Traducir a: \n");
		printf("1. Binario \n");
		printf("=) no choice: ");
		scanf("%d", &verify);
	}while(verify<1 || verify>3);
	
	return verify;
}

int *binario (int x)
{
	int i;
	int *otroArr;
	
	otroArr = (int *)malloc(sizeof(int)*8); /* arreglo dinamico de tamaño 8*sizeof(int) */
	
	for (i=0; i<8; i++) /* Llenamos la memoria con 0s */
		otroArr[i]=0;
	
	i = 7;
	while (x!=0)
	{
		if (x%2==0)
			otroArr[i]=0;
		else
			otroArr[i]=1;
		x /= 2;
		i--;
	}
	
	return otroArr; /* retorna un puntero a una memoria dinamica */
}
