#ifndef BARCO_H
#define BARCO_H

#include <string>

class Barco
{
protected:
	std::string Nombre;
	std::string Id;

public:
	Barco(std::string nombre, std::string id);

	std::string getNombre() const;
	std::string getId() const;

	void setNombre(std::string nombre);
	void setId(std::string id);

	virtual ~Barco();
	//virtual void Arribar(float cargaDespacho);
};

#endif /* BARCO_H */
