#include <stdlib.h>
#include <stdio.h>        
#include <string.h>  
#include <time.h>

struct node {                                                 
  char *x;				                        
  struct node *next;
};
typedef struct node db;

char* rancube ();
int rancolumn (int col);
int menu ();
void viewList (db *ptr);                          // ___________________________________________________
db* append (db **L1, char *a);                    //|                                                   |
int len(db *L1);                                  //|                                                   |
void extend (db **L1, db **L2);                   //|  Declaracion de Funciones de Listas en Python     |
void insert (db **L1, int pos, char *val);        //|                                                   |
void removel (db **L1, char *val);                //|___________________________________________________|
char* pop (db **L1);
int index1 (db *L1, char *a);
int count (db *L1, char *a);
void empty(db **L1);
db* reverse(db **L1);
void checkHorizontal (db **array, int size, FILE *arch, int columna);
void checkVertical (db **array, int size, FILE *arch);	
void writeList (db *L1, FILE *arch);

int main (int argc, char *argv[])
{
	srand(time(NULL));
	FILE *arch=fopen("Jugadas.txt", "w");
	int i=0,columna,size,length=0,jugadas=1;                                    //i se usa para recorrer el for; columna es la variable donde se almacena 
	char *cubo;
	printf("Ingrese la cantidad de Columnas \n");
	scanf("%d", &size);	                                                        //size es la cantidad de pilas que se deberan usar
	

	db *array[size];
	for (i = 0; i < size; i += 1)
		array[i]=NULL;
	while(length<10)
	{
		columna=rancolumn(size);	                                            //pila al azar para que caiga un cubo al azar
		cubo=rancube();                                                         //color al azar
		array[columna-1]=append(&array[columna-1], cubo);                       //le agrega un elemento a la pila que haya sido seleccionada al azar
		fprintf(arch, "Jugada %d:Cubo %s - Pila %d \n",jugadas,cubo,columna);   //se imprime cada una de las jugadas al archivo de salida
		
		checkVertical(array,columna, arch);                                     //se verifica la regla 1 con la funcion checkVertical
		checkHorizontal(array, size, arch, columna);                            //se verifica la regla 2 con la funcion checkHorizontal
		
		if(len(array[columna-1])>length)
			length=len(array[columna-1]);                                       //aumenta la variable de longitud de la pila en 1 para provocar la salida del while.
		jugadas++;
	}
	fprintf(arch, "--JUEGO TERMINADO-- \n");                                    //sale del while cuando una pila tiene 10 cubos
	for (i = 0; i < size; i += 1)                                               //y se hara un registro del estado final de las pilas, usando la funcion len
	{
		fprintf(arch, "Pila %d [%d]: " ,i+1, len(array[i]));		
		writeList(array[i], arch); 
	}
	return 0;
}

void checkHorizontal (db **array, int size, FILE *arch, int columna)            //funcion que verifica la regla 2
{

	db *aux1=NULL;
	db *aux2=NULL;
	db *aux3=NULL;
	int i,length,length2,length3,cont,j;
	char *ver1, *ver2, *ver3;

	for(i=0;i<size;i++)
	{
		cont=0;
		aux1=reverse(&array[i]);
		aux2=reverse(&array[i+1]);
		aux3=reverse(&array[i+2]);
		while(aux1!=NULL && aux2!=NULL && aux3!=NULL)
		{
			printf("1,2,3 \n");
			length=len(array[i]);
			length2=len(array[i+1]);
			length3=len(array[i+2]);
			cont++;
			ver1=pop(&aux1);
			ver2=pop(&aux2);
			ver3=pop(&aux3);
			if(ver1==ver2 && ver1==ver3)
			{	
				for(j=0;j<=length-cont;j++)
					ver1=pop(&array[i]);
				for(j=0;j<=length2-cont;j++)
					ver2=pop(&array[i+1]);
				for(j=0;j<=length3-cont;j++)
					ver3=pop(&array[i+2]);
				fprintf(arch, "--REGLA 2 EN PILAS %d,%d,%d--\n", i+1,i+2,i+3);
			}
			
		empty(&aux1);
		empty(&aux2);
		empty(&aux3);
		}

	}
}
void checkVertical (db **array, int columna, FILE *arch)                        //funcion que verifica la regla 1
{
	char *top, *bot, *mid;                                                       
	int length;
	length=len(array[columna-1]);
	if(length>2)                                                                //si el largo de la lista es mayor que 2 comenzara a verificar si es que se tienen 3 nodos con el mismo valor
	{
		top=pop(&array[columna-1]);                                             //para ello se sacaran los ultimos 3 nodos de la lista con la funcion pop
		mid=pop(&array[columna-1]);
		bot=pop(&array[columna-1]);
		if(top==mid && top==bot)                                                //si son los 3 iguales se aplica la regla 1, es decir se eliminan los nodos
			fprintf(arch, "--REGLA 1 EN PILA %d \n", columna);
		else                                                                    //si no son iguales, se insertan nuevamente en el orden inverso al que salieron,con la funcion append
		{
			array[columna-1]=append(&array[columna-1], bot);
			array[columna-1]=append(&array[columna-1], mid);
			array[columna-1]=append(&array[columna-1], top);
		}
	}
}	

