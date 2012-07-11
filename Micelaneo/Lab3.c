#include<stdio.h>
#include<stdlib.h>

#define ID 9
#define SALMAX 6400000
long int saldo_total_banco = 0; //Variable global para funcion SaldoBanco(tABB arbol):
long int c;//Variable global

typedef long int tElemento;//Definicion de tElemento

/*------------------------*/
//Estructura Arbol
/*------------------------*/

typedef struct Arbol{
long int rut;//Rut Cliente
int cantidad_cuentas;//Cantidad de cuentas disponibles
struct Arbol *izq;//Puntero a Hijo Izquierdo
struct Arbol *der;//Puntero a Hijo Derecho
struct listaclientes *cliente;//Puntero a Estructura de Cuentas
} tAB;

typedef tAB *tArbol;
typedef tAB *pNodo;

/*------------------------*/
//Estructura Cuentas
/*------------------------*/

typedef struct listaclientes{
int id_cuenta;//Identificador cuenta
long int saldo;//Saldo en la cuenta
struct listaclientes *sig;//Puntero hacia siguiente estructura
}cliente;

typedef cliente *tPosicion;
typedef cliente *tLista;

/*------------------------*/
//Funciones Declaradas
/*------------------------*/

void Crear_Arbol(tArbol*A);
void Crear_nodo(pNodo *N,tElemento x);
void Ingreso_Binario(tArbol *A,tElemento x);
int Inorden_lista(tArbol *A);
long int Inorden_Saldo_Banco(tArbol *A);
int esVacio(tArbol *A);
pNodo BuscarNodo(tArbol *A, tElemento aBuscar);
int Agregar_Cuenta(tArbol *A,tElemento rut, int n_id_cuenta, long int n_saldo);
int ModificarSaldo(tArbol *A , tElemento rut, int n_id_cuenta, tElemento aCambiar);
int EliminarCuenta(tArbol *A, tElemento rut, int n_id_cuenta);
long int SaldoCliente(tArbol *A, tElemento rut);
int MostrarClientes(tArbol *A);
int Cuenta_rutmenor(tArbol *A);
int Retirosaldos(tArbol *A);
void escribe_archivos(FILE *salida, tArbol *A);
void Estado(FILE *);
int Saldo_rutmayor(tArbol *A);
/*------------------------*/
//Programa main()
/*------------------------*/
int main(){

//TODO LO QUE ESTA EN MAIN ESTA SOLAMENTE PARA PROBAR LAS FUNCIONES

tArbol A1;//se crea un arbol
Crear_Arbol(&A1);
//se crean 5 cuentas diferentes y son ingresadas
//Agregar_cuenta(Arbol,Rut,ID,Saldo)

int cantidad_clientes,cantidad_de_cuentas,id_cuenta,y,x;
long int rut,saldo;
pNodo nodo;


FILE *archivo, *output_1, *output_2;
archivo = fopen("Cuentas.txt","r");
output_1 = fopen("estado 1.txt","w");
fscanf(archivo,"%d",&cantidad_clientes);
fprintf(archivo,"\n");


for(x=0;x<cantidad_clientes;x++){

fscanf(archivo,"%ld",&rut);
fscanf(archivo,"%d",&cantidad_de_cuentas);
Ingreso_Binario(&A1,rut);
nodo = BuscarNodo(&A1,rut);
nodo->cantidad_cuentas = cantidad_de_cuentas;
fprintf(archivo,"\n");
for(y=0;y<cantidad_de_cuentas;y++){
fscanf(archivo,"%d",&id_cuenta);
fscanf(archivo,"%ld",&saldo);
Agregar_Cuenta(&A1,rut,id_cuenta,saldo);

 }
}

fclose(archivo);
Estado(output_1);
escribe_archivos(output_1, &A1);
fprintf(output_1,"--------------------------------------------------------\n");
fprintf(output_1 ,"Saldo total del Banco\t\t\t%ld", Inorden_Saldo_Banco(&A1));
fprintf(output_1,"\n");

MostrarClientes(&A1);
printf("El saldo total del banco es [%ld]\n\n",Inorden_Saldo_Banco(&A1));

fclose(output_1);



Retirosaldos(&A1);
printf("Mitad de todas las cuentas");
MostrarClientes(&A1);
printf("El saldo total del banco es [%ld]\n\n",Inorden_Saldo_Banco(&A1));

Cuenta_rutmenor(&A1);
printf("Elimina cuenta");
MostrarClientes(&A1);
printf("El saldo total del banco es [%ld]\n\n",Inorden_Saldo_Banco(&A1));
Saldo_rutmayor(&A1);
printf("Nuevo saldo rut mayor");
MostrarClientes(&A1);
printf("El saldo total del banco es [%ld]\n\n",Inorden_Saldo_Banco(&A1));
escribe_archivos(output_1, &A1); 


output_2 = fopen("estado 2.txt","w");
Estado(output_2);
escribe_archivos(output_2, &A1);
fprintf(output_2,"--------------------------------------------------------\n");
fprintf(output_2 ,"Saldo total del Banco\t\t\t%ld", Inorden_Saldo_Banco(&(A1)));
fprintf(output_2,"\n");


fclose(output_2);
free(A1);
return 0;

}
/*----------------------------------------------------*/
//Lista de Funciones TAD ÁRBOL DE BÚSQUEDA BINARIA
/*----------------------------------------------------*/

