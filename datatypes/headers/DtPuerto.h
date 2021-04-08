#ifndef DTPUERTO_H
#define DTPUERTO_H
#include <string>
#include "./DtFecha.h"

class DtPuerto
{
private:
    std::string id;
    std::string nombre;
    DtFecha fechaCreacion;
    int cantArribos;
    bool isValid();

public:
    DtPuerto();
    DtPuerto(std::string id, std::string nombre, DtFecha fechaCreacion, int cantArribos);

    std::string getId();
    std::string getNombre();
    DtFecha getFechaCreacion();
    int getCantArribos();

    void setId(std::string id);
    void setNombre(std::string nombre);
    void setFechaCreacion(std::string fechaCreacion);
    void setCantArribos(std::string cantArribos);

    bool operator<(DtPuerto);
    void agregarPuerto(std::string id, std::string nombre);
    DtPuerto *obtenerIdPuerto(std::string paramId);
    virtual ~DtPuerto();
};

#endif /* PUERTO_H */
