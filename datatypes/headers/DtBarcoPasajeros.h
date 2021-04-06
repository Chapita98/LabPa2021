#ifndef DTBARCOPASAJEROS_H
#define DTBARCOPASAJEROS_H

class DtBarcoPasajeros
{
private:
    enum TipoTamanio
    {
        BOTE,
        CRUCERO,
        GALEON,
        TRANSATLANTICO
    };
    int cantPasajeros;
    TipoTamanio Tamanio;

public:
    DtBarcoPasajeros(int cantPasajeros, TipoTamanio tamanio);

    int getcantPasajeros();
    auto getTamanio();

    void setcantPasajeros(int cantPasajeros);
    void setTamanio(TipoTamanio Tamanio);

    virtual ~DtBarcoPasajeros();
};
#endif /* BARCOPASAJEROS_H */
