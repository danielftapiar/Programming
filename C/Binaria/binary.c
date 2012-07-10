#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int searching (int *arr1, int a, int search);

int main (int argc, char *argv[])
{
	int *arr, a,i, search,cont;
	printf("Ingrese la cantidad de datos a ingresar \n");
	scanf("%d", &a);
	arr=(int*)malloc(a*sizeof(int));
	for (i = 0; i < a; i += 1)
	{
		arr[i]=i+1;
		printf("%d ", arr[i]);
	}
	printf(" \n");
	printf("Ingrese Numero para buscar \n");
	scanf("%d", &search);
	cont=searching(arr, a, search);
	printf("%d \n", cont);
	free(arr);
	return 0;
}

int searching (int *arr1, int a, int search)
{
	int cont=0;
	
	while(a!=1)
	{
		a=a/2
		if(a/2>search)
			{
			cont++;
			if(arr1[a]==search)
				return cont;
		}
		else
		{
			
		}
			
	}
	return 0;
}

