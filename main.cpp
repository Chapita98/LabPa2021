#include <iostream>
#include <stdexcept>

#include "./metodosMain/Definiciones.h"

using namespace std;

int main(int argc, char **argv)
{
	int opcionUsuario;
	bool bandera = true;
	while (bandera == true)
	{
		imprimirTextoPrincipal();
		getline(std::cin, opcionUsuario, '\n');
		// std::cin.clear(); TODO: hacer prueba con el throw
		try
		{
			switch (opcionUsuario)
			{
			case 0: //CASO SALIDA DE SISTEMA
			{
				std::cout << "\nGracias por usar nuestro programa.\n";
				bandera = false;
				break;
			}
			case 1: //AGREGAR PUERTO
			{
				menuCaso1();
				break;
			}
			case 2: //AGREGAR BARCO
			{
				menuCaso2();
				break;
			}
			case 3: //LISTAR PUERTOS
			{

				break;
			}
			case 4: //AGREGAR ARRIBO
			{
				menuCaso4();
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
			std::cerr << e.what() << endl;
			bandera = false;
			break;
		}
	}
	return 0;
}