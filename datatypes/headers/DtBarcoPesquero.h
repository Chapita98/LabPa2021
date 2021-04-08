#ifndef DTBARCOPESQUERO_H
#define DTBARCOPESQUERO_H
#include <string>

class DtBarcoPesquero
{
private:
    int capacidad;
    int carga;
    bool isValid();

public:
    DtBarcoPesquero();
    DtBarcoPesquero(int capacidad, int carga);
    DtBarcoPesquero(int capacidad, int carga, std::string id, std::string nombre);

    int getCapacidad();
    int getCarga();

    void setCapacidad(int capacidad);
    void setCarga(int carga);
    bool operator<(DtBarcoPesquero);

    virtual ~DtBarcoPesquero();
};

#endif /* BARCOPESQUERO_H */
