#include <stdio.h>

int main(int argc, char *argv[]) {
	FILE *archivo = fopen("miFile.txt", "w");
	
	if (!archivo) {
		printf("El archivo no se pudo abrir!");
		return 1;
	}
	
	fprintf(archivo, "Probando...");
	
	fclose(archivo);
	
	return 0;
}
