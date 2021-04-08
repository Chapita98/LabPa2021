#include "../headers/DtBarcoPasajeros.h"
DtBarcoPasajeros::DtBarcoPasajeros() {}

DtBarcoPasajeros::DtBarcoPasajeros(int _cantPasajeros, TipoTamanio _tamanio)
{
	this->cantPasajeros = _cantPasajeros;
	this->tamanio = _tamanio;
}

int DtBarcoPasajeros::getCantPasajeros()
{
	return this->cantPasajeros;
}

auto DtBarcoPasajeros::getTamanio()
{
	return this->tamanio;
}

void DtBarcoPasajeros::setCantPasajeros(int _cantPasajeros)
{
	this->cantPasajeros = _cantPasajeros;
}

void DtBarcoPasajeros::setTamanio(TipoTamanio _tamanio)
{
	this->tamanio = _tamanio;
}

DtBarcoPasajeros::~DtBarcoPasajeros() {}

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
