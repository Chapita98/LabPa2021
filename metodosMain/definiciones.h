#ifndef DEFINICIONES_H
#define DEFINICIONES_H
#include <iostream>
#include <stdexcept>
#include <ctime>
#include <string>

#include "./../classes/headers/Puerto.h"
#include "./../classes/headers/Arribo.h"
#include "./../classes/headers/Barco.h"
#include "./../classes/headers/BarcoPesquero.h"
#include "./../classes/headers/BarcoPasajeros.h"
#include "./../classes/headers/TipoTamanio.h"

#include "./../datatypes/headers/DtArribo.h"
#include "./../datatypes/headers/DtBarco.h"
#include "./../datatypes/headers/DtBarcoPesquero.h"
#include "./../datatypes/headers/DtBarcoPasajeros.h"
#include "./../datatypes/headers/DtFecha.h"
#include "./../datatypes/headers/DtPuerto.h"

//Puerto* obtenerIdPuerto(std::string paramId);
//Barco* obtenerIdBarco(std::string paramId);
void eliminarArribo(std::string id);

void imprimirTextoPrincipal();
void colorAlTexto();
void menuCaso1();
void menuCaso2();
void menuCaso3();
void menuCaso4();
void menuCaso5();
void menuCaso6();
void menuCaso7();

void agregarBarco(DtBarco *barco);
void agregarPuerto(std::string id, std::string nombre,const DtFecha &fechaCreacion);
void agregarArribo(std::string idPuerto, std::string idBarco, float cargaDespacho);
DtBarco **listarBarcos();
DtPuerto *listarPuertos();
void obtenerFechaDelSitema(int &dia, int &mes, int &anio);

#endif
