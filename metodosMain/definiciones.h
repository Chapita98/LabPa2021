#ifndef DEFINICIONES_H
#define DEFINICIONES_H
#include <iostream>

Puerto *obtenerPuerto(std::string id);
void agregarPuerto(std::string id, std::string nombre, const DtFecha &fechaCreacion);
void eliminarSocio(std::string ci);
DtMascota **obtenerMascotas(std::string ci, int &cantMascotas);
DtMascota *crearDtMascota(std::string tipoMascota);
void imprimirTextoPrincipal();
void colorAlTexto();

#endif