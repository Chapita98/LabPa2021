#include <iostream>
#include <stdexcept>

#include "./metodosMain/definiciones.h"

using namespace std;

int main(int argc, char **argv)
{
	int opcionUsuario;
	bool bandera = true;
	int dia, mes, anio =0;
    int tam = 3;
    TipoTamanio tamanio;
    switch(tam)
    {
        case BOTE:
            tamanio= TipoTamanio::BOTE;
            break;
        case CRUCERO:
            tamanio= TipoTamanio::CRUCERO;
            break;
        case GALEON:
            tamanio= TipoTamanio::GALEON;
            break;
        case TRANSATLANTICO:
            tamanio= TipoTamanio::TRANSATLANTICO;
            break;
        default:
            throw std::invalid_argument("Ingrese tamanio valido");
            break;
        }

    DtBarcoPasajeros *barco2 = new DtBarcoPasajeros(300, tamanio, "3", "Barquito");
    DtBarcoPasajeros *barco3 = new DtBarcoPasajeros(300, tamanio, "5", "Barquito2");
    DtBarcoPesquero *barco1 = new DtBarcoPesquero(300, 30, "Barcoup", "4");
    agregarBarco(barco1);
    agregarBarco(barco2);
    agregarBarco(barco3);
    agregarPuerto("1","puertop1", DtFecha(dia, mes, anio));
    agregarPuerto("2","puertop2", DtFecha(dia, mes, anio));
    agregarArribo("2", "Barquito", 0);
    agregarArribo("2", "4", 20);
    DtArribo *a=obtenerInfoArribosEnPuerto("2");
    for (int i=0; i < 2; i++) {

        std::cout << "\nLa carga es: " << a[i].getCarga();

    }
	/*
/*while (bandera == true)
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
	}*/
	return 0;
}
