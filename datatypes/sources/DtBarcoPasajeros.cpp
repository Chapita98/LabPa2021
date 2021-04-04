#include "../headers/DtBarcoPasajeros.h"

DtBarcoPasajeros::DtBarcoPasajeros(int cantpasajeros, TipoTamanio tamanio) {
	this->cantPasajeros = cantpasajeros;
	this->Tamanio = tamanio;
}

int DtBarcoPasajeros::getcantPasajeros() {
	return this->cantPasajeros;
}

auto DtBarcoPasajeros::getTamanio() {
	return this->Tamanio;
}

void DtBarcoPasajeros::setcantPasajeros(int cantpasajeros) {
	this->cantPasajeros =  cantpasajeros;

}

void DtBarcoPasajeros::setTamanio(TipoTamanio tamanio) {
	this->Tamanio =  tamanio;

}

DtBarcoPasajeros::~DtBarcoPasajeros(){

}

//Overload de <<
std::ostream& operator<<(std::ostream &o, DtMascota* dtM) {
    o << std::string("Nombre: ") << dtM->getNombre() << std::string("\n");
    
    if(dtM->getGenero()==Genero::Macho){
		o << std::string("Genero: Macho")<< std::string("\n");
	}else{
			o << std::string("Genero: Hembra")<< std::string("\n");
	}
	
    //o << std::string("Genero: ") << dtM->getGenero() << std::string("\n");
    o << std::string("Peso: ") <<  std::to_string (dtM->getPeso());

    return o;
}

