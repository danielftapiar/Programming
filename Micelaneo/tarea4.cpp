#include <iostream>
#include <string>

typedef struct AB{
   char letra;
   int frecuencia;
   bool bit;
   struct AB* hijoDerecho;
   struct AB* hijoIzquierdo;
}tValor;

typedef tValor *tABB;

//Si el árbol está vacío retorna 1, si no, retorna cero
bool ABVacio(tABB *arbol){ 
    if (arbol) 
    return false;
    else 
    return true;
     }         
     
//Inserta un nodo en el árbol binario
void Insertar(tABB *arbol, tValor *valor){
 tABB aux;
 aux=*arbol;
 if(!(*arbol)) {
      *arbol = valor;
   }
 else{
   if((valor->frecuencia)<(aux->frecuencia))
    Insertar(&aux->hijoIzquierdo, valor);
   if((valor->frecuencia)>(aux->frecuencia))
     Insertar(&aux->hijoDerecho, valor);
   }
}

//Recorre el árbol binario en InOrden
void InOrden(tABB *arbol,FILE *arch1){
   tABB aux3;
   aux3=*arbol;
   if(arbol!=NULL){          //verifica que el árbol no esté vacío
   InOrden(&aux3->hijoIzquierdo,arch1);   //recorre en InOrden por la izquierda del árbol
   fprintf(arch1,"%c", aux3->letra);      
   fprintf(arch1,"%d", aux3->frecuencia);
   InOrden(&aux3->hijoDerecho,arch1);  //recorre en InOrden por la derecha del árbol
 }
}

//Recorre el árbol binario en PreOrden
void PreOrden(tABB *arbol, FILE *arch1){
   tABB aux4;
   aux4=*arbol;
   if(arbol!=NULL){          //verifica que el árbol no esté vacío
   fprintf(arch1,"%c", aux4->letra);
   fprintf(arch1,"%d", aux4->frecuencia);
   PreOrden(&aux4->hijoIzquierdo,arch1);   //recorre en PreOrden por la izquierda del árbol
   PreOrden(&aux4->hijoDerecho,arch1);  //recorre en PreOrden por la derecha del árbol
 }
}     
     
//Elimina una hoja del árbol binario

/*void Eliminar(tABB *arbol, char letra){
   tABB aux2;
   aux2=*arbol;
   if(arbol!=NULL){          //verifica que el árbol no esté vacío
   InOrden(aux2->hijoIzquierdo); //recorre en InOrden por la izquierda del árbol
   if(strcmp(aux->letra,letra)==1) //si recorriendo el árbol encuentra la letra, la elimina
   Eliminar(aux2,letra);
   InOrden(aux->hijoDerecho); //recorre en InOrden por la derecha del árbol
 }
} */

//Vacía el arbol binario    
int Vaciar (tABB *arbol){
    return (arbol==NULL);
}
    
int main (){

  tABB *arbol;
  FILE *arch1;
    arch1=fopen("Arbol.txt","w");
    fprintf(arch1,"Recorrido InOrden\n"); 
    InOrden(arbol,arch1);
    fprintf(arch1,"\n");
    fprintf(arch1,"Recorrido PreOrden\n");
    PreOrden(arbol,arch1);
    fclose(arch1);

    return 0;
}
    


  