void Crear_Arbol(tArbol*A){
 (*A) = NULL;
}

void Crear_nodo(pNodo *N,tElemento x){
  (*N)=(tArbol)malloc(sizeof(tAB));
  (*N)->izq = NULL;
  (*N)->der = NULL;
  (*N)->rut = x;
}

int esVacio(tArbol *A){
    if((*A)==NULL){
       return 1;
    }else{
       return 0;
    }
}

pNodo BuscarNodo(tArbol *A, tElemento aBuscar){

    if((*A) == NULL)
        return NULL;

    if((*A)->rut == aBuscar)
        return (*A);
    if((*A)->rut < aBuscar)
            BuscarNodo(&((*A)->der),aBuscar);
   else
    if((*A)->rut > aBuscar)
            BuscarNodo(&((*A)->izq),aBuscar);

}

void Ingreso_Binario(tArbol *A,tElemento x){
 pNodo aux;
 aux = *A;
 if(esVacio(A)){
     pNodo nuevo ;
     Crear_nodo(&nuevo,x);
     (*A) = nuevo;

 }else{
    if(x  > ((*A)->rut)){
       if((*A)->der == NULL)
       {
          pNodo nuevo;
          Crear_nodo(&nuevo,x);
          (*A)->der = nuevo;

       }else{
          aux = aux->der;
       Ingreso_Binario(&aux,x);
       }
    }else{

       if(x < ((*A)->rut)){
       if((*A)->izq == NULL)
       {
           pNodo nuevo;
           Crear_nodo(&nuevo,x);
           (*A)->izq = nuevo;
       }else{
          aux = aux->izq;
       Ingreso_Binario(&aux,x);
     }
    }
   }
 }
}


int Inorden_lista(tArbol *A){
    if((*A) != NULL){
        Inorden_lista(&((*A)->izq));
        printf("[%ld]",((*A)->rut));
        long int c = SaldoCliente(&(*A),((*A)->rut));
        printf("$%ld \n",c);
        Inorden_lista(&((*A)->der));
}
return c;
}

int Saldo_rutmayor(tArbol *A){
   long int cuenta;
   tLista p = NULL;
    if( (*A) != NULL){
	
        Saldo_rutmayor(&((*A)->der));
		while (p != NULL){
		p = (*A)->cliente;
		cuenta = p->id_cuenta;
		p = p->sig;	
		}
     Agregar_Cuenta(&(*A),(*A)->rut ,ID,SALMAX);
 }
	
 return 0;
 }
		

