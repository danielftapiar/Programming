#include <stdio.h>

int main(int argc, char *argv[]) {
	FILE *archivo = fopen("miFile.txt", "r");
	char linea[20];
	
	if (!archivo) {
		printf("El archivo no se pudo abrir!");
		return 1;
	}
	
	fgets(linea, 19, archivo);
	
	printf("%s\n", linea);
	fclose(archivo);
	
	return 0;
}