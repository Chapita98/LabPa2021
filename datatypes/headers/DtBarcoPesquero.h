#ifndef DTBARCOPESQUERO_H
#define DTBARCOPESQUERO_H

class DtBarcoPesquero
{
private:
    int capacidad;
    int carga;
    bool isValid();

public:
    DtBarcoPesquero(int capacidad, int carga);

    int getCapacidad() const;
    int getCarga() const;
    bool operator<(DtBarcoPesquero);

    virtual ~DtBarcoPesquero();
};

#endif /* BARCOPESQUERO_H */
