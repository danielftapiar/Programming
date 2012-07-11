#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct nodo{
        int valor;
        char color[9];
        struct nodo *sig;
        }nodo;
        
typedef nodo *pila;
typedef nodo *punt;
        
int len(pila);
void append (pila*,int);
void extend (pila*,pila*);
void insert (pila*,int,int);
void remove_ (pila*,int);            
void pop (pila*);
int index_ (pila,int);                 
int count (pila,int);
void reverse (pila*);
void imprimirarchivo(FILE *,int,int);  
void imprimirarchivo2(FILE*,pila);     

void append2(pila*,int);  // Función utilizada en la pila nueva idéntica a append pero sin la asignación de color.

void regla_uno(FILE*,pila*,int);      
int regla_dos(pila,int,int);            

int main(){
  int i,numpila,numcolor,z,ant,sig,pos_nodo,num,y=0;
  long int n;
    punt aux;                                         
    FILE *f;                                          
    f=fopen("Jugadas.txt","w+");                      
    
    do{
    printf("Ingrese numero de columnas: ");
    scanf("%d",&n);
    if(n<3)
    printf("Cantidad no valida. Ingrese nuevamente.\n");
}while(n<3);

    pila arreglo[n];                                 
    pila posicion=NULL;                             
    
    for(i=0;i<n;i++)
    arreglo[i]=NULL;                 
                     
    srand(time(NULL));                              
      
   do{
       numpila=rand()%n;                            
       numcolor=rand()%4;                            
       append(&arreglo[numpila],numcolor);
       imprimirarchivo(f,numcolor,numpila);
       
       ant=numpila-1;
       sig=numpila+1;
       pos_nodo=len(arreglo[numpila]);              
       
       // R E G L A  1
       
       if(pos_nodo>2)
       regla_uno(f,&arreglo[numpila],numpila);
       
       // R E G L A  2
       
       while(ant>=0){
                     z=regla_dos(arreglo[ant],pos_nodo,numcolor); 
                     
                     if(z==1)
                     append2(&posicion,ant);  
                                 
                     if(z==0)
                     break; 
                                                   
                     ant=ant-1;
                     }
                     
       
       while(sig<=n-1){
                     z=regla_dos(arreglo[sig],pos_nodo,numcolor);
                     
                     if(z==1)
                     append2(&posicion,sig);
                     
                     if(z==0)
                     break;
                     
                     sig=sig+1;
                     }
                     
   
       if(len(posicion)>=2){
                            if(len(arreglo[numpila])==1)
                            arreglo[numpila]=NULL;  // Si el largo de la pila es 1, se vacía la pila completa.
                            
                            else pop(&arreglo[numpila]);                        // sino se borra el nodo recién agregado.
                            fprintf(f,"--REGLA 2 EN PILAS %d,",numpila+1);      
                            aux=posicion;                                      
                            while(aux){
                                  num=len(arreglo[aux->valor])-pos_nodo+1;                                       // Num es la cantidad de veces que se borran nodos en las otras pilas. Esto es la diferencia entre el largo de la pila adyacente y la posicion del nodo hasta el que se elimina + 1
                                 
                                  if(len(arreglo[aux->valor])==num)
                                  arreglo[aux->valor]=NULL; 
                                  
                                  else{
                                       while(y<num){
                                            pop(&arreglo[aux->valor]);          
                                            y++;}
                                       }
                                  y=0;
                                  aux=aux->sig;
                                  }
                                         
                            aux=posicion;                                       
                                 while(aux){
                                       fprintf(f,"%d,",aux->valor+1);           
                                       aux=aux->sig;
                                       }
                                       
                            fprintf(f,"--\n");
                            }
        posicion=NULL;              // Posicion se debe hacer null cada vez que se agrega un nodo nuevo. De no hacerse, puede que la pila ya tenga ciertos valores y se considere que igual se cumple la regla. 
                              
       }while(len(arreglo[numpila])<10);                  // Si el largo de la pila donde se agregó el último nodo es 10, el juego termina.
       
       fprintf(f,"--JUEGO TERMINADO--\n");
       
       
       for(i=0;i<n;i++){
        fprintf(f,"Pila %d [%d]: ",i+1,len(arreglo[i]));
        imprimirarchivo2(f,arreglo[i]);
        fprintf(f,"\n");}

    fclose(f);
    return 0;
} 
//fin main

// F U N C I O N E S

int len(pila p){
    punt aux;                                              
    int contador=0;                                        
    aux=p;                                                 
    while(aux){
         contador++;                                       
         aux=aux->sig;}
    return contador;                                       
}


