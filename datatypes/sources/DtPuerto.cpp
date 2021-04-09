#include "../headers/DtPuerto.h"
#include <string>

DtPuerto::DtPuerto() {}
DtPuerto::DtPuerto(std::string _id, std::string _nombre, DtFecha _fechaCreacion, int _cantArribos) //: fechaCreacion(_fechaCreacion)
{
    this->id = _id;
    this->nombre = _nombre;
    this->fechaCreacion = _fechaCreacion;
    this->cantArribos = _cantArribos;
}

std::string DtPuerto::getId()
{
    return this->id;
}

std::string DtPuerto::getNombre()
{
    return this->nombre;
}

DtFecha DtPuerto::getFechaCreacion()
{
    return this->fechaCreacion;
}

int DtPuerto::getCantArribos()
{
    return this->cantArribos;
}


DtPuerto::~DtPuerto()
{
}

//Overload de <<
/*std::ostream &operator<<(std::ostream &o, DtPuerto *dtP)
{
    o << std::string("Id: ") << std::to_string(dtP->getId()) << std::string("\n");
    o << std::string("Nombre: ") << dtP->getNombre() << std::string("\n");
    o << std::string("Fecha: ") << std::to_string(dtP->getFechaCreacion()) << std::string("\n");
    return o;
}*/
