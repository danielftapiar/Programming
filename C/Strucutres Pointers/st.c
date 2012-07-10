#include <stdio.h>

struct database {
	int age;
	char initial;
};

typedef struct database db;

void swap (db *tmp1,db *tmp2);

int main (int argc, char *argv[])
{
	db a;
	db b;
	db *ptr1;
	db *ptr2;	
	
	a.age=30;
	a.initial='d';
	b.age=33;
	b.initial='t';
	
	printf("Edad #1 :%d, Inicial #1: %c \n", a.age, a.initial);
	printf("Edad #2 :%d, Inicial #2: %c \n", b.age, b.initial);
	printf("-----------------------------------------\n");
	ptr1=&a;
	ptr2=&b;
	
	ptr1->age=55;
	ptr2->age=6210;
	
	printf("Edad #1 :%d, Inicial #1: %c \n", a.age, a.initial);
	printf("Edad #2 :%d, Inicial #2: %c \n", b.age, b.initial);
	printf("-----------------------------------------\n");
	
	swap(ptr1, ptr2);
	
	printf("Edad #1 :%d, Inicial #1: %c \n", a.age, a.initial);
	printf("Edad #2 :%d, Inicial #2: %c \n", b.age, b.initial);
	printf("-----------------------------------------\n");
	
	return 0;
}

void swap (db *tmp1, db *tmp2)
{
	db *aux;
	aux=tmp1;
	tmp1=tmp2;
	tmp2=aux;
	
	tmp2->age=6210;
	tmp1->age=55;	
			
}
