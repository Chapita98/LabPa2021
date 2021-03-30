#include "../headers/Arribo.h
// Lista
Arribo::Arribo(DtFecha paramFechaDeArribo, float paramCargaDespachada)
{
    this->fechaDeArribo = paramFechaDeArribo;
    this->cargaDespachada = paramCargaDespachada;
}
// Getters
DtFecha Arribo::getFechaDeArribo()
{
    return this->fechaDeArribo;
}

float Arribo::getCargaDespachada()
{
    return this->cargaDespachada;
}
// Setters

void Arribo::setFechaDeArribo(DtFecha paramFechaDeArribo)
{
    this->fechaDeArribo = paramFechaDeArribo;
}
void Arribo::setCargaDespachada(float paramCargaDespachada)
{
    this->cargaDespachada = paramCargaDespachada;
}

Arribo::~Arribo() {}