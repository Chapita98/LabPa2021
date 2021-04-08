#include "../headers/DtBarcoPesquero.h"
DtBarcoPesquero::DtBarcoPesquero() {}
DtBarcoPesquero::DtBarcoPesquero(int capacidad, int carga)
{
  this->capacidad = capacidad;
  this->carga = carga;
}

DtBarcoPesquero::DtBarcoPesquero(int capacidad, int carga, std::string id, std::string nombre)
{
  this->capacidad = capacidad;
  this->carga = carga;
}

int DtBarcoPesquero::getCapacidad()
{
  return this->capacidad;
}

int DtBarcoPesquero::getCarga()
{
  return this->carga;
}

void DtBarcoPesquero::setCarga(int carga)
{
  this->carga = carga;
}

void DtBarcoPesquero::setCapacidad(int capacidad)
{
  this->capacidad = capacidad;
}

DtBarcoPesquero::~DtBarcoPesquero() {}

//Overload de <<
/*std::ostream &operator<<(std::ostream &o, DtMascota *dtM)
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
}*/