int Retirosaldos(tArbol *A){
   
    if((*A) != NULL){
        Retirosaldos(&((*A)->izq));
        long int cuenta,saldo;
        tLista p;
		p = (*A)->cliente;
		
		while (p != NULL){
			cuenta = p->id_cuenta;
			saldo = p->saldo/2;
			ModificarSaldo(&(*A),(*A)->rut,cuenta,saldo);
			p = p->sig;
		}
		
  
        Retirosaldos(&((*A)->der));
        
	}
return 0;
}


int Cuenta_rutmenor(tArbol *A){
    int flag = 1;
    if(((*A) != NULL) && flag == 1){
        Cuenta_rutmenor(&((*A)->izq));
        long int cuenta;
        tLista p;
		flag = 0;
		p = (*A)->cliente;
		cuenta = p->id_cuenta;
        EliminarCuenta(&(*A),(*A)->rut,cuenta);
        (*A)->cantidad_cuentas = cuenta;
        return 0;
	}
return 0;
}



long int Inorden_Saldo_Banco(tArbol *A){
    if((*A) != NULL){
        Inorden_Saldo_Banco(&((*A)->izq));
        c = SaldoCliente(&(*A),((*A)->rut));
        saldo_total_banco = saldo_total_banco + c;
        Inorden_Saldo_Banco(&((*A)->der));
}
return saldo_total_banco;
}

/*---------------------------------*/
//FUNCIONES PARA LAB 3
/*---------------------------------*/

//Agregar una cuenta dentro de un cliente
int Agregar_Cuenta(tArbol *A,tElemento rut, int n_id_cuenta, long int n_saldo){
    pNodo n_cliente;//Crea un Nodo cliente
    tLista p; //Crea un puntero tLista
    n_cliente = BuscarNodo(&(*A),rut);//Busca si existe un cliente con el mismo rut ingresado.
     if( n_cliente == NULL){ //En el caso de que no encuentre ningun cliente parecido
         Ingreso_Binario(&(*A),rut); //El cliente es creado e ingresado a la lista
         n_cliente = BuscarNodo(&(*A),rut);//Se identifica el nodo ingresado
         n_cliente->cliente =(tLista)malloc(sizeof(cliente));//Se reserva memoria para la lista de cuentas
         n_cliente->cliente->id_cuenta = n_id_cuenta;//Se le agrega la identifiación de la cuenta
         n_cliente->cliente->saldo = n_saldo;//Se le agrega el saldo de la cuenta
         n_cliente->cliente->sig = NULL;//puntero del nodo es NULL

//De lo contrario, si el cliente si existe
     }else{
          p = (n_cliente->cliente);//Se iguala p a el header de la Lista

          if((n_cliente->cliente) == NULL){
          (n_cliente->cliente)=(tLista)malloc(sizeof(cliente));
          (n_cliente->cliente)->id_cuenta = n_id_cuenta;
          (n_cliente->cliente)->saldo = n_saldo;
          (n_cliente->cliente)->sig = NULL;
             return 0;
          }
         else{
          tLista q =(tLista)malloc(sizeof(cliente));//se crea nodo q, que será la nueva cuenta
          q->id_cuenta = n_id_cuenta;
          q->saldo = n_saldo;
          q->sig = NULL;

         while( p->sig !=NULL && p->id_cuenta != n_id_cuenta)//Se llega al final de la lista para insertar la nueva cuenta
                     p = p->sig;
                 if(p->id_cuenta == n_id_cuenta){ //Se verifica que la cuenta no exista
                      printf("[LA CUENTA YA EXISTE]\n");
                      return -1;//De lo contrario el programa termina
         }else{
         p->sig = q; //el nodo q se ingresa al final
         q->sig = NULL; // el puntero de q apunta no apunta, es NULL
          }
         }
         }
return 0; //FIN DE LA FUNCION
}

