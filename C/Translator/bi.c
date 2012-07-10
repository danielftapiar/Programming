#include <stdio.h>

int menu(int y);
int *binario(int x);
int octal(int z);
int hexadecimal(int x);

int main (int argc, char *argv[])
{
	int a, menu1;
	int *ptrarr;
	printf("Ingrese Numero \n");
	scanf("%d", &a);
	menu1=menu(0);
	switch (menu1)
	{
	case 1:
	ptrarr=binario(a);
	break;
	case 2:
	hexadecimal(a);
	break;
	case 3:
	break;
	}
	return 0;
}

int menu(int x)
{
	int verify=0;
	while(verify<1 || verify>3)
	{
	printf("Traducir a: \n");
	printf("1. Binario \n");
	printf("2. Hexadecimal \n");
	printf("3. Octal \n");
	scanf("%d", &verify);
	}
	return verify;
}

int *binario (int x)
{
	int i,a;
	int *ptr;
	int arr[8];
	for (i = 7; i>=0; i --)
	{
		if (x%2==0)
			arr[i]=0;
		else
			arr[i]=1;
		x=x/2;
		if (x==0)
		{
			for (a = 0; a< i; a++)
			{
				arr[a]=0;
			}
			i=0;
		}
		
	}
	for (i = 0; i < 8; i ++)
	{
		printf("%d ", arr[i]);
		if (i==7)
		printf(" \n");
	}
	ptr=arr[0];
	return ptr;
}

int hexadecimal(int x)
{
	int *ptr;
	ptr=binario(x);
	printf("%d \n", *ptr);
}
