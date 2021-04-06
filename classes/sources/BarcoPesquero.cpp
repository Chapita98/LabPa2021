"./../headers/BarcoPesquero.h"
BarcoPesquero::BarcoPesquero(int capacidad, int carga) {
	this->Capacidad = capacidad;
	this->Carga = carga;
}

BarcoPesquero::BarcoPesquero(int capacidad, int carga, std::string nombre, std::string id): DtBarco(nombre, id)
{
    this->Capacidad = capacidad;
    this->Carga = carga;
}

int BarcoPesquero::getCapacidad(){
    return this->Capacidad;
}

int BarcoPesquero::getCarga(){
    return this->Carga;
}

void BarcoPesquero::setCarga(int carga) {
    this->Carga = carga;
}

void BarcoPesquero::setCapacidad(int capacidad){
    this->Capacidad = capacidad;
}

BarcoPesquero::~BarcoPesquero(){}
