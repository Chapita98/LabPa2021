#ifndef ARRIBO_H
#define ARRIBO_H
/* Aca van las funciones que van a usar atributos*/
#include "./../../datatypes/headers/DtFecha.h"

class Arribo
{
private:
    DtFecha fechaDeArribo;
    float carga; // Puede ser negativa

public:
    // Constructor
    Arribo(DtFecha fechaDeArribo, float carga);

    // Getters
    DtFecha getFechaDeArribo();
    float getCarga();

    // Setters
    void setFechaDeArribo(DtFecha paramFechaDeArribo);
    void setCarga(float paramCarga);

    // Metodos
    void ingresarArribo();

    virtual ~Arribo();
};

#endif /* ARRIBO_H */