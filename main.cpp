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
    //std::cout << barco2->getId();
    //std::cout << barco3->getId();
    agregarBarco(barco2);
    agregarBarco(barco3);
    //agregarBarco(barco1);
    //agregarPuerto("2","puertop", DtFecha(dia, mes, anio));
    //agregarArribo("2", "3", 50);
    //std::cout << "c";
   //DtBarco **barquitos = listarBarcos();
   /* Barco *b = obtenerIdBarco("5");
     for (int i=0; i < 2; i++) {

        std::cout << barquitos[i];
        //std::cout << barco1.getNombre();


    }*/
    agregarPuerto("1","puertop1", DtFecha(dia, mes, anio));
    agregarPuerto("2","puertop2", DtFecha(dia, mes, anio));
    agregarArribo("2", "Barquito", 0);
    agregarArribo("2", "4", 40);
    Barco *b = obtenerIdBarco("Barquito");
    //std::cout<< b->getNombre();
    Puerto *p = obtenerIdPuerto("5");
    //std::cout<< b->getNombre();
    if(b == NULL){
        std::cout <<"lmao";
    }
    //std::cout<< puerot->getCantArribos();

    DtPuerto *puertitos = listarPuertos();
    //Arribo a = puertos[0].getArribos;
    /*for (int i=0; i < 2; i++) {

        std::cout << puertitos[i].getNombre();

        //std::cout << barco1.getNombre();

    }*/
    DtArribo *a=obtenerInfoArribosEnPuerto("2");
    for (int i=0; i < 2; i++) {

        std::cout << a[i].getCarga();

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
