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

/*std::ostream& operator<<(std::ostream& out , DtBarco* info) {
	info->print(out);
	return out;
}*/

//Overload de <<
/*std::ostream &operator<<(std::ostream &o, DtGato *dtG)
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
}*/
