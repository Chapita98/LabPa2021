#include "./../headers/Barco.h"

Barco::Barco(std::string nombre, std::string id)
{
	this->Id = id;
	this->Nombre = nombre;
}

std::string Barco::getId() const
{
	return this->Id;
}

std::string Barco::getNombre() const
{
	return this->Nombre;
}

void Barco::setId(std::string id)
{
	this->Id = id;
}

void Barco::setNombre(std::string nombre)
{
	this->Nombre = nombre;
}

Barco::~Barco() {}
