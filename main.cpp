#include <iostream>
#include <stdexcept>
#include <ctime>
#include <string>

#include "classes/headers/Puerto.h"
#include "classes/headers/Arribo.h"
#include "classes/headers/Barco.h"
#include "classes/headers/BarcoPesquero.h"
#include "classes/headers/BarcoPasajeros.h"

#include "datatypes/headers/DtArribo.h"
#include "datatypes/headers/DtBarco.h"
#include "datatypes/headers/DtBarcoPesquero.h"
#include "datatypes/headers/DtBarcoPasajeros.h"
#include "datatypes/headers/DtFecha.h"
#include "datatypes/headers/DtPuerto.h"

#include "datatypes/headers/TipoTamanio.h"
#include "metodosMain/Definiciones.h"

using namespace std;

void imprimirTextoPrincipal();

const int MAX_PUERTOS = 30;
const int MAX_BARCOS = 30;

Puerto **puertos = new Puerto *[MAX_PUERTOS];
int cantidadPuertos = 0;

Barco **barcos = new Barco *[MAX_BARCOS];
int cantidadBarcos = 0;

int main(int argc, char **argv)
{
	int opcionUsuario;
	bool bandera = true;
	while (bandera == true)
	{
		colorAlTexto();
		imprimirTextoPrincipal();
		getline(cin, opcionUsuario, '\n');
		cin.clear();
		try
		{
			switch (opcionUsuario)
			{
			case 0: //CASO SALIDA DE SISTEMA
			{
				cout << "Gracias por usar nuestro programa";
				bandera = false;
			}
			case 1: //AGREGAR PUERTO
			{
				std::string id, nombre; //nota: agregar fecha de creacion al entrar al void.
				cout << "Ingrese en orden ci y nombre: ";
				cin >> id >> nombre;
				//const DtPuerto* puerto = crearDtPuerto();  //crearDtPuerto se podria hacer sobreescribiendo el crearDtMascota que deje abajo del todo
				agregarPuerto(id, nombre); // + const DtFecha fechaCreacion
				break;
			}
			case 2: //AGREGAR BARCO
			{
				std::string nombre, id;
				cout << "Ingrese el nombre e id del barco: ";
				cin >> nombre >> id;
				agregarBarco(nombre, id);
				break;
			}
			case 3: //LISTAR PUERTOS
			{

				break;
			}
			case 4: //AGREGAR ARRIBO
			{

				break;
			}
			case 5: //OBTENER INFORMACION DE ARRIBOS EN PUERTO
			{

				break;
			}
			case 6: //ELIMINAR ARRIBOS
			{

				break;
			}
			case 7: //LISTAR BARCOS
			{

				break;
			}
			default:
				throw std::invalid_argument("La opcion ingresada no es correcta");
			}
		}
		catch (std::invalid_argument &e)
		{
			cout << "\nError: " << e.what() << endl;
		}
	}
	return 0;
}
