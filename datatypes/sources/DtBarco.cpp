#include "./../headers/DtBarco.h"
DtBarco::DtBarco() {}
DtBarco::DtBarco(std::string _id, std::string _nombre)
{
    this->id = _id;
    this->nombre = _nombre;
}

std::string DtBarco::getId()
{
    return this->id;
}

std::string DtBarco::getNombre()
{
    return this->nombre;
}

void DtBarco::setId(std::string _id)
{
    this->id = _id;
}

void DtBarco::setNombre(std::string _nombre)
{
    this->nombre = _nombre;
}

DtBarco::~DtBarco()
{
}

std::ostream& operator<<(std::ostream& out , DtBarco* info) {
	info->print(out);
	return out;
}

