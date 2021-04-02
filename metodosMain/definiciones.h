#ifndef DEFINICIONES_H
#define DEFINICIONES_H
#include <iostream>

Puerto *obtenerIdPuerto(std::string paramId);
Barco *obtenerIdBarco(std::string paramId);
void agregarPuerto(std::string id, std::string nombre, const DtFecha &fechaCreacion);
void eliminarSocio(std::string ci);
DtMascota **obtenerMascotas(std::string ci, int &cantMascotas);
DtMascota *crearDtMascota(std::string tipoMascota);
void imprimirTextoPrincipal();
void colorAlTexto();
void menuCaso4();
void obtenerFechaDelSitema(int &dia, int &mes, int &anio);

#endif