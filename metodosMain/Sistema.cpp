#include "Sistema.h"

Sistema::Sistema(){}

void Sistema::agregarBarco(DtBarco *barco)
{
   int i=0;
   while (true)
   {
        if(barco->getId()==this->barcos[i].getId())
        {
            throw std::invalid_argument("Ya existe un barco con la misma id ingresada"); //se rompe todo cuando tira esto
            return;

        }
        else if(i==this->cantBarcos)
        {
                if (dynamic_cast<DtBarcoPasajeros*>(barco))
                {
                    DtBarcoPasajeros* b = dynamic_cast<DtBarcoPasajeros*>(barco);
                    if(i==0)
                    {

                        this->barcos[i] = BarcoPasajeros (b->getcantPasajeros(), b->getTamanio(), b->getNombre(), b->getId());
                    }
                    else
                    {
                        this->barcos[i++] = BarcoPasajeros(b->getcantPasajeros(), b->getTamanio(), b->getNombre(), b->getId());
                    }
                    i++;
                    break;
                }
                else
                {
                    DtBarcoPesquero* b = dynamic_cast<DtBarcoPesquero*>(barco);
                    if(i==0)
                    {
                        this->barcos[i] = BarcoPesquero(b->getCapacidad(), b->getCarga(), b->getNombre(), b->getId());
                    }
                    else
                    {
                        this->barcos[i++] = BarcoPesquero(b->getCapacidad(), b->getCarga(), b->getNombre(), b->getId());
                    }
                    i++;
                    break;
                }

        }
        i++;
    }
}
