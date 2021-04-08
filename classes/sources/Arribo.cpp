#include "./../headers/Arribo.h"
// Lista
Arribo::Arribo() {}
Arribo::Arribo(DtFecha paramFechaDeArribo, float paramCarga) : fechaDeArribo(paramFechaDeArribo)
{
    this->fechaDeArribo = paramFechaDeArribo;
    this->carga = paramCarga;
}
// Getters
DtFecha Arribo::getFechaDeArribo()
{
    return this->fechaDeArribo;
}

float Arribo::getCarga()
{
    return this->carga;
}
// Setters

void Arribo::setFechaDeArribo(DtFecha &paramFechaDeArribo)
{
    this->fechaDeArribo = paramFechaDeArribo;
}
void Arribo::setCarga(float paramCarga)
{
    this->carga = paramCarga;
}

Arribo::~Arribo() {}
