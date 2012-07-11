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
db* append (db *head, int a);
int len(db *head);
void extend (db *L1, db *L2);
void insert (db *L1, int pos, int val);
void removel (db *L1, int val);
db* pop (db *L1);
int index1 (db *L1, int a);
int count (db *L1, int a);
db* reverse (db *L1);

int main (int argc, char *argv[])
{
	db *head=NULL;
	int phase=1,men,length,a,pos,val,codex,times;
	db *aux;
	system("clear");

	while (phase)
	{
		men=menu();
		switch (men)
		{
			case 1:
				length=len(head);
				viewList(head);
				printf("The Length of the List is %d \n", length);
			break;
			case 2:
				viewList(head);
				printf("What vale do you wish to add? \n");
				scanf("%d", &a);
				head=append(head, a);
			break;
			case 3:
			{
				viewList(head);
				printf("Insert Value to Remove \n");
				scanf("%d", &a);
				removel(head, a);
			}
			break;
			case 4:
			{
				viewList(head);
				printf("Insert Position \n");
				scanf("%d", &pos);
				printf("Insert Value \n");
				scanf("%d", &val);
				system("clear");
				insert(head, pos, val);
			}
			break;
			case 5:
				phase=0;
			break;
			case 6:
			{
				viewList(head);
				aux=pop(head);
			}
			break;
			case 7:
			{
				system("clear");
				viewList(head);
				printf("Input value \n");
				scanf("%d", &val);
				system("clear");
				codex=index1(head,val);
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
				viewList(head);
				printf("Input a value to match in List \n");
				scanf("%d", &val);
				times=count(head,val);
				system("clear");
				viewList(head);
				printf("The number %d was found %d times \n", val,times);
				
			}
			break;
			case 9:
			{
				system("clear");
				viewList(head);
				head=reverse(head);
				system("clear");
				viewList(head);
			}
			break;
		}
		
	}

	return 0;
}

int menu ()
{
	int i;
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

void viewList (db *tmp)
{
	
		while(tmp)
		{
			printf("%d ", tmp->x);
			tmp=tmp->next;
		}		
		printf(" \n");
}

db* append (db *head, int a)
{
	db *aux;
	system("clear");
	aux=head;
	if(aux==NULL)
	{
		head=malloc(sizeof(db));
		head->x=a;
		head->next=NULL;
		viewList(head);
	}
	else
	{
		aux=head;
		while((aux->next)!=NULL)
		{
			aux=aux->next;
		}
	
		aux->next=malloc(sizeof(db));
		aux=aux->next;		
		aux->x=a;
		aux->next=NULL;
		viewList(head);
	}
	return head;
}

int len (db *head)
{
	db *aux;
	int count;
	aux=head;
	while(aux)
	{
		count++;
		aux=aux->next;		
	}	
	return count;
}

void extend (db *L1, db *L2)
{
	db *aux;
	db *newaux;
	
	aux=L1;
	newaux=L2;
		
	while((aux->next)!=NULL)
	{
		aux=aux->next;
	}
	
	aux->next=newaux;
}

void insert (db *L1, int pos, int val)
{
	db *aux;
	db *aux2;
	int cont=1, tmp;
	
	aux=L1;
	if(pos>len(L1))
	{
		printf("The list is shorter than the specified position  \n");
	}
	else
	{	
		while((aux->next)!=NULL && cont!=pos)
		{	
				aux2=aux;
				aux=aux->next;
				cont++;
		}
	}
	
	tmp=aux->x;
	aux2->next=(db*)malloc(sizeof(db));
	aux2=aux2->next;
	aux2->next=aux;
	aux2->x=val;
	viewList(L1);
}

void removel (db *L1, int val)
{
	db *aux;
	db *aux2;
	db *aux3;
	int found=0;
	aux=L1;
	
	//usar funcion pop para buscar en el primer elemento de la lista y sacarlo si existe AQUI!
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
	
	if (found==0)
		printf("The value isn't on the List' \n");	
	system("clear");
	viewList(L1);
}

db* pop (db *L1)
{
	if(L1==NULL)
	{
		printf("No Existe Lista \n");
		return L1;		
	}
	else
	{	
		db *aux;
		db *aux2;
		aux=L1;
		while((aux->next)!=NULL)
		{
			aux2=aux;
			aux=aux->next;
		}
		aux2->next=NULL;
		system("clear");
		viewList(L1);
		return aux;
	}
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
/*
db* reverse (db *L1)
{
	db *new=NULL;
	db *aux;
	db *aux2;
	
	int	flag=0,cmp, i=0;
	
	aux=L1;
	
	if(aux==NULL)
		printf("There is no List to Reverse\n");
	else if (len(aux)==1)
		new=aux;
	else if (len(aux)>1)
	{
		while((len(L1)!=len(new))
		{
			aux=L1
			while ((aux->next)!=NULL && (len(aux)-i)=!0)
			{
				aux=aux->next;
				i++;
			}
			
			
			
		}
	}
			
	}
	return new;
}
		
/*
