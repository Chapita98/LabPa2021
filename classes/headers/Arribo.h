#ifndef ARRIBO_H
#define ARRIBO_H
/* Aca van las funciones que van a usar atributos*/
#include "../../datatypes/headers/DtFecha.h"

class Arribo
{
private:
    DtFecha fechaDeArribo;
    float cargaDespachada; // Puede ser negativa

public:
    // Constructor
    Arribo(DtFecha fechaDeArribo, float cargaDespachada);

    // Getters
    DtFecha getFechaDeArribo();
    float getCargaDespachada();

    // Setters
    void setFechaDeArribo(DtFecha paramFechaDeArribo);
    void setCargaDespachada(float paramCargaDespachada);
    // void funcion1() { } // el main llama a estas
    // void funcion2() { }
    virtual ~Arribo();
};

#endif /* ARRIBO_H */