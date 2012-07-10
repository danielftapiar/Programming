#include <stdio.h>
int main ()
{
	int menu,x=0,y=0,result;
	printf("Seleccione su Opcion\n");
	printf("1. Sumar\n");
	printf("2. Restar\n");
	printf("3. Multiplicar\n");
	printf("4. Dividir\n");
	printf("5. Minimo Comun Multiple\n");
	printf("6. Potencia\n");
	printf("7. Raiz Cuadrada\n");
	scanf("%d", &menu);	
	switch (menu)
	{
	case 1:
	{
			printf("Ingrese Numeros para Sumar\n");
			scanf("%d", &x);
			scanf("%d", &y);
			result=x+y;
			printf("%d + %d = %d \n" ,x,y,result);
			break;
	}
	case 2:
		{
			printf("Ingrese Numeros para Restar\n");
			scanf("%d", &x);
			scanf("%d", &y);
			result=x-y;
			printf("%d - %d = %d \n" ,x,y,result);
			break;
		}
	case 3:
		{
			printf("Ingrese Numeros para Multiplicar\n");
			scanf("%d", &x);
			scanf("%d", &y);
			result=x*y;
			printf("%d * %d = %d \n" ,x,y,result);
			break;
		}
	case 4:
		{
			printf("Ingrese Numeros para Dividir\n");
			while(y==0)			
			{
				scanf("%d", &x);
				scanf("%d", &y);
			}
			result=x/y;
			printf("%d / %d = %d \n" ,x,y,result);
			break;
		}
	case 5:
	case 6:
	case 7:
	default:
	;
	
	}
return 0;
}


