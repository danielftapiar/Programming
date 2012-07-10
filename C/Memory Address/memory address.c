#include "stdio.h"
#include "string.h"

int main(int argc, char const *argv[])
{
	char x = 'b';
	char *pchar;
	char *address = &x;
	int i;

	printf("Address in Hexadecimal is: %p \n", address);
	printf("Address in Decimal is: %d \n", (int)address );

	char array[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";

	printf("%s\n", array);
	
	for (i = 0; i < 53; ++i)
	{
		pchar = &array[i];
		printf("Array Letter: %c    | ", array[i]);
		printf("Decimal: %d |  ", (int)array[i]);
		printf("Address in Hexadecimal for position %d is: %p\n",i, pchar);
	}


	return 0;

}

