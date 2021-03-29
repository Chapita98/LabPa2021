#ifndef DTARRIBO_H
#define DTARRIBO_H
/* Esto es nada mas para estructura */
#include "../../datatypes/headers/DtFecha.h"
#include "../../datatypes/headers/DtBarco.h"

class DtArribo
{
private:
    DtBarco barcoQueArriba;
    DtFecha fechaDeArribo;
    float cantidadDespachada;

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

    virtual ~DtArribo();
};

#endif /* DTARRIBO_H */
