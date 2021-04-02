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

#include "./../datatypes/headers/DtArribo.h"
#include "./../datatypes/headers/DtBarco.h"
#include "./../datatypes/headers/DtBarcoPesquero.h"
#include "./../datatypes/headers/DtBarcoPasajeros.h"
#include "./../datatypes/headers/DtFecha.h"
#include "./../datatypes/headers/DtPuerto.h"
#include "./../datatypes/headers/TipoTamanio.h"

Puerto *obtenerIdPuerto(std::string paramId);
Barco *obtenerIdBarco(std::string paramId);
void agregarPuerto(std::string id, std::string nombre, const DtFecha &fechaCreacion);
void eliminarSocio(std::string ci);
DtMascota **obtenerMascotas(std::string ci, int &cantMascotas);
DtMascota *crearDtMascota(std::string tipoMascota);
void imprimirTextoPrincipal();
void colorAlTexto();
void menuCaso1();
void menuCaso2();
void menuCaso4();
void obtenerFechaDelSitema(int &dia, int &mes, int &anio);

#endif