//Modificar el saldo de una cuenta determinada de un cliente
int ModificarSaldo(tArbol *A , tElemento rut, int n_id_cuenta, tElemento aCambiar) {

  pNodo n_cliente; //Se crea nodo n_cliente
  n_cliente = BuscarNodo(&(*A),rut);//Se verifica si existe un cliente con el rut ingresado

  if( n_cliente == NULL){
    printf("[El Cliente No Existe]\n");
    return -1;//De lo contrario finaliza el programa
  }else{
     tLista p; //se crea nodo tLista p
     p = n_cliente->cliente;
     while( p != NULL && p->id_cuenta !=n_id_cuenta) //Se busca la cuenta ingresada en la función
           p = p->sig;
        if(p == NULL){
           printf("[La cuenta no existe]\n");
           return -1; //Si no encuentra la cuenta, finaliza la función
        }else{
           if(p->id_cuenta == n_id_cuenta)//Si la id ingresada coincide con la id encontrada
           {
               //printf("El saldo anterior era $%ld \n",p->saldo);
               p->saldo = aCambiar;
               //printf("El nuevo saldo ahora es $%ld \n",p->saldo);//El saldo es modificado
           }

        }
  }
  return 0; //FINALIZA EL PROGRAMA
}


//Elimina una cuenta determinada de un cliente
int EliminarCuenta(tArbol *A, tElemento rut, int n_id_cuenta){

  pNodo n_cliente;
  n_cliente = BuscarNodo(&(*A),rut);
  if( n_cliente == NULL){
    printf("[El Cliente No Existe]\n");
    return -1;
}else{
    tLista p;
    p = n_cliente->cliente;
    if(p->id_cuenta == n_id_cuenta)
    {
        tLista q;
        q = (n_cliente->cliente);
        p = q->sig;
        free(q);
        n_cliente->cliente = p;
        return 0;
    }else{
    while( p != NULL && p->id_cuenta !=n_id_cuenta)
        p = p->sig;
        if(p == NULL){
           printf("[La cuenta no existe]\n");
           return -1;
        }else{
             if(p->id_cuenta == n_id_cuenta){
             tLista q;
             q = n_cliente->cliente;
             while( q->sig != p)
                q = q->sig;
                if(q->sig == p){
                   q->sig = p->sig;
                   free(p);
                   return 0;
                }
              }
             }
            }
}return 0;
}

//Muestra el saldo total de todas las cuentas de un cliente
long int SaldoCliente(tArbol *A, tElemento rut){

  long int saldo_total = 0;
  pNodo n_cliente;
  n_cliente = BuscarNodo(&(*A),rut);
  if( n_cliente == NULL){
    printf("[El Cliente No Existe]\n");
    return -1;
  }else{
      tLista p;
      p = n_cliente->cliente;
      while (p != NULL){
      saldo_total = saldo_total + (p->saldo);
      p = p->sig;
      }
  return saldo_total;
  }

}





//Muestra el saldo total depositado en el banco por todos los clientes


int MostrarClientes(tArbol *A){
    printf("-Lista de Clientes-\n\n");
    Inorden_lista(&(*A));
    return 0;
}
void Estado(FILE *salida){
     

fprintf(salida,"Situacion del Banco\n");
fprintf(salida,"--------------------------------------------------------\n");
fprintf(salida,"Clientes\n");
fprintf(salida,"--------------------------------------------------------\n");
fprintf(salida,"RUT\t\tN Cuentas\t\tSaldo\n");
fprintf(salida,"--------------------------------------------------------\n");

}

void escribe_archivos(FILE *salida, tArbol *A){


    if((*A) != NULL){
        escribe_archivos(salida,&((*A)->izq));  
        fprintf(salida, "[%ld]\t\t[%d]\t\t\t[%ld]\n",((*A)->rut), ((*A)->cantidad_cuentas), SaldoCliente(&(*A),(*A)->rut));
        fprintf(salida, "\n");
        escribe_archivos(salida,&((*A)->der));

	}

}
