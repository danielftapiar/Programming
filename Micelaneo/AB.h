#ifndef AB_H
#define AB_H
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

class AB
{
    public:
        class Nodo
        {
            public:
                Nodo(char letra, int frecuencia, bool bit, Nodo *izq=NULL, Nodo *der=NULL) : letra(letra), frecuencia(frecuencia), bit(bit), izq(izq), der(der) {} //Constructor.
                char letra;
                int frecuencia;
                bool bit;
                Nodo *izq;
                Nodo *der;
        };
        Nodo *raiz;
        Nodo *actual;

        void Borrar(Nodo* &);

    public:
        AB() : raiz(NULL), actual(NULL) {} //Constructor.
        ~AB() //Destructor.
        {
            Borrar(raiz);
        }
        void Insertar(char caracter, int frec); //Inserta elemento.
        void Eliminar(char caracter, int frec); //Borra elemento.
        bool esVacio(Nodo *n); //Comprueba si el arbol esta vacio.
        bool esHoja(Nodo *n); //Comprueba si el nodo es hoja.
        void inOrden(Nodo *nodo);
        void preOrden(Nodo *nodo);
};

void AB::Borrar(Nodo* &nodo) //DESTRUCTOR (recursivo en postorden).
{
   if(nodo)
   {
      Borrar(nodo->izq);
      Borrar(nodo->der);
      delete nodo;
      nodo = NULL;
   }
}

void AB::Insertar(char caracter, int frec)
{
    Nodo *padre = NULL;
    actual = raiz;

    while(!esVacio(actual) && caracter != actual->letra) //Buscar el caracter en el arbol, manteniendo un puntero al nodo padre.
    {
        padre = actual;

        if(frec > actual->frecuencia)
            actual = actual->der;
        else if(frec < actual->frecuencia)
            actual = actual->izq;
    }
    if(!esVacio(actual)) //Si se encontro el elemento, no insertar.
        return;
    if(esVacio(padre)) //Si padre es NULL, entonces el nuevo nodo sera la raiz.
        raiz = new Nodo(caracter, frec, NULL);
    else if(frec < padre->frecuencia) //Si la precuencia es menor que la del nodo padre, lo insertamos a la izquierda.
        padre->izq = new Nodo(caracter, frec, 0);
    else if(frec > padre->frecuencia) //Si la precuencia es menor que la del nodo padre, lo insertamos a la derecha.
        padre->der = new Nodo(caracter, frec, 1);
}

void AB::Eliminar(char caracter, int frec)
{
    Nodo *padre = NULL;
    Nodo *nodo;
    int aux;

    actual = raiz;
    while(!esVacio(actual)) //Mientras el valor este en el arbol...
    {
        if(caracter == actual->letra) //Si el valor está en el nodo actual...
        {
            if(esHoja(actual)) //Comprobar que es hoja, de ser asi, lo borramos.
            {
                if(padre) //Si tiene padre (no es nodo raiz) anulamos el puntero que le hace referencia.
                {
                    if(padre->der == actual)
                        padre->der = NULL;
                    else if(padre->izq == actual)
                        padre->izq = NULL;
                }
                delete actual; //Borrar el nodo.
                actual = NULL;
                return;
            }
            else //Si no es hoja.
            {
                padre = actual;
                if(actual->der) //Buscar nodo mas izquierdo de rama derecha.
                {
                    nodo = actual->der;
                    while(nodo->izq)
                    {
                        padre = nodo;
                        nodo = nodo->izq;
                    }
                }
                else //O buscar nodo mas derecho de rama izquierda.
                {
                    nodo = actual->izq;
                    while(nodo->der)
                    {
                        padre = nodo;
                        nodo = nodo->der;
                    }
                }
                //Intercambiar valores de nodo a borrar. De esta forma solo borramos nodos hojas.
                aux = actual->letra;
                actual->letra = nodo->letra;
                nodo->letra = aux;
                actual = nodo;
            }
        }
        else //Si el valor no esta en el nodo actual, buscar...
        {
            padre = actual;
            if(frec > actual->frecuencia)
                actual = actual->der;
            else if(frec < actual->frecuencia)
                actual = actual->izq;
        }
    }
}

bool AB::esVacio(Nodo *n)
{
    return n==NULL;
}

bool AB::esHoja(Nodo *n)
{
    return !n->der && !n->izq;
}

void AB::inOrden(Nodo *nodo)
{
    if(nodo != NULL)
    {
        inOrden(nodo->izq);
        cout << nodo->letra << ", ";
        inOrden(nodo->der);
    }
 }

void AB::preOrden(Nodo *nodo)
{
    if(nodo != NULL)
    {
        cout << nodo->letra << ", ";
        preOrden(nodo->izq);
        preOrden(nodo->der);
    }
 }

#endif
