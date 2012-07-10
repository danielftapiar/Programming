#include <stdio.h>

int main (int argc, char *argv[])
{
	int i;
	char name [256];
	fgets(name, 256, stdin );
	
	
	for (i=0; i<256; i++)
	{
		if (name[i]=='/n')
		{	
			name[i]='0';
		}
	}
	printf("%s \n", name);
	return 0;
}
