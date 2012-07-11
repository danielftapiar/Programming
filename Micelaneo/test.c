#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//TDA Lista Simplemente Enlazada
typedef struct tNodoLista {
	int id;
	int saldo;
	
	struct tNodoLista * sig;
} tNodoLista;

typedef tNodoLista * pLista; //puntero a una lista
typedef pLista * tLista; //puntero al puntero, para llamarlo por referencia

//interfaz Lista
int listaVacia(tLista lista){//indica si la lista esta vacia (1) o no (0).
	if(*lista) return 0;
	else return 1;
}

void agregarNodo(tLista lista, int id, int saldo){ //agrega un nodo a una lista, de no existir la lista, la crea.
	pLista temp = (pLista) malloc(sizeof(tNodoLista));
	temp->id = id;
	temp->saldo = saldo;
	temp->sig = NULL;
	
	if(!listaVacia(lista)) (*lista)->sig = temp;
	else *lista = temp;
}

void vaciarLista(tLista lista){//libera la memoria de la lista.
	pLista point = *lista;
	pLista temp;
	while(point != NULL){
		temp = point;
		point = point->sig;
		free(temp);
	}
}

int buscarCuenta(tLista lista, int id){//Busca una cuenta en la lista enlazada, si no la encuentra desvuelve -1.
	pLista point = *lista;
	while(point != NULL){
		if(point->id != id) point = point->sig;
		else {
			return point->saldo;
		}
	}
	return -1;
}

//TDA Arbol de Búsqueda Binaria
typedef struct tNodo {
	int rut;
	pLista cuentas;
	
	struct tNodo * izq;
	struct tNodo * der;
} tNodo;

typedef tNodo * pNodo; //puntero a un nodo del arbol.
typedef pNodo * tABB; //puntero al puntero, para llamarlo por referencia.

//interfaz Arbol
void crearArbol(tABB arbol){//crea espacio para armar un arbol en el puntero arbol.
	*arbol = NULL;
}

int esVacio(tABB arbol){ //indica si el arbol esta vacio (1) o no (0).
	if(*arbol) return 0;
	else return 1;
}

void insertarNodo(tABB arbol, pNodo nodo){ //inserta un nodo nuevo en el arbol.
	if(esVacio(arbol)) *arbol = nodo;
	else if((*arbol)->rut > nodo->rut) insertarNodo(&(*arbol)->izq, nodo);
	else if((*arbol)->rut < nodo->rut) insertarNodo(&(*arbol)->der, nodo);
} 

pNodo buscarNodo(tABB arbol, int aBuscar){ //busca un nodo en el arbol con respecto al rut aBuscar.
	pNodo puntero = *arbol;
	while(puntero != NULL){
		if(puntero->rut == aBuscar) return puntero;
		else if(puntero->rut > aBuscar) puntero = puntero->izq;
		else if(puntero->rut < aBuscar) puntero = puntero->der;
	}
	return NULL;
}

//funciones Arbol
/* se verifica si existe el cliente, de no existir, se crea un nodo nuevo y luego se inserta con insertarNodo. Si existe, se verifica que no exista la cuenta, de existir (mismo identificador), se retorna -1. Si no existe, la cuenta se agrega a las cuentas del cliente con agregarNodo. Se crea un nodo nuevo y luego se inserta ese nodo con insertarNodo.
*/
int agregarCuenta(tABB arbol, int rut, int id_cuenta, int saldo){
	pNodo busqueda = buscarNodo(arbol, rut);
	if(busqueda != NULL){
		if(buscarCuenta(&(busqueda->cuentas), id_cuenta) < 0){
			agregarNodo(&(busqueda->cuentas), id_cuenta, saldo);
		} else return -1;
	} else {
		pNodo temp = (pNodo) malloc(sizeof(tNodo));
		temp->rut = rut;
		temp->cuentas = NULL;
		temp->izq = NULL;
		temp->der = NULL;
		agregarNodo(&(temp->cuentas), id_cuenta, saldo);
		insertarNodo(arbol, temp);
	}
	return 0;
}