int rancolumn (int col)                                                         //esta funcion asigna un numero al azar para el cual se "colorearan" los cubos
{
	int column;
	column = rand()%col + 1;
	return column;
	
}
char* rancube()
{
	int a;
	char *color;
	
	a = rand()%4 + 1;                                                           //mediante un switch case se asigna a el color al cubo
	switch(a){
	case 1:
		color ="Amarillo";
	break;
	case 2:
		color ="Azul";
	break;
	case 3:
		color ="Verde";
	break;
	
	case 4:
		color ="Rojo";
	break;
	default: 
	printf("Fail \n");
	}
	return color;	
}

void writeList (db *L1, FILE *arch)												//funcion que no retorna nada y solo muestra la lista por pantalla,

{																	            //no modifica la lista
	db *aux;
		aux=L1;
		while(aux)
		{
			fprintf(arch,"%s ", aux->x);
			aux=aux->next;
		}	
	fprintf(arch," \n");	
}

void viewList (db *L1)												            //funcion que no retorna nada y solo muestra la lista por pantalla,
{																	            //no modifica la lista
	db *aux;
		aux=L1;
		while(aux)
		{
			printf("%s ", aux->x);
			aux=aux->next;
		}	
	printf(" \n");	
}

db* append (db **L1, char *a)											        //funcion que agrega un nodo al final de la lista (Push), se le pasa 
{			
															                    //por ** (doble puntero) el puntero Inicial de la lista para ser modificado
	db *aux=NULL;														        //por si la lista esta vacia
	aux=*L1;
	if(aux==NULL)                                                               //si la lista esta vacia, se asigna memoria para agregar un nodo al final de valor a
	{
		*L1=(db*)malloc(sizeof(db));
		aux=*L1;
		aux->x=a;
		aux->next=NULL;
	}
	else                                                                        
	{
		aux=*L1;
		while((aux->next)!=NULL)                                                //si la lista no esta vacia, se recorre llegar a NULL
		{
			aux=aux->next;
		}
	
		aux->next=(db*)malloc(sizeof(db));                                      //se asigna memoria para poder agregar un nodo de valor a
		aux=aux->next;                                                          		
		aux->x=a;
		aux->next=NULL;                                                         //y se hace que el nodo agregado ahora apunte a NULL
		
	}
	return *L1;
}

int len (db *L1)												                //función que retorna el largo de la lista, solo se le pasa una copia del puntero 
{																                //original ya que no lo modificara sino que lo recorrera
	db *aux=NULL;
	int count;
	aux=L1;
	if(aux==NULL)                                                               //si la lista esta vacia, tiene un largo 0
		count=0;
	else                                                                        //si no esta vacia, entonces tiene al menos un nodo
	{
		count=1;	
		while((aux->next)!=NULL)                                                //se recorre la lista hasta llegar a NULL y se lleva un contador de iteraciones
		{
			count++;
			aux=aux->next;		
		}
	}	
	
	return count;                                                               //retornando el contador, que es igual al largo de la lista
}

