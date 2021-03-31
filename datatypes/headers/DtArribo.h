#ifndef DTARRIBO_H
#define DTARRIBO_H
/* Esto es nada mas para estructura */
#include "./DtFecha.h"
#include "./DtBarco.h"

class DtArribo
{
private:
    DtBarco barcoQueArriba;
    DtFecha fechaDeArribo;
    float carga;

public:
    // Constructor
    DtArribo(DtBarco barcoQueArriba, DtFecha fechaDeArribo, float carga);

    // Getters
    DtBarco getBarcoQueArriba();
    DtFecha getFechaDeArribo();
    float getCarga();

    // Setters
    void setBarcoQueArriba(DtBarco paramBarcoQueArriba);
    void setFechaDeArribo(DtFecha paramFechaDeArribo);
    void setCarga(float paramCarga);

    virtual ~DtArribo();
};

#endif /* DTARRIBO_H */
