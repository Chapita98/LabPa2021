#ifndef PUERTO_H
#define PUERTO_H

#include "./../../datatypes/headers/DtFecha.h"
#include "./Arribo.h"

class Puerto
{
private:
	std::string id;
	std::string nombre;
	DtFecha fechaCreacion;
	int cantidadArribos;

public:
	Puerto();
	Puerto(std::string _id, std::string _nombre, DtFecha _fechaCreacion);

	static const int MAX_ARRIBOS = 30;

	std::string getId();
	std::string getNombre();
	DtFecha getFechaCreacion();

	void setId(std::string _id);
	void setNombre(std::string _nombre);
	void setFechaCreacion(DtFecha &_fechaCreacion);

	void agregarPuerto(std::string _id, std::string _nombre, DtFecha &_fechaCreacion);
	Puerto *obtenerIdPuerto(std::string _id);

	virtual ~Puerto();
};

#endif /* PUERTO_H */
