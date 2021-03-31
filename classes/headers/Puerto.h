#ifndef PUERTO_H
#define PUERTO_H

#include <string>
#include "../../datatypes/sources/DtFecha.cpp"

class Puerto {
	public:
		Puerto(std::string _id, std::string nombre, DtFecha fechaCreacion);
		std::string getId();
		std::string getNombre();
		DtFecha fechaCreacion();
    private:
		std::string id;
		std::string nombre;
		DtFecha fechaCreacion;
};

#endif /* PUERTO_H */