void extend (db **L1, db **L2)                                                  //funcion que recibe 2 punteros a listas y las une
{
	db *aux;
	db *newaux;
	
	aux=*L1;
	newaux=*L2;
		
	while((aux->next)!=NULL)                                                    //se recorre la primera lista hasta que se ecuentre el puntero a NULL
	{                                                                           
		aux=aux->next;
	}
	
	aux->next=newaux;                                                           //y se hace que ahora este apunte al primer nodo de la segunda lista                              
}

void insert (db **L1, int pos, char *val)						                //funcion que recibe el puntero original para ser modificado por si el usuario desea
{																                
	db *aux=NULL;
	db *aux2=NULL;
	int cont=1;                                                                 
	char *tmp;
	
	
	if(*L1==NULL || pos==1)                                                     //si la lista esta vacia o se quiere insertar en la primera posicion
	{

		if(*L1==NULL)                                                           //se si la lista esta vacia, se le asigna memoria para un nodo de valor val
		{                                                                       //y este nodo ahora apuntara a NULL
			*L1=(db*)malloc(sizeof(db));                                         
			aux=*L1; 
			aux->next=NULL;                                                       
			aux->x=val;
		}
		else                                                                    //se asigna memoria para insertar el nodo de valor val
		{
			aux=*L1;                                                            //hacemos que nuestro primer puntero ahora apunte al nuevo nodo
			*L1=(db*)malloc(sizeof(db));                                        //y luego hacemos que nuevo nodo apunte al nodo siguiente
			aux2=*L1;
			aux2->next=aux;
			aux2->x=val;
		}
	}
	else                                                                        //si la lista no esta vacia y se quiere insertar un nodo en una posicion distina que la primera
	{	
		aux=*L1;
		if(pos>len(*L1))                                                        //si la posicion que se quiere insertar es mayor que el largo de la lista
		{
			while((aux->next)!=NULL)                                            //se recorre la lista hasta llegar a NULL
			{
				aux=aux->next;
			}
			aux->next=(db*)malloc(sizeof(db));                                  //se asigna memoria para el nodo de valor val
			aux=aux->next;                                                      //y este apunta a null
			aux->next=NULL;                                                     //ahora el nuevo largo de la lista es len + 1, y la posicion en la que realmente esta guardado en nodo es en len + 1
			aux->x=val;
		}
		else
			{
			while((aux->next)!=NULL && cont!=pos)                               //si la posicion en que se quiere insertar ahora es menor o igual que el largo de la lista
			{	
					aux2=aux;                                                   //se recorre mientras no se llege a NULL y el contador auxiliar sea distinto de la posicion
					aux=aux->next;                                              //en que se quiere insertar el nodo, asi se asegura que se inserte el nodo en la posicion correcta
					cont++;                                                        
			}                                                                   
			tmp=aux->x;                                                         //se asigna memoria para un nuevo nodo y apuntamos hacia el desde la posicion en que quedo el contador
			aux2->next=(db*)malloc(sizeof(db));                                 //luego hacemos que el nuevo nodo apunte al siguiente
			aux2=aux2->next;
			aux2->next=aux;
			aux2->x=val;
		
		}
	}
	
}

void removel (db **L1, char *val)                                               //funcion que remueve el primer nodo de la lista cuyo valor sea *val
{
	db *aux=*L1;
	db *aux2;
	db *aux3;
	int found=0;
	
	if((aux->x)==val)                                                           //si se encuentra en el primer nodo, se remueve y se indica con el flag found que se encontro
	{
		aux=aux->next;
		free(*L1);
		*L1=aux;
		found=1;
	}
	if(*L1==NULL)                                                               //si la lista esta vacia, se muestra por pantalla que el valor no esta en la lista                                                                  
		printf(" \n");
	else                                                                        //si la lista no esta vacia
	{
		while((aux->next)!=NULL && found==0)                                    //se recorre la lista hasta llegar a NULL o hasa que se encuentre el valor
		{
			aux2=aux;	
			aux=aux->next;
	
			if((aux->x)==val)                                                   //si se encuentra el nodo, se remueve y se indica con el flag found que se encontro
			{
				aux3=aux->next;
				aux2->next=aux3;
				found=1;
				free(aux);
			}	
		}
	}
	if (found==0)                                                               //si no se encuentra en la lista, se muestra por pantalla 
		printf("The value isn't on the List' \n");	
	
}

