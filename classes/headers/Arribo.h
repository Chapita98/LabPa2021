#ifndef ARRIBO_H
#define ARRIBO_H

#include "../../datatypes/headers/DtFecha.h"

class Arribo {
public:
  Arribo(float carga, DtFecha fecha);
  DtFecha getFecha();
};

#endif /* ARRIBO_H */
