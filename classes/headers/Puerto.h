#ifndef PUERTO_H
#define PUERTO_H

#include <string>
#include "../../datatypes/sources/DtFecha.cpp"
#include "../../classes/headers/Arribo.h"

class Puerto {
	public:
		Puerto(std::string _id, std::string nombre, DtFecha fechaCreacion);
		std::string getId() const;
		std::string getNombre() const;
		DtFecha getFechaCreacion() const;
		void agregarPuerto(std::string id, std::string nombre, const DtFecha& fechaCreacion);
		Puerto *obtenerIdPuerto(std::string paramId);
    private:
		std::string id;
		std::string nombre;
		DtFecha fechaCreacion;
		DtArribo Arribos[cantidadArribos];
};

#endif /* PUERTO_H */
