#include "../headers/DtPuerto.h"
#include "../headers/DtFecha.h"
#include <string>

DtPuerto::DtPuerto(std::string _id, std::string _nombre, DtFecha _fechaCreacion){
	this->id = _id;
	this->nombre = _nombre;
    this->fechaCreacion = _fechaCreacion;
}

std::string DtPuerto::getId() const {
	return this->id;
}

std::string DtPuerto::getNombre() const {
	return this->nombre;
}

DtFecha DtPuerto::getFechaCreacion() const{
    return this->fechaCreacion;
}

DtPuerto::~DtPuerto() {
}


//Overload de <<
std::ostream& operator<<(std::ostream &o, DtPuerto* dtP) {
    	
    o << std::string("Id: ") <<  std::to_string (dtP->getId()) << std::string("\n");
	o << std::string("Nombre: ") << dtP->getNombre() << std::string("\n");
    o << std::string("Fecha: ") << std::to_string (dtP->getFechaCreacion()) << std::string("\n");
    return o;
}
