#include <iostream>
#include <stdexcept>
#include <ctime>
#include <string>

#include "datatypes/headers/DtArribo.h"
#include "datatypes/headers/DtBarco.h"
#include "datatypes/headers/DtBarcoPesquero.h"
#include "datatypes/headers/DtBarcoPasajeros.h"
#include "datatypes/headers/DtFecha.h"
#include "datatypes/headers/DtPuerto.h"
#include "datatypes/headers/TipoTamanio.h"
/*
#include "classes/headers/Consulta.h"
#include "classes/headers/Mascota.h"
#include "classes/headers/Perro.h"
#include "classes/headers/Gato.h"
#include "classes/headers/Socio.h"
*/
#include "datatypes/headers/DtArribo.h"
#include "datatypes/headers/DtBarco.h"
#include "datatypes/headers/DtBarcoPesquero.h"
#include "datatypes/headers/DtBarcoPasajeros.h"
#include "datatypes/headers/DtFecha.h"
#include "datatypes/headers/DtPuerto.h"
#include "datatypes/headers/TipoTamanio.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;



int main(int argc, char** argv) {
	int opcionUsuario;
	cout << "Bienvenido al sistema" << endl;
	while(true){
		//Opciones para el Usuario.
		cout << "\tElegir una Opcion:\n" << endl;
		cout << "1 Agregar Puerto.\n" << endl;
		cout << "2 Agregar Barco.\n" << endl;
		cout << "3 Listar Puertos.\n" << endl;             //Solo cuando el socio a agregar ya existe. Osea la 2da o mas mascota del socio.
		cout << "4 Agregar Arribo.\n" << endl;   //Lista mascotas por ci de socio.
		cout << "5 Obtener Informacion de Arribos en Puerto.\n" << endl;           //Pregunta de Usuario a un socio existente.
		cout << "6 Eliminar Arribos.\n" << endl;
		cout << "7 Listar Barcos.\n" << endl;
		cout << "Pulse 0 para salir.\n" << endl;
		
		cin >> opcionUsuario;
		try {

			switch(opcionUsuario){
				case 0:  //CASO SALIDA DE SISTEMA
				{
					cout << "Gracias por usar nuestro programa";
					return 0;
				}
				case 1:  //AGREGAR PUERTO
                {
                    std::string id, nombre; //nota: agregar fecha de creacion al entrar al void.
                    cout << "Ingrese en orden ci y nombre: ";
                    cin >> id >> nombre;
                    //const DtPuerto* puerto = crearDtPuerto();  //crearDtPuerto se podria hacer sobreescribiendo el crearDtMascota que deje abajo del todo
                    agregarPuerto(id, nombre); // + const DtFecha fechaCreacion
                    break;
                }
				case 2:  //AGREGAR BARCO
                {
                    std::string nombre, id;
                    cout << "Ingrese el nombre e id del barco: ";
                    cin >> nombre >> id;
                    agregarBarco(nombre, id);
                    break;
                }
				case 3:  //LISTAR PUERTOS
                {
                    
                    break;
                }
				case 4:  //AGREGAR ARRIBO
                {
                    
                    break; 
                }
				case 5:  //OBTENER INFORMACION DE ARRIBOS EN PUERTO
                {
                    
                    break;
                }
				case 6:  //ELIMINAR ARRIBOS
                {
                    
                    break;
                }
				case 7:  //LISTAR BARCOS
                {

                    break;
                }
				default:
					throw std::invalid_argument("La opcion ingresada no es correcta");
			}
		}
		catch(std::invalid_argument &e){
			cout << "\nError: " << e.what() << endl;
		}
		if (opcionUsuario != 5) { cin.ignore(); }
		cout << "\nPresione ENTER para continuar...";
		cin.get();
		cout << endl;
	}
	return 0;
}

void agregarPuerto(std::string id, std::string nombre, const DtFecha& fechaCreacion){
	
	Puerto* puerto = obtenerPuerto(id);
 
	if (puerto != NULL) { 
		throw std::invalid_argument("Ya existe un puerto con la misma id ingresada");
	}
	std::time_t t = std::time(0);      // Obtener tiempo actual
    std::tm* now = std::localtime(&t); //

	puertos[cantidadSocios] = new Puerto(ci, nombre, DtFecha(now->tm_mday, now->tm_mon + 1, now->tm_year + 1900)); //Agregar dia, mes y anio actuales a DtFecha
	puertos[cantidadSocios]->agregarPuerto();
	cantidadSocios++;
	}
}




