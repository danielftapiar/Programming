#include <stdio.h>
#include <stdlib.h>

typedef struct nodo{
        int info,
        struct nodo *sig;
        }tNodo

typedef tNodo *pNodo;
typedef tNodo *tLista;
typedef tNodo tElemento;
/* defino estructura*/

int len(tLista L){
    int cont=0;
    pNodo *q=L;
    while(q!=NULL){
         cont+=1;
         q=q->sig;
         }
    return cont;
} /* retorna la longitud de la lista*/
                   
                   
