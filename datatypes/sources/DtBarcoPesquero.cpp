#include "../headers/DtBarcoPesquero.h"
DtBarcoPesquero::DtBarcoPesquero() {}
DtBarcoPesquero::DtBarcoPesquero(int capacidad, int carga)
{
  this->capacidad = capacidad;
  this->carga = carga;
}

DtBarcoPesquero::DtBarcoPesquero(int capacidad, int carga, std::string id, std::string nombre): DtBarco(id, nombre)
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

void DtBarcoPesquero::print(std::ostream&){
	std::cout << "Id: " << this->getId() << std::endl;
	std::cout << "Nombre: " << this->getNombre() << std::endl;
	std::cout << "Capacidad: " << this->getCapacidad() << std::endl;
	std::cout << "Carga: " << this->getCarga() << std::endl;
}
