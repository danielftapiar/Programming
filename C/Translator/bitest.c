#include <stdio.h>
#include <stdlib.h>

int arr[8];
int menu(void);
int *binario(int x);
int octal(int z);
int *hexadecimal(int x);
int *c2 (int *arrptr, int x);
int *c1 (int *arrptr, int x);
int *sumabinario(int *arr1, int *arr2);

int main (int argc, char *argv[])
{
	int a, i;
	int *arr, *arrc;
	printf("Ingrese Numero \n");
	scanf("%d", &a);
	switch (menu())
	{
		case 1:
			arr=binario(a);
			for (i = 0; i < 8; i ++)
				printf("%d ", *(arr+i));
		
			printf(" \n");
			free(arr);
			break;
		case 2:
			arr=binario(a);
			arrc=c1(arr, a);
			for(i=0; i<8; i++)
				printf("%d ", *(arrc+i));
			printf(" \n");
			free(arr)
			break;
		case 3:
			break;
		case 4:
			arr=hexadecimal(a);
			break;
		case 5:
			break;
	}
		return 0;
}

int menu(void)
{
	int verify=0;
	while(verify<1 || verify>5)
	{
	printf("Traducir a: \n");
	
	printf("1. Binario \n");
	printf("2. C-1 \n");
	printf("3. C-2 \n");
	printf("4. Hexadecimal \n");
	printf("5. Octal \n");
	scanf("%d", &verify);
	}
	return verify;
}

int *binario (int x)
{
	int i;
	int *arr2;
	
	arr2=(int *)malloc(8 * sizeof(int)); //   arrayname = (type *) malloc (numberOfElements * sizeof(type));
	
	for (i = 0; i < 8; i += 1)
	{
		arr2[i]=0;
	}
	i=7;
	while (x!=0)
	{
		if (x%2==0)
			arr2[i]=0;
		else
			arr2[i]=1;
		x=x/2;
		i--;
	}
	return arr2;
}

int *c2 (int *arrptr, int x)
{	
	int *c2;
	c2= (int *)(8*sizeof(int));
	if(x>=0)
		c2=binario(x);
	else
	{	
		c2=c1(binario(x), x);
	}
	return c2;
}

int *c1 (int *arrptr, int x)
{
	int i;
	int *c1;
	c1=(int *)malloc(8 * sizeof(int));
	if(x>=0)
		c1=binario(x);
	else
	{
		for (i = 0; i < 8; i += 1)
		{
			if(arrptr[i]==0)
				c1[i]=1;
			else
				c1[i]=0;
		}
	}
	return c1;
}

int *sumabinario(int *arr1, int *arr2)
{
	int i;
	int *total;
	int acarreo;
	total = (int *)malloc(8*sizeof(int));
	for (i = 7; i < 0; i --)
	{
		if (arr1[i]+arr2[i]+acarreo==0)
		{
			total[i]=0;
			acarreo=0;
		}
		else if (arr1[i]+arr2[i]+acarreo==1)
		{
			total [i]=1;
			acarreo=0;
		}
		else if (arr1[i]+arr2[i]+acarreo==2)
		{
			total[i]=0;
			acarreo=1;
		}
	}
	return total;		
}

int *hexadecimal(int x)
{
	int i;
	int *arr3;
	
	arr3=binario(x);
	for (i = 0; i < 8; i += 1)
	{
		if (i%4==0)
		{
			//mucha paja
		}
	} 
	return arr3;
	
}

