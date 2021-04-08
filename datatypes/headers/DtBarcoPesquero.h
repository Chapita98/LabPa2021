#ifndef DTBARCOPESQUERO_H
#define DTBARCOPESQUERO_H
#include <string>
#include <iostream>
#include "DtBarco.h"

class DtBarcoPesquero : public DtBarco
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
    //void print(std::ostream&);
};

#endif /* BARCOPESQUERO_H */
