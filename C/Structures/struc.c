#include <stdio.h>

struct database {

	int a;
	int b;
	float c;

};
void viewList (db *tmp);


int main ()
{
	struct database example1;
	struct database *ptr;
	example1.a = 33;
	example1.b=22;
	example1.c=123.32;
	ptr = &example1;
	printf("%d %d \n", ptr->a,ptr->b, ptr->c);
	return 0;
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
