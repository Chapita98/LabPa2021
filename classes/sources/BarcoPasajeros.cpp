#include "../../headers/BarcoPasajeros.h"

BarcoPasajeros::BarcoPasajeros(int cantpasajeros, TipoTamanio tamanio) {
	this->cantPasajeros = cantpasajeros;
	this->Tamanio = tamanio
}
BarcoPasajeros:: BarcoPasajeros(int cantpasajeros, TipoTamanio tamanio, std::string nombre, std::string id): Barco(nombre, id)
{
    this->cantPasajeros = cantpasajeros;
    this->Tamanio = tamanio;
}
int BarcoPasajeros::getCantPasajeros() {
	return this->cantPasajeros;
}

TipoTamanio getTamanio() {
	return this->Tamanio;
}

void BarcoPasajeros::setCantPasajeros(int cantpasajeros) {
	this->cantPasajeros =  cantpasajeros;

}

void BarcoPasajeros::setTamanio(TipoTamanio tamanio) {
	this->Tamanio =  tamanio;

}

BarcoPasajeros::~BarcoPasajeros(){

}
