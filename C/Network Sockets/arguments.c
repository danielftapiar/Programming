#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
	int i;

	if (argc == 2)
	{
		fprintf(stderr, "argc = 2\n");
	}
	else
	{
		for(i=0; i<argc; i++)
		{
			fprintf(stderr, "The first argument is: %s \n", argv[i]);		
		}
	}
	return 0;
}