#ifndef DTBARCOPASAJEROS_H
#define DTBARCOPASAJEROS_H
#include "./../../classes/headers/TipoTamanio.h"

class DtBarcoPasajeros
{
private:
    int cantPasajeros;
    TipoTamanio tamanio;

public:
    DtBarcoPasajeros();
    DtBarcoPasajeros(int _cantPasajeros, TipoTamanio _tamanio);

    int getCantPasajeros();
    auto getTamanio();

    void setCantPasajeros(int _cantPasajeros);
    void setTamanio(TipoTamanio _tamanio);

    virtual ~DtBarcoPasajeros();
};
#endif /* BARCOPASAJEROS_H */
