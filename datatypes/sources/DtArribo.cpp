#include "../headers/DtArribo.h"
// Lista
DtArribo::DtArribo(DtBarco paramBarcoQueArriba, DtFecha paramFechaDeArribo, float paramCargaDespachada)
{
    this->barcoQueArriba = paramBarcoQueArriba;
    this->fechaDeArribo = paramFechaDeArribo;
    this->cargaDespachada = paramCargaDespachada;
}
// Getters
DtBarco DtArribo::getBarcoQueArriba()
{
    return this->barcoQueArriba;
}

DtFecha DtArribo::getFechaDeArribo()
{
    return this->fechaDeArribo;
}

float DtArribo::getCargaDespachada()
{
    return this->cargaDespachada;
}
// Setters
void DtArribo::setBarcoQueArriba(DtBarco paramBarcoQueArriba)
{
    this->barcoQueArriba = paramBarcoQueArriba;
}
void DtArribo::setFechaDeArribo(DtFecha paramFechaDeArribo)
{
    this->fechaDeArribo = paramFechaDeArribo;
}
void DtArribo::setCargaDespachada(float paramCargaDespachada)
{
    this->cargaDespachada = paramCargaDespachada;
}

DtArribo::~DtArribo() {}
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