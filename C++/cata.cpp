#include <iostream> // input output 
#include <fstream>
#include <sstream>

using namespace std;
/*se desea crear un programa el cual simule una tienda de compra online para poder ingresear al portal, se debe solicitar un usuario y 
clave , estos se encontraran en un archivo para ser validados. luego se debe mostrar la lista de productos,la que presenta los detalles
del nombre, precio y cantidad. el usuario podra comprar tantos productos como desee, sin sobrepasar su linea de credito, ni el stock 
del producto

se debe considerar lo siguiente

la linea de credito se encuentra en archivo de usuarios en el siguiente formato. user;pass;linea_de_credito
el formato de la linea de productos es siguiente: nombre; precio; stock
luego de realizar todas las comrpas el usuario puede respaldarlas en un arichvo
deben crear un metodo para validar el usuario, otro para rescatar la lista de productos y otro para guardar la lista de compra. */
static int lineaDeCredito;
static string stringLineaCredito;


bool is_logged_in(string usuario, string password)
{
	string linea1, linea2,linea3;
	bool estado=false;
	
	ifstream archivoUsuario;
	archivoUsuario.open("ArchivoUsuario.txt"); // FILE *file = fopen("Archivousuario.txt")


	while (archivoUsuario.good()) // lo mismo que EOF
	{
		getline(archivoUsuario,linea1);
		getline(archivoUsuario,linea2);
		getline(archivoUsuario,linea3);
    

		if (linea1 == usuario && linea2 == password)
		{
			stringstream ss(linea3);
			ss>>lineaDeCredito;
			estado = true;
			cout << "Usted Dispone de: " << linea3 << endl;
			stringLineaCredito = linea3;

		}
		
	}
	archivoUsuario.close();
	return estado;

}

void mostrar_productos ()
{
	string linea1, linea2,linea3;

	ifstream archivoProducto;
	archivoProducto.open("listadoProductos.txt");
	while(archivoProducto.good())
	{

		getline(archivoProducto, linea1);
		getline(archivoProducto, linea2);
		getline(archivoProducto, linea3);

		if (linea1.length()==0)
		{
			break;
		}
		cout << linea1 << " " << linea2 << " " <<linea3 << endl;
	}

	archivoProducto.close();
}

void comprar(string item)
{
		string linea1, linea2,linea3;
		int stock, precio;
		string aux;

		ifstream archivoProductoLectura;
		archivoProductoLectura.open("listadoProductos.txt");
		ofstream archivoProductoEscritura;
		archivoProductoEscritura.open("listadoProductos2.txt");

		while(archivoProductoLectura.good()) //ejecuion de compra
		{

			getline(archivoProductoLectura, linea1);
			getline(archivoProductoLectura, linea2);
			getline(archivoProductoLectura, linea3);

			
			if (item == linea1)
			{
				stringstream ss(linea3);
				ss>>stock;
				stringstream sd(linea2);
				sd>>precio;


				
				if (stock > 0 )
				{
					int presupuesto = lineaDeCredito-precio;
					if (presupuesto >= 0 )
					{
						stock -=1;
						lineaDeCredito -= precio;
						
						std::stringstream out; //stock from int to string
						out << stock;
						linea3 = out.str();//end stock

						std::stringstream out2; //credito from int to string
						out2 << lineaDeCredito;
						stringLineaCredito = out2.str();//end credito

						cout << "Compra ejecutada" <<endl;
					}
					else
						cout <<"No hay suficiente Credito" << endl;
										
				}
				else
					cout << "No hay suficiente stock" <<endl;
			}
			if (linea1.length() == 0)
				break;
			
			archivoProductoEscritura << linea1 << endl;
			archivoProductoEscritura << linea2 << endl;
			archivoProductoEscritura << linea3 << endl;

		}

		archivoProductoLectura.close();
		archivoProductoEscritura.close();
}

void cambiarLineaDeCredito(string usuario, string password)
{
	string linea1, linea2,linea3, aux;
	ifstream archivoUsuario;
	archivoUsuario.open("ArchivoUsuario.txt");

	ofstream archivoUsuarioEscritura;
	archivoUsuarioEscritura.open("ArchivoUsuario2.txt");

	while (archivoUsuario.good())
	{
		getline(archivoUsuario,linea1);
		getline(archivoUsuario,linea2);
		getline(archivoUsuario,linea3);

		if (linea1 == usuario && linea2 == password)
		{
			linea3 = stringLineaCredito;	
		}

		
		if (linea1.length() == 0)
			break;
		
		archivoUsuarioEscritura << linea1 << endl;
		archivoUsuarioEscritura << linea2 << endl;
		archivoUsuarioEscritura << linea3 << endl;

	
	}
	archivoUsuario.close();
	archivoUsuarioEscritura.close();
}

int main()
{
	string usuario, password, linea1, linea2,linea3, item;


	cout << "Usuario: "; //printf("");
	cin >> usuario; //scanf("%s", &usuario);
	cout << "Contraseña: ";
	cin >> password; ; //scanf("%s", &password);

	if (is_logged_in(usuario,password))
	{
		
		mostrar_productos();
		cout<< "Que desea comprar?" << endl;
		cin >> item;

		comprar(item);

		cambiarLineaDeCredito(usuario,password);

	}
	else
	{
		cout << "Usuario no existe" << endl;;
	}
	

  int result;
  char oldname[20] ="ArchivoUsuario2.txt";
  char newname[19] ="ArchivoUsuario.txt";
  result= rename( oldname , newname );

  char oldname2[22] = "listadoProductos2.txt";
  char newname2[21] = "listadoProductos.txt";
  result = rename(oldname2, newname2);

	return 0;
}
/*

*/