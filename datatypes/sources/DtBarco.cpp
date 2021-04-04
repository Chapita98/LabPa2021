#include "../headers/DtBarco.h"

DtBarco::DtBarco(std::string nombre, std::string id) {
	this->Nombre = nombre;
	this->Id = id;
}

std::string DtBarco::getId() const{
	return this->Id;
}

std::string DtBarco::getNombre() const{
	return this->Nombre;
}

void DtBarco::setId(std::string id) {
	this->Id = id;

}

void DtBarco::setNombre(std::string nombre) {
	this->Nombre =  nombre;

}

DtBarco::~DtBarco(){

}

//Overload de <<
std::ostream &operator<<(std::ostream &o, DtGato *dtG)
{

    o << std::string("Nombre: ") << dtG->getNombre() << std::string("\n");

    if (dtG->getGenero() == Genero::Macho)
    {
        o << std::string("Genero: Macho") << std::string("\n");
    }
    else
    {
        o << std::string("Genero: Hembra") << std::string("\n");
    }

    o << std::string("Peso: ") << std::to_string(dtG->getPeso()) << std::string("\n");

    if (dtG->getPelo() == TipoPelo::Corto)
    {
        o << std::string("Tipo de Pelo: Corto") << std::string("\n");
    }
    else if (dtG->getPelo() == TipoPelo::Mediano)
    {
        o << std::string("Tipo de Pelo: Mediano") << std::string("\n");
    }
    else
    {
        o << std::string("Tipo de Pelo: Largo") << std::string("\n");
    }

    return o;
}
