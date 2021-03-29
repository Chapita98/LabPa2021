#ifndef ARRIBO_H
#define ARRIBO_H
/* Aca van las funciones que van a usar atributos*/
#include "../../datatypes/headers/DtFecha.h"
#include "../../datatypes/headers/DtBarco.h"

class Arribo
{
private:
    DtBarco barcoQueArriba;
    DtFecha fechaDeArribo;
    float cantidadDespachada; // Puede ser negativa

public:
    // Constructor
    DtArribo(DtBarco barcoQueArriba, DtFecha fechaDeArribo, float cantidadDespachada);

    // Getters
    DtBarco getBarcoQueArriba();
    DtFecha getFechaDeArribo();
    float getCantidadDespachada();

    // Setters
    void setBarcoQueArriba(DtBarco barcoQueArriba);
    void setFechaDeArribo(DtFecha getFechaDeArribo);
    void setCantidadDespachada(float cantidadDespachada);
// void funcion1() { } // el main llama a estas
// void funcion2() { }
    virtual ~DtArribo();
};

#endif /* ARRIBO_H */