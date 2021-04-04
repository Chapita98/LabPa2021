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
		std::cin >> opcionUsuario;
		std::cin.clear();
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
				menuCaso3();
				break;
			}
			case 4: //AGREGAR ARRIBO
			{
				menuCaso4();
				break;
			}
			case 5: //OBTENER INFORMACION DE ARRIBOS EN PUERTO
			{
				menuCaso5();
				break;
			}
			case 6: //ELIMINAR ARRIBOS
			{
				menuCaso6();
				break;
			}
			case 7: //LISTAR BARCOS
			{
				menuCaso7();
				break;
			}
			default:
				throw std::invalid_argument("\nLa opcion ingresada no es correcta.\n");
			}
		}
		catch (std::invalid_argument &e)
		{
			std::cerr << e.what() << endl;
		}
	}
	return 0;
}