void eliminarSocio(std::string ci){
	Socio* socio = obtenerSocio(ci);
	if (socio == NULL) { 
		throw std::invalid_argument("No existe el socio que quiere eliminar"); 
	}
	delete socio;
	std::cout << "El Socio se ha eliminado efectivamente" << '\n';
}

//queda a modo de ejemplo para listar puertos y barcos
DtMascota** obtenerMascotas(std::string ci, int& cantMascotas){
	Socio* socio = obtenerSocio(ci);
 
	if (socio == NULL) { throw std::invalid_argument("No existe un socio con la ci ingresada"); }
	
	DtMascota** retornoMascota = new DtMascota*[cantMascotas];
	Mascota** mascotasSocio = socio->getMascota();
	
	if (socio->getCantidadMascotas() < cantMascotas){ cantMascotas = socio->getCantidadMascotas(); }
	int j = 0;
	for (int i=0; i < socio->getCantidadMascotas() && j < cantMascotas; i++) {

		Perro * p = dynamic_cast<Perro*>(mascotasSocio[i]);
	    if (p) {
	        retornoMascota[j] = new DtPerro(
	        	p->getRaza(),
	        	p->getVacunaCachorro(),
	            p->getNombre(),
	            p->getGenero(),
	            p->getPeso()
	        );
	    }
	    else {
	        auto g = (DtGato*) mascotasSocio[i];
	        retornoMascota[j] = new DtGato(
	        	g->getPelo(),
	            g->getNombre(),
	            g->getGenero(),
	            g->getPeso()
	        );
	    }
		j++;
	}
	
	return retornoMascota;
}


//queda a modo de ejemplo para crear los otros dt
//Auxiliares 
DtMascota* crearDtMascota (std::string tipoMascota){
	std::string nombreMascota, generoMascota;
	float pesoMascota;
	
	DtMascota* mascota;
    if(tipoMascota == "Perro"){
        std::string raza, vacuna; 
        cout << "Ingrese en orden el nombre, genero, peso, raza y si esta vacunada la mascota (Si/No): ";
        cin >> nombreMascota >> generoMascota >> pesoMascota >> raza >> vacuna; 
            	 
		Genero genero; 
        if (generoMascota == "Macho"){
			genero = Genero::Macho;
		}else{
			genero = Genero::Hembra;
		} 
            	 
        RazaPerro razaPerro; 
		if(raza == "Labrador"){
			razaPerro = RazaPerro::Labrador;
		}else{ 
			if(raza == "Ovejero"){
				razaPerro = RazaPerro::Ovejero;
			}else{ 
				if(raza == "Bulldog"){
					razaPerro = RazaPerro::Bulldog;
				}else{ 
					if(raza == "Collie") {
                        razaPerro = RazaPerro::Collie;
                    } else { 
						if(raza == "Pekines"){
							razaPerro = RazaPerro::Pekines;
						}else{ 
							if (raza == "Otro"){
								razaPerro = RazaPerro::Otro;
							} 
						} 
					} 
				} 
			} 
		} 
            	 
        bool vacunabool = false;
        if (vacuna == "Si") {
            vacunabool = true;
        }
        
        mascota = new DtPerro(razaPerro, vacunabool, nombreMascota, genero, pesoMascota);
    } else {
		std::string tipoPelo, vacuna; 
		cout << "Ingrese en orden el nombre, genero, peso, y su tipo de pelo: ";
		cin >> nombreMascota >> generoMascota >> pesoMascota >> tipoPelo; 
			
		Genero genero; 
        if (generoMascota == "Macho"){
			genero = Genero::Macho;
		}else{
			genero = Genero::Hembra;
		} 
        	
        TipoPelo pelo; 
        	
       	if(tipoPelo == "Corto"){
            pelo = TipoPelo::Corto;
		}else{ 
			if(tipoPelo == "Mediano"){
                pelo = TipoPelo::Mediano;
			}else{ 
				if(tipoPelo == "Largo"){
                    pelo = TipoPelo::Largo;
				} 
			} 
		}
		
		mascota = new DtGato(pelo, nombreMascota, genero, pesoMascota);
	}    

    return mascota;
}  
