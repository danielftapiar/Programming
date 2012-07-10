#include <stdio.h>
main()
{
	int n=0,suma=0,i;
	printf("Ingrese el numero hasta el cual desea sumar\n");
	scanf("%d",&n);
		
	for(i=0;i<=n;i++){
		suma=suma+i;
	}
	printf("La suma es de %d \n", suma);
return 0;
}
