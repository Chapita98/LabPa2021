#include "./../headers/BarcoPasajeros.h"

BarcoPasajeros(int cantpasajeros, TipoTamanio tamanio)
{
	this->cantPasajeros = cantpasajeros;
	this->Tamanio = tamanio
}

int BarcoPasajeros::getCantPasajeros()
{
	return this->cantPasajeros;
}

BarcoPasajeros::TipoTamanio getTamanio()
{
	return this->Tamanio;
}

void BarcoPasajeros::setCantPasajeros(int cantpasajeros)
{
	this->cantPasajeros = cantpasajeros;
}

void BarcoPasajeros::setTamanio(TipoTamanio tamanio)
{
	this->Tamanio = tamanio;
}

BarcoPasajeros::~BarcoPasajeros()
{
}
