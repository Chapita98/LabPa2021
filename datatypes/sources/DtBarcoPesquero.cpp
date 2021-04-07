#include "../headers/DtBarco.h"

DtBarcoPesquero::DtBarcoPesquero(int capacidad, int carga)
{
    this->Capacidad = capacidad;
    this->Carga = carga;
}

DtBarcoPesquero::DtBarcoPesquero(int capacidad, int carga, std::string nombre, std::string id) : DtBarco(nombre, id)
{
    this->Capacidad = capacidad;
    this->Carga = carga;
}

int DtBarcoPesquero::getCapacidad()
{
    return this->Capacidad;
}

int DtBarcoPesquero::getCarga()
{
    return this->Carga;
}

void DtBarcoPesquero::setCarga(int carga)
{
    this->Carga = carga;
}

void DtBarcoPesquero::setCapacidad(int capacidad)
{
    this->Capacidad = capacidad;
}

DtBarcoPesquero::~DtBarcoPesquero() {}

//Overload de <<
std::ostream &operator<<(std::ostream &o, DtMascota *dtM)
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

  //o << std::string("Genero: ") << dtM->getGenero() << std::string("\n");
  o << std::string("Peso: ") << std::to_string(dtM->getPeso());

  return o;
}
