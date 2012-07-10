#include <stdio.h>
#include <string.h>

void strip (char *str, int size)
{
	int i;
	for (i = 0; i < size; i += 1)
	{
		if (str[i]=='\n')
		{
			str[i]='\0';
		}
	}
	
}

int main (int argc, char *argv[])
{
	char read[100];
	read[0]='\0';
	FILE *wri=fopen("test.txt", "w+");
	if(wri)
	{
		printf("El archivos se abrio \n");
	}
	else
	{
		printf("El Archivo no se abrio \n");
	}
	fprintf(wri, "Archive 3...testing..");
	
	
	
	
	
	fgets(read, 100, wri);
	printf("The text reads %s \n", read);
	char name[50];
	char last[50];
	char full[100];
	char fullname[100];
	printf("Ingrese su Nombre: \n");
	fgets(name, 50, stdin);
	strip(name, 50);
	printf("Ingrese su Apellido \n");
	fgets(last, 50, stdin);
	strip(last, 50);
	if (strcmp(name, "Daniel")==0)
	{
		printf("%s That's my name too!' \n", name);
	}
	full [0]='\0';
	strcat (full, name);
	strcat (full, " ");
	strcat (full, last);
	strcpy (fullname, full);
	printf("Your full name is %s \n", full);
	printf("Your full name is %s \n", fullname);
	fclose(wri);
	return 0;
}
