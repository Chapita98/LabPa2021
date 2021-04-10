#include "./../headers/DtArribo.h"
// Lista
DtArribo::DtArribo() {}
DtArribo::DtArribo(DtBarco *paramBarcoQueArriba, DtFecha paramFechaDeArribo, float paramCarga) : fechaDeArribo(paramFechaDeArribo), barcoQueArriba(paramBarcoQueArriba)
{
    this->barcoQueArriba = paramBarcoQueArriba;
    this->fechaDeArribo = paramFechaDeArribo;
    this->carga = paramCarga;
}
// Getters
DtBarco* DtArribo::getBarcoQueArriba()
{
    return this->barcoQueArriba;
}

DtFecha DtArribo::getFechaDeArribo()
{
    return this->fechaDeArribo;
}

float DtArribo::getCarga()
{
    return this->carga;
}
// Setters
/*void DtArribo::setBarcoQueArriba(DtBarco paramBarcoQueArriba)
{
    this->barcoQueArriba = paramBarcoQueArriba;
}
void DtArribo::setFechaDeArribo(DtFecha paramFechaDeArribo)
{
    this->fechaDeArribo = paramFechaDeArribo;
}
void DtArribo::setCarga(float paramCarga)
{
    this->carga = paramCarga;
}*/

DtArribo::~DtArribo() {}

std::ostream& operator<<(std::ostream& out , DtArribo* info) {
	out << std::string("Carga: ") << info->getCarga() << std::string("\n");
	out << std::string("Barco: ") << info->getBarcoQueArriba() << std::string("\n");
	//out << std::string("Fecha: ") << info->getFechaDeArribo() << std::string("\n");
	return out;
}
/*
//Overload de <<
std::ostream &operator<<(std::ostream &o, DtArribo *dtM)
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
    o << std::string("Peso: ") << std::to_string(dtM->getPeso());
    return o;
}*/
