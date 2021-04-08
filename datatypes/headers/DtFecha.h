#ifndef DTFECHA_H
#define DTFECHA_H
#include <iostream>

class DtFecha
{
private:
    int dia;
    int mes;
    int anio;
    bool isValid();

public:
    DtFecha();
    DtFecha(int dia, int mes, int anio);
    int getDia();
    int getMes();
    int getAnio();
    void setDia(int dia);
    void setMes(int mes);
    void setAnio(int anio);
    bool operator==(const DtFecha &df) const;
    bool operator<(const DtFecha &df) const;
    virtual ~DtFecha();
};

#endif
