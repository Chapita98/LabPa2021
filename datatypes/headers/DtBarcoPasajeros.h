#ifndef DTBARCOPASAJEROS_H
#define DTBARCOPASAJEROS_H
#include "./../../classes/headers/TipoTamanio.h"
#include "DtBarco.h"

class DtBarcoPasajeros : public DtBarco
{
private:
    int cantPasajeros;
    TipoTamanio tamanio;

public:
    DtBarcoPasajeros();
    DtBarcoPasajeros(int _cantPasajeros, TipoTamanio _tamanio);
    DtBarcoPasajeros(int _cantPasajeros, TipoTamanio _tamanio, std::string _id, std::string _nombre);

    int getCantPasajeros();
    TipoTamanio getTamanio();

    void setCantPasajeros(int _cantPasajeros);
    void setTamanio(TipoTamanio _tamanio);

    virtual ~DtBarcoPasajeros();
};
#endif /* BARCOPASAJEROS_H */
