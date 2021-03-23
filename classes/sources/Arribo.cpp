//#include <"../datatypes/sources/DtFecha"> //no se como era
#include <stdexcept>


Arribo::Arribo(float carga, DtFecha fecha){
	this->Fecha = fecha;
	this->Carga = carga;
}

float Arribo::getCarga() const {
	return this->Carga;
}

DtFecha Arribo::getFecha() const {
	return this->Fecha;
}



Arribo::~Arribo() {

}
