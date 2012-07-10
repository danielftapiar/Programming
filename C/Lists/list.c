
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


struct node {
  int x;				
  struct node *next;
};
typedef struct node db;

int menu ();
void viewList (db *ptr);
db* append (db **L1, int a);
int len(db *L1);
void extend (db **L1, db **L2);
void insert (db **L1, int pos, int val);        			//Declaracion de Funciones de Listas en Python
void removel (db **L1, int val);
int pop (db **L1);
int index1 (db *L1, int a);
int count (db *L1, int a);
void empty(db *L1);
db* reverse(db **L1);	

int main (int argc, char *argv[])               			//Main
{
	db *head=NULL;											//Puntero de Inicio a las Listas
	int phase=1,men,length,a,pos,val,codex,times,aux;
	system("clear");

	while (phase)											//loop infinito mientras usuario no ingrese el "5"
	{
		men=menu();
		viewList(head);
		switch (men)
		{
			case 1:
				length=len(head);									//Funcion Length que retorna el largo de la lista
				printf("The Length of the List is %d \n", length);
			break;
			case 2:
				printf("What vale do you wish to add? \n");
				scanf("%d", &a);
				head=append(&head, a);								//Funcion Append que agrega un nodo al final de la lista 
			break;
			case 3:
			{
				printf("Insert Value to Remove \n");				//Funcion Remove que remueve cualquier nodo de la lista
				scanf("%d", &a);									//ingresando las coordenadas del nodo a borrar
				removel(&head, a);
			}
			break;
			case 4:
			{
				printf("Insert Position \n");
				scanf("%d", &pos);
				printf("Insert Value \n");
				scanf("%d", &val);
				system("clear");
				insert(&head, pos, val);							//Funcion Insert que inserta un valor en cualquier nodo de la lista
			}
			break;
			case 5:
				phase=0;											//Sale del Programa
			break;
			case 6:
			{
				
				aux=pop(&head);										//Funcion Pop que borra el ultimo nodo de la lista y retorna su valor
				if(aux==0)
					printf("There is no Value to Return \n");
				else
					printf("The last value is %d \n", aux);
			}
			break;
			case 7:
			{
				system("clear");
				printf("Input value \n");
				scanf("%d", &val);
				system("clear");
				codex=index1(head,val);								//Funcion Index que retorna la ubicacion en la lista del valor ingresado
				if (codex==-1)
					printf("The Number Indexed is not on the List \n");
				else
				{	
					viewList(head	);
					printf("The value is in the %dth position \n", codex);
				}	
			}
			break;
			case 8:
			{
				system("clear");
				printf("Input a value to match in List \n");
				scanf("%d", &val);
				times=count(head,val);								//Funcion Count que retorna la cantidad de veces que encuentra un determinado Valor
				system("clear");
				viewList(head);
				printf("The number %d was found %d times \n", val,times);
				
			}
			break;
			case 9:
			{
				system("clear");
				viewList(head);
				head=reverse(&head);								//Funcion que retorna la Lista inicial Invertida
				system("clear");
				viewList(head);
			}
			break;
		}
		
	}

	return 0;
}

int menu ()															//funcion menu que retorna el valor del menu hacia el main
{																	//el while e if en la funcion son para asegurar que el numero ingresado este dentro
	int i;															//del rango del menu
	while (i>9 || i<1)
	{
		printf("1. Length of the List \n");
		printf("2. Add to List \n");
		printf("3. Delete from List \n");
		printf("4. Insert Node \n");
		printf("5. Exit \n");
		printf("6. Pop \n");
		printf("7. Index \n");
		printf("8. Count \n");
		printf("9. Reverse \n");
		scanf("%d", &i);
		if(i>9 || i<1)
			printf("ERROR type a Number within the range \n");
	}
	system("clear");
	return i;
	
}

void viewList (db *L1)												//funcion que no retorna nada y solo muestra la lista por pantalla,
{																	//no modifica la lista
	db *aux;
		aux=L1;
		while(aux)
		{
			printf("%d ", aux->x);
			aux=aux->next;
		}	
	printf(" \n");	
}

db* append (db **L1, int a)											//funcion que agrega un nodo al final de la lista (Push), se le pasa 
{																	//por ** (doble puntero) el puntero Inicial de la lista para ser modificado
	db *aux;														//por si la lista esta vacia
	system("clear");
	aux=*L1;
	if(aux==NULL)
	{
		*L1=(db*)malloc(sizeof(db));
		aux=*L1;
		aux->x=a;
		aux->next=NULL;
		viewList(*L1);
	}
	else
	{
		aux=*L1;
		while((aux->next)!=NULL)
		{
			aux=aux->next;
		}
	
		aux->next=(db*)malloc(sizeof(db));
		aux=aux->next;		
		aux->x=a;
		aux->next=NULL;
		viewList(*L1);
	}
	return *L1;
}

