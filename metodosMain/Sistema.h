#ifndef SISTEMA_H
#define SISTEMA_H
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

const int MAX_PUERTOS = 30;
const int MAX_BARCOS = 30;
const int MAX_ARRIBOS = 30;

class Sistema
{
private:
	Barco barcos[MAX_BARCOS];
	Puerto puertos[MAX_PUERTOS];
	int cantBarcos;
	int cantPuertos;

public:
	Sistema();

	int getcantBarcos();
	int getcantPuertos();
	void setcantBarcos(int cantbarcos);
	void setcantPuertos(int cantpuertos);

	void agregarBarco(DtBarco *barco);
	DtBarco *listarBarcos();
	DtPuerto *listarPuertos();

	Puerto *obtenerIdPuerto(std::string paramId);
	Barco *obtenerIdBarco(std::string paramId);
	void agregarPuerto(std::string id, std::string nombre, const DtFecha &fechaCreacion);
	void eliminarSocio(std::string ci);
	void obtenerFechaDelSitema(int &dia, int &mes, int &anio);

	~Sistema();
};

#endif