void append(pila *p,int n){
     punt aux,nuevo;                                    
     nuevo=(punt)malloc(sizeof(nodo));                     
     
     switch(n){                                            
                     case 0:
                          strcpy(nuevo->color,"Rojo");
                          break;
                     case 1:
                          strcpy(nuevo->color,"Azul");
                          break;
                     case 2:
                          strcpy(nuevo->color,"Verde");
                          break;
                     case 3:
                          strcpy(nuevo->color,"Amarillo");
                          break;
                     default:
                             break;
                     }
                     
     nuevo->valor=n;                                      // El valor del nodo nuevo es el número del color
     aux=*p;                                              // Se iguala el puntero auxiliar a la pila.
     
     // Si es el primer valor de la pila, el valor sig del nodo nuevo es null y la cabecera del puntero ahora es el nodo nuevo.
     if(!aux){
        nuevo->sig=NULL;                                  
        *p=nuevo;}
        
     //Si no es el primer nodo, se hace un while hasta el final, y se determina que el sig del nodo nuevo es null, y que el último nodo apunte al nuevo.
     else{
          while(aux->sig){
                aux=aux->sig;}
           nuevo->sig=NULL;
           aux->sig=nuevo;
           }
}

int jugada=1;



void imprimirarchivo(FILE *f, int n,int b){
       
       switch(n){
                     case 0:
                          fprintf(f,"Jugada %d: Cubo Rojo - Pila %d\n",jugada,b+1);
                          break;
                     case 1:
                          fprintf(f,"Jugada %d: Cubo Azul - Pila %d\n",jugada,b+1);
                          break;
                     case 2:
                          fprintf(f,"Jugada %d: Cubo Verde - Pila %d\n",jugada,b+1);
                          break;
                     case 3:
                          fprintf(f,"Jugada %d: Cubo Amarillo - Pila %d\n",jugada,b+1);
                          break;
                     }
      jugada++;
}


void imprimirarchivo2(FILE *f, pila l){
     punt aux;                                         
     aux=l;                                            
     while(aux){
        fprintf(f,"%s ",aux->color);                  
        aux=aux->sig;
        }
}

void extend(pila *p,pila *c){
     punt aux,aux2;
     aux=*p;
     aux2=*c;
     while(aux->sig){
           aux=aux->sig;}
     aux->sig=aux2;
}

void insert(pila *p, int i, int n){
     punt aux,nuevo,ant;
     nuevo=(punt)malloc(sizeof(nodo));
     nuevo->valor=n;
     aux=*p;
     int contador=1;
     while(contador!=i){
          contador++;
          ant=aux;
          aux=aux->sig;}
     if(contador==1){
                     nuevo->sig=aux;
                     *p=nuevo;}
     else{
          nuevo->sig=ant->sig;
          ant->sig=nuevo;}
}

void remove_ (pila *p, int n){
     punt aux,ant;
     aux=*p;
     while(aux->valor!=n){
           ant=aux;
           aux=aux->sig;}
     ant->sig=aux->sig;
     free(aux);
}

void pop(pila *p){
     punt aux,ant;
     aux=*p;
     if(aux->sig){     
         while(aux->sig){
              ant=aux;
              aux=aux->sig;}
          ant->sig=NULL;
          free(aux);}
     else aux=NULL;
     }

int index_(pila p, int n){
    punt aux;
    aux=p;
    int contador=1;
    while(aux->valor!=n){
          contador++;
          aux=aux->sig;
          if(!aux)return -1;}
    return contador;
}

int count(pila p, int n){
    punt aux;
    aux=p;
    int contador=0;
    while(aux){
          if(aux->valor==n)contador++;
          aux=aux->sig;}
    return contador;
}                   

void reverse(pila *p){
     punt ant,aux;
     pila pinv;
     pinv=NULL;
     aux=*p;
     while(aux){   
           ant=aux;
           insert(&pinv,1,(ant->valor));
           aux=aux->sig;}
     
     *p=pinv;
}

void regla_uno(FILE *f,pila *a,int n){
     int c=0;
     punt aux1,aux2,aux3;
     aux1=*a;
     while(aux1->sig){
                aux3=aux2;
                aux2=aux1;
                aux1=aux1->sig;}
     if(aux1->valor==aux2->valor && aux1->valor==aux3->valor){
        if(len(*a)==3){
                       *a=NULL;
                       fprintf(f,"--REGLA 1 EN PILA %d--\n",n+1);
                       return;}
        while(c<3){
                   pop(&(*a));
                   c++;}
        fprintf(f,"--REGLA 1 EN PILA %d--\n",n+1);}
     }
     
int regla_dos(pila a,int n,int l){
     punt aux;
     aux=a;
     if(!aux)return 0;
     int contador=1;
     while(contador!=n){
          aux=aux->sig;
          if(!aux)return 0;
          contador++;
          }
     if (aux->valor==l) return 1;
     return 0;
     }

void append2(pila *p,int n){
     punt aux,nuevo;
     nuevo=(punt)malloc(sizeof(nodo));
     nuevo->valor=n;
     aux=*p;
     if(!aux){
        nuevo->sig=NULL;
        *p=nuevo;}
     else{
          while(aux->sig){
                aux=aux->sig;}
           nuevo->sig=NULL;
           aux->sig=nuevo;
           }
     
}
