#ifndef DTARRIBO_H
#define DTARRIBO_H
/* Esto es nada mas para estructura */
#include "DtFecha.h"
#include "DtBarco.h"

class DtArribo
{
private:
    DtBarco barcoQueArriba;
    DtFecha fechaDeArribo;
    float cargaDespachada;

public:
    // Constructor
    DtArribo(DtBarco barcoQueArriba, DtFecha fechaDeArribo, float cargaDespachada);

    // Getters
    DtBarco getBarcoQueArriba();
    DtFecha getFechaDeArribo();
    float getCargaDespachada();

    // Setters
    void setBarcoQueArriba(DtBarco paramBarcoQueArriba);
    void setFechaDeArribo(DtFecha paramFechaDeArribo);
    void setCargaDespachada(float paramCargaDespachada);

    virtual ~DtArribo();
};

#endif /* DTARRIBO_H */
