#include "../headers/DtPuerto.h"

DtPuerto::DtPuerto(std::string _id, std::string _nombre, DtFecha _fechaCreacion){
	this->Id = _id;
	this->Nombre = _nombre;
    this->FechaCreacion = _fechaCreacion;
}

std::string DtPuerto::getId() const {
	return this->Id;
}

string DtPuerto::getnombre() const {
	return this->Nombre;
}

DtFecha DtPuerto::getFechaCreacion() const{
    return this->FechaCreacion;
}

DtPuerto::~DtPuerto() {
}


//Overload de <<
std::ostream& operator<<(std::ostream &o, DtPuerto* dtP) {
    	
    o << std::string("Id: ") <<  std::to_string (dtP->getId()) << std::string("\n");
	o << std::string("Nombre: ") << dtP->getNombre() << std::string("\n");
    o <<  /* ingresar fecha de ahora*/ << std::to_string (dtP->getFechaCreacion()) << std::string("\n");
    return o;
}
