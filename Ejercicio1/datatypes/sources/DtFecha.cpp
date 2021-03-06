#include "../headers/DtFecha.h"
DtFecha::DtFecha() {}

DtFecha::DtFecha(int dia, int mes, int anio)
{
	this->dia = dia;
	this->mes = mes;
	this->anio = anio;
}

// ------- Getters ------ //
int DtFecha::getDia()
{
	return this->dia;
}

int DtFecha::getMes()
{
	return this->mes;
}

int DtFecha::getAnio()
{
	return this->anio;
}

bool DtFecha::operator==(const DtFecha &dtfecha) const
{
	int suma_fecha1 = this->anio + this->mes * 100 + this->dia;
	int suma_fecha2 = dtfecha.anio + dtfecha.mes * 100 + dtfecha.dia;
	return (suma_fecha1 == suma_fecha2);
}

bool DtFecha::operator<(const DtFecha &dtfecha) const
{
	int suma_fecha1 = this->anio + this->mes * 100 + this->dia;
	int suma_fecha2 = dtfecha.anio + dtfecha.mes * 100 + dtfecha.dia;
	return (suma_fecha1 < suma_fecha2);
}

DtFecha::~DtFecha()
{
}