/*se modifica el saldo de la cuenta id_cuenta del cliente con rut igual al entregado. Se valida que el cliente y la cuenta existan, de no ser
asi, se debe retornar -1.
*/
int modificarCuenta(tABB arbol, int rut, int id_cuenta, int aCambiar)
{
	pNodo buscar;
	buscar=buscarNodo(arbol,rut);
	int flag=0;
	pLista BuscarID=NULL;
	if(buscar==NULL)
		return -1;
	else
	{
		BuscarID=buscar->cuentas;
		while(BuscarID->sig!=NULL)
		{
			if(BuscarID->id==id_cuenta)
			{
				BuscarID->saldo=aCambiar;
				flag=1;
			}
		}
		if (flag==0)
			return -1;
	}
	return 0;
}

/* se elimina la cuenta de id “id_cuenta” en el cliente. Se verifica que exista tanto el cliente como la cuenta, de no existir alguno de los 2,
se retorna -1.
*/
int eliminarCuenta(tABB arbol, int rut, int id_cuenta){return 0;}

/* se retorna la suma del saldo de todas las cuentas del cliente. Si el cliente no existe se debe retornar -1.
*/
int saldoCliente(tABB arbol, int rut){
	
	pLista tmp;
	int suma;
	pNodo buscarRut;
	buscarRut=buscarNodo(arbol,rut);
	if (buscarRut==NULL)
		return -1;
	else
	{
		while(listaVacia(&tmp)!=1)
			suma=suma+(tmp->saldo);
	}
	return suma;
}

/* muestra todos los clientes del banco ordenados por rut (inorden) y el saldo total
(suma de los saldos de todas sus cuentas) asociado a cada uno.
*/
void mostrarClientes(FILE * archivo, tABB arbol)
{
	pLista tmp;
	if(arbol!=NULL)
	{
		mostrarClientes(archivo, &((*arbol)->izq));
		printf("%d \n", ((*arbol)->rut));
		tmp=(*arbol)->cuentas;
		while(listaVacia(&tmp)!=1)
			printf("ID:%d  Saldo:%d \n", tmp->id,tmp->saldo);
		mostrarClientes(archivo, &((*arbol)->der));
			
	}
}
/* retorna la suma de los saldos de todas las cuentas de todos los clientes del
banco. En caso de no existir clientes, retorna 0.
*/

int saldoBanco(tABB arbol){
	int suma = 0;
	int intento = 0;
	pNodo temp = *arbol;
	if(!esVacio(&temp)){
		suma += saldoBanco(&(temp->izq));
		intento = saldoCliente(&temp, temp->rut);
		if(intento > 0) suma += intento;
		suma += saldoBanco(&(temp->izq));
	}
	return suma;
}


//funciones Programa

/* lee los clientes desde el archivo de texto y los va agregando usando agregarCuenta() */
int leerClientes(FILE * archivo, tABB arbol){
	int tempRut, tempNumCuentas, tempIdCuenta, tempSaldo, clientes, i, j;
	pNodo temp = *arbol;
	
	if(archivo != NULL){
		fscanf(archivo, "%d", &clientes);
		for(i = 0; i < clientes; i++){
			fscanf(archivo, "%d %d", &tempRut, &tempNumCuentas);
			for(j = 0; j < tempNumCuentas; j++){
				fscanf(archivo, "%d %d", &tempIdCuenta, &tempSaldo);
				//hacer que se añadan al nodo
				agregarCuenta(&temp, tempRut, tempIdCuenta, tempSaldo);
			} 
		}
	}
	return clientes;
}

/* escribe el archivo de estado del banco */
void escribirEstado(FILE * archivo, tABB arbol){	
}

/* funcion que aplica las condiciones del estado 2, no las imprime */
void aplicarEstadoDos(tABB arbol){
	
}

int main(int argc, char * argv[]){
	FILE *archivoEntrada, *estadoUno, *estadoDos;
	int cantClientes = 0;
	pNodo arbol;
	archivoEntrada = fopen("Clientes.txt", "r+");
	if(archivoEntrada != NULL){
		crearArbol(&arbol);
		cantClientes = leerClientes(archivoEntrada, &arbol);
	} else {
		printf("\nNo se encontró el archivo, saliendo...\n");
		return (EXIT_FAILURE);
	}
	
	printf("%d", saldoBanco(&arbol));
	
	estadoUno = fopen("Estado1.txt", "w+");
	escribirEstado(estadoUno, &arbol);
	aplicarEstadoDos(&arbol);
	estadoDos = fopen("Estado2.txt", "w+");
	escribirEstado(estadoDos, &arbol);
	
	return (EXIT_SUCCESS);
}