int len (db *L1)												//funcion que retorna el largo de la lista, solo se le pasa una copia del puntero 
{																//original ya que no lo modificara sino que lo recorrera
	db *aux=NULL;
	int count;
	aux=L1;
	if(aux==NULL)
		count=0;
	else
	{
		count=1;	
		while((aux->next)!=NULL)
		{
			count++;
			aux=aux->next;		
		}
	}	
	
	return count;
}

void extend (db **L1, db **L2)                                     //funcion que recive 2 punteros a listas y las une
{
	db *aux;
	db *newaux;
	
	aux=*L1;
	newaux=*L2;
		
	while((aux->next)!=NULL)
	{
		aux=aux->next;
	}
	
	aux->next=newaux;
}

void insert (db **L1, int pos, int val)							//funcion que recive el puntero original para ser modificado por si el usuario desea
{																//insertar en el primer nodo
	db *aux=NULL;
	db *aux2=NULL;
	int cont=1, tmp;
	
	
	if(*L1==NULL || pos==1)
	{

		if(*L1==NULL)
		{
			*L1=(db*)malloc(sizeof(db));
			aux=*L1;
			aux->next=NULL;
			aux->x=val;
		}
		else
		{
			aux=*L1;
			*L1=(db*)malloc(sizeof(db));
			aux2=*L1;
			aux2->next=aux;
			aux2->x=val;
		}
	}
	else
	{	
		aux=*L1;
		if(pos>len(*L1))
		{
			while((aux->next)!=NULL)
			{
				aux=aux->next;
			}
			aux->next=(db*)malloc(sizeof(db));
			aux=aux->next;
			aux->next=NULL;
			aux->x=val;
		}
		else
			{
			while((aux->next)!=NULL && cont!=pos)
			{	
					aux2=aux;
					aux=aux->next;
					cont++;
			}
			
			tmp=aux->x;
			aux2->next=(db*)malloc(sizeof(db));
			aux2=aux2->next;
			aux2->next=aux;
			aux2->x=val;
		
		}
	}
	
	viewList(*L1);
}

void removel (db **L1, int val)

{
	db *aux=*L1;
	db *aux2;
	db *aux3;
	int found=0;
	
	if((aux->x)==val )
	{
		aux=aux->next;
		free(*L1);
		*L1=aux;
		found=1;
	}
	if(*L1==NULL)
		printf(" \n");
	else
	{
		while((aux->next)!=NULL && found==0)
		{
			aux2=aux;	
			aux=aux->next;
			if((aux->x)==val)
			{
				aux3=aux->next;
				aux2->next=aux3;
				found=1;
				free(aux);
			}	
		}
	}
	system("clear");
	if (found==0)
		printf("The value isn't on the List' \n");	
	
	viewList(*L1);
}

void empty(db *L1)
{
	db *aux;
	if(L1==NULL)
		printf("The list is empty \n");
	else
	{
		while(L1!=NULL)
		{
			aux=L1;
			L1=L1->next;
			free(aux);
		}
	}
}
int pop (db **L1)
{
	db *aux;
	db *aux2=NULL;
	int ret;
	aux=*L1;

	if(aux==NULL)
		printf("No list Exists \n");
	else
	
	{

		if((aux->next)==NULL)
		{
			ret=aux->x;
			free(aux);
			*L1=NULL;
		}
		else
		{	
			while((aux->next)!=NULL)
			{
				aux2=aux;
				aux=aux->next;
			}
			aux2->next=NULL;
			ret=aux->x;
			free(aux);
			system("clear");
			
		}
	}
	viewList(*L1);
	return ret;
}

int index1(db *L1, int a)
{
	db *aux;
	aux=L1;
	int cont=0, pos=-1;
	
	if(aux==NULL)
		pos=-1;
	else 
	{
		while(aux)
		{
			cont++;
			if(aux==NULL)
				break;
			if((aux->x)==a)
				{
					pos=cont;
					break;
				}
			aux=aux->next;	
		}
	}
	return pos;
}

int count (db *L1, int a)
{
	system("clear");
	db *aux;
	int cont=0;
	aux=L1;
	printf("1 \n");
	if (L1==NULL)
		return cont;
	else
	{
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

db* reverse (db **L1)
{
	
	db *new=NULL;
	while(len(*L1)>0)
	{
		new=append(&new, pop(L1));
	}
	return new;
}


