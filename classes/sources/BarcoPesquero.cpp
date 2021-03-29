
BarcoPesquero::BarcoPesquero(int capacidad, int carga) {
	this->Capacidad = capacidad;
	this->Carga = carga;
}

int BarcoPesquero::getCapacidad() const{
    return this->Capacidad;
}

int BarcoPesquero::getCarga() const{
    return this->Carga;
}

void BarcoPesquero::setCarga(int carga) {
    this->Carga = carga;
}

void BarcoPesquero::setCapacidad(int capacidad){
    this->Capacidad = capacidad;
}

void BarcoPesquero::Arribar(float cargaDespacho){
    //???
}

BarcoPesquero::~BarcoPesquero(){

}
