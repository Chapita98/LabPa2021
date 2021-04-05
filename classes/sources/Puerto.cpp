#include <string>
#include "../headers/Puerto.h"

Puerto::Puerto(std::string _id, std::string _nombre, DtFecha _fechaCreacion) {
  this->id = _id;
  this->nombre = _nombre;
  this->fechaCreacion = _fechaCreacion;
}

std::string Puerto::getId() const {
	return this->id;
}

std::string Puerto::getNombre() const {
	return this->nombre;
}

DtFecha Puerto::getFechaCreacion() const {
	return this->fechaCreacion;
}


 