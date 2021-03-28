#include "../headers/DtArribo.h"

DtArribo::DtArribo(std::string _nombre, const Genero &_genero, float _peso) : genero(_genero) {
    this->nombre = _nombre;
    this->peso = _peso;
}

std::string DtArribo::getNombre() const {
    return this->nombre;
}

Genero DtArribo::getGenero() const {
    return this->genero;
}

float DtArribo::getPeso() const {
    return this->peso;
}

DtArribo::~DtArribo(){ }

//Overload de <<
std::ostream &operator<<(std::ostream &o, DtArribo *dtM)
{
    o << std::string("Nombre: ") << dtM->getNombre() << std::string("\n");

    if (dtM->getGenero() == Genero::Macho)
    {
        o << std::string("Genero: Macho") << std::string("\n");
    }
    else
    {
        o << std::string("Genero: Hembra") << std::string("\n");
    }
    o << std::string("Peso: ") << std::to_string(dtM->getPeso());
    return o;
}
