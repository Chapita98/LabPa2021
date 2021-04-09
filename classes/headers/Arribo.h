#ifndef ARRIBO_H
#define ARRIBO_H
#include "./../../datatypes/headers/DtFecha.h"
#include "./Barco.h"

class Arribo
{
private:
    DtFecha fechaDeArribo;
    float carga;
    Barco *barco;

public:
    // Constructor
    Arribo();
    Arribo(DtFecha fechaDeArribo, float carga, Barco &barco);

    // Getters
    DtFecha getFechaDeArribo();
    float getCarga();

    // Setters
    void setFechaDeArribo(DtFecha &paramFechaDeArribo);
    void setCarga(float paramCarga);

    // Metodos
    void ingresarArribo();

    virtual ~Arribo();
};

#endif /* ARRIBO_H */
