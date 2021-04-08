#include "Sistema.h"

Sistema::Sistema() {}

int Sistema::getcantBarcos()
{
    return this->cantBarcos;
}
int Sistema::getcantPuertos()
{
    return this->cantPuertos;
}
void Sistema::setcantBarcos(int cantbarcos)
{
    this->cantBarcos = cantbarcos;
}
void Sistema::setcantPuertos(int cantpuertos)
{
    this->cantPuertos = cantpuertos;
}
void Sistema::agregarBarco(DtBarco *barco)
{
    int i = 0;
    while (true)
    {
        if (barco->getId() == this->barcos[i].getId())
        {
            throw std::invalid_argument("Ya existe un barco con la misma id ingresada"); //se rompe todo cuando tira esto
            return;
        }
        else if (i == this->cantBarcos)
        {
            if (dynamic_cast<DtBarcoPasajeros *>(barco))
            {
                DtBarcoPasajeros *b = dynamic_cast<DtBarcoPasajeros *>(barco);
                if (i == 0)
                {

                    this->barcos[i] = BarcoPasajeros(b->getcantPasajeros(), b->getTamanio(), b->getNombre(), b->getId());
                    this->cantBarcos++;
                }
                else
                {
                    this->barcos[i++] = BarcoPasajeros(b->getcantPasajeros(), b->getTamanio(), b->getNombre(), b->getId());
                    this->cantBarcos++;
                }
                i++;
                break;
            }
            else
            {
                DtBarcoPesquero *b = dynamic_cast<DtBarcoPesquero *>(barco);
                if (i == 0)
                {
                    this->barcos[i] = BarcoPesquero(b->getCapacidad(), b->getCarga(), b->getNombre(), b->getId());
                    this->cantBarcos++;
                }
                else
                {
                    this->barcos[i++] = BarcoPesquero(b->getCapacidad(), b->getCarga(), b->getNombre(), b->getId());
                    this->cantBarcos++;
                }
                i++;
                break;
            }
        }
        i++;
    }
}
DtBarco *Sistema::listarBarcos()
{
    DtBarco *dtbarcos = new DtBarco[this->cantBarcos];
    for (int i = 0; i < this->cantBarcos; i++)
    {
        if (!this->barcos[i].getId().empty()) ///controlar que cantBarcos sea diferente de 0 afuera
        {
            BarcoPasajeros *b = (dynamic_cast<BarcoPasajeros *>(&this->barcos[i]));
            if (b)
            {
                dtbarcos[i] = DtBarcoPasajeros(b->getcantPasajeros(), b->getTamanio(), b->getNombre(), b->getId());
            }
            else
            {
                BarcoPesquero b;
                b.Barco::operator=(this->barcos[i]);
                dtbarcos[i] = DtBarcoPesquero(b.getCapacidad(), b.getCarga(), b.getNombre(), b.getId());
            }
        }
        else
        {
            i = this->cantBarcos;
        }
    }
    return dtbarcos;
}

DtPuerto *Sistema::listarPuertos()
{
    DtPuerto *dtpuertos = new DtPuerto[this->cantPuertos];
    for (int i = 0; i < this->cantPuertos; i++)
    {

        if (!this->puertos[i].getId().empty())
        {
            dtpuertos[i] = DtPuerto(this->puertos[i].getId(), this->puertos[i].getNombre(), this->puertos[i].getFechaCrecion(), this->puertos[i].getcantArribos());
        }
        else
        {
            i = this->cantPuertos;
        }

        return dtpuertos;
    }
