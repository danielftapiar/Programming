#include <stdio.h>

void swap (int *x, int *y);
int main()
{ 
	int a,b;
	printf("Ingrese Valor de A:\n");
	scanf("%d", &a);
	printf("Ingrese Valor de B: \n");
	scanf("%d", &b);
	swap (&a, &b);
	printf("El valor de A es %d \n",a);
	printf("El valor de B es %d \n",b);
	return 0;
	
}

void swap (int *x, int *y)
{
	int aux;
	aux=*x;
	*x=*y;
	*y=aux;
	
}




