#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include "List.h"
#include "Huffman.h"
#include "AB.h"

using namespace std;

List::List() //Constructor.
{
	root=NULL;
}

List::~List () //Destructor.
{
	delete root;
}

int main (int argc, char const* argv[])
{
	string inputInt, inputString;
	int parseInt,i,contador=0, fnodo1, fnodo2, nodoizquierdo=0, nododerecho=0, suma, largo;
	char parseChar;
	List object;
	bool status=false; //Es un flag para decirle a la funcion agregar que debe usar los punteros left y right para anidar.
	vector<string> myLetter(22), myFrequency(22); //el arbol.

	ifstream myfile("frecuencia.txt", ios::in);

    if (myfile.is_open())
	{
		while(!myfile.eof()) //Monta todo el archivo de frecuencias a una lista.
		{
			getline(myfile, inputString);
			getline(myfile, inputInt);

			istringstream buffer(inputInt);

			buffer >> parseInt; //Cambia de string a int.
			parseChar=inputString[0]; //Cambia de string a char.
			i=parseChar; //Convierte la letra en su homologo formato INT en codigo ASCII.
			if (i!=0) //Esta comparacino es para que no agrege a la lista el /n (new line) del archivo.
			{
				myLetter[contador]=inputString; //myLetter y myFrequency son una especie de base de datos para comparar con el arbol que se generara.
				myFrequency[contador]=inputInt;

				object.ordenar(parseInt, parseChar,status, nodoizquierdo, nododerecho);
			}
			contador++;
		}
	myfile.close();
	}

    else
        cout<< "Unable to Open The File" <<endl;

    status=true; //Se cambia el estado de insercion para avisar que ahora debe empezar a crear el arbol con las inserciones.
    parseChar='-';
    largo = object.length();

    while (largo>1)
    {
        object.show();
        fnodo1=object.primera_posicion();
        fnodo2=object.segunda_posicion();
        suma=fnodo1+fnodo2;
        object.borrar_primeras_2posiciones();
        object.ordenar(suma,parseChar,status,fnodo1,fnodo2);
        largo=object.length();
        cout<<endl;
    }

    AB arbol;
    List::node *temp = object.root;

    while(temp->next != NULL)
    {
        arbol.Insertar(temp->letra, temp->frequency);
        temp = temp->next;
    }

    AB::Nodo *temp2 = arbol.raiz;
    arbol.preOrden(temp2);
    cout << "\n";
    arbol.inOrden(temp2);
    cout << endl;

    return 0;
}
