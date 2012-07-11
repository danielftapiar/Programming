# include <stdlib.h>
# include <stdio.h>

int SumaNumeros(int A[], int n)
{
  int i, suma=0;
  for(i=0;i<n;i++)
    {
      suma+=A[i];
    }    
  printf("Algoritmo 1: Suma arreglo: %d\n\n\n\n",suma);
  return 0;
}

int Fibonacci(int n)
{
  if (n<2)
    return n;
  else
    return Fibonacci(n-1) + Fibonacci(n-2);
}

int main ()
{
  int a, h, i, n;
  int *ptr; /// puntero
  char s,t,u;
  FILE *arch1;
  arch1=fopen("./entrada.txt","r"); /// abro archivo
  fscanf (arch1, "%c", &s); /// leo primera linea en busqueda de la cantidad de veces
  printf("Linea 32: %c valor de s\n", s);
  h=atoi(&s); /// transformo
  printf("Linea 34: %d valor de h, si h y s son iguales se cumple la funcion atoi.\n", h);/// compruebo
  ptr=(int *)malloc(sizeof(int)*4*h); ///guardo toda la memoria que necesito
  
 for (a=0;a<h;a++) ///realizo 'h' veces
   {  
     fscanf (arch1, "%s", &t); /// 'debiera' leer 1er elemento de fila 2n+2 (2a temporalmente),para el tamaño del arreglo.
     n=atoi(&t); /// t, a entero n
     printf("Linea 40: %d valor de n\n", n); /// mostrar n
     for(i=0;i<n;i++) /// repetir lectura de datos e ir transform´andola para conseguir la suma
		{
	 fscanf (arch1, "%s", &u); ///leo despues del tamaño arreglo, y voy guardando los strings del archivo
	 ptr[i]=atoi(&u); /// transformo todo el string a un arreglo 
		}
	   	   
     SumaNumeros(ptr,n); /// llamo a funcion con parametros ptr (arreglo), n (veces)
     /*fscanf(arch1, "%s", &w);
     d=atoi(&w);
     Fibonacci(d);
     printf ("Funcion fibonacci da : %d\n\n", d);*/
     fclose (arch1);
   }
 free(ptr); /// libero espacio dinamico reservado
 return 0;
}