void empty(db **L1)                                                             //funcion que vacia la lista, se tienen 2 casos
{
	db *aux;
	if(*L1==NULL)                                                               //si la lista ya esta vacia, se muestra por pantalla
		printf("The list is empty \n");
	else                                                                        //o se recorrela lista hasta llegar a NULL y se libera la memoria
	{
		aux=*L1;
		
		while(aux!=NULL)
		{
			aux=*L1;
			aux=aux->next;
			free(*L1);
		}
	}
}
char* pop (db **L1)                                                             //funcion que saca el ultimo nodo de la lista y retorna su valor
{
	db *aux;
	db *aux2=NULL;
	char *ret;
	aux=*L1;

	if(aux==NULL)                                                               //se comprueba que la lista no este vacia, verificando si el puntero inicial no apunta a NULL
		printf("No list Exists \n");
	else                                                                        //si tiene nodos, entonces se tienen 2 casos
	
	{

		if((aux->next)==NULL)                                                   //la lista tenga un solo nodo, entonces se retorna su valor
		{                                                                       
			ret=aux->x;
			free(aux);
			*L1=NULL;
		}
		else
		{	
			while((aux->next)!=NULL)                                            //o que la lista tenga mas de un nodo
			{                                                                   //se recorre la lista mientras lo se llege a NULL
				aux2=aux;
				aux=aux->next;
			}
			aux2->next=NULL;                                                    //entonces se usa un puntero auxiliar que apunte a NULL
			ret=aux->x;                                                         //y se retorna el valor del ultimo nodo
			free(aux);	
		}
	}
	return ret;
}

int index1(db *L1, char *a)                                                     //funcion que devuelve la posicion del primer nodo con valor a
{
	db *aux;
	aux=L1;
	int cont=0, pos=-1;
	
	if(aux==NULL)                                                               //si la lista esta vacia, entonces retorna -1
		pos=-1;
	else                                                                        //si no esta vacia se recorre mientras no se llege a NULL
	{
		while(aux)
		{
			cont++;                                                             //en cada iteracion se sumara 1 a un contador auxiliar
			if(aux==NULL)                                                       
				break;
			if((aux->x)==a)                                                     //si se encuentra el valor, se devolvera el valor del contador auxiliar
				{
					pos=cont;
					break;
				}
			aux=aux->next;	
		}
	}
	return pos;
}

int count (db *L1, char *a)                                                     //funcion que retorna la cantidad de nodos que tienen valor "a" en la lista
{
	db *aux;
	int cont=0;
	aux=L1;
	printf("1 \n");
	if (L1==NULL)                                                               //si la lista esta vacia, retornara el contador=0
		return cont;
	else                                                                        //si la lista no esta vacia, entonces la recorrera hasta llegar a NULL
	{                                                                           //sumando 1 al contador cada vez que se encuentre con un nodo "a"
		while((aux->next)!=NULL)
		{
			if((aux->x)==a)
				cont++;
			aux=aux->next;	
		}
		
	}
	if((aux->x)==a)                                                             
		cont++;
	return cont++;
}

db* reverse (db **L1)                                                           //funcion que invierte los nodos de la lista
{
	
	db *new=NULL;
	while(len(*L1)>0)
	{
		new=append(&new, pop(L1));                                              //uno a uno se sacan los nodos de la lista mediante con la funcion pop 
	}                                                                           //y se guardan uno a uno en una nueva lista con la funcion append
	L1=&new;
	return new;
}


