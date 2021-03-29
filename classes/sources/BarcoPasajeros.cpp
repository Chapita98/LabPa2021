

BarcoPasajeros(int cantPasajeros, const TipoTamanio & Tamanio) {
	this->cantPasajeros = cantPasajeros;
	//this->TipoTamanio = Tamanio???
}

int BarcoPasajeros::getCantPasajeros() {
	return this->cantPasajeros;
}

void BarcoPasajeros::setCantPasajeros() {
	this->cantPasajeros =  cantPasajeros;

}

BarcoPasajeros::~BarcoPasajeros(){

}
