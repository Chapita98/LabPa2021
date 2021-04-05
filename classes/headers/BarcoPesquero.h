#ifndef BARCOPESQUERO_H
#define BARCOPESQUERO_H

class BarcoPesquero : public Barco
{
private:
	int Capacidad;
	int Carga;

public:
	BarcoPesquero(int capacidad, int carga);

	int getCapacidad() const;
	int getCarga() const;

	void setCapacidad(int capacidad);
	void setCarga(int carga);

	virtual ~BarcoPesquero();
	//virtual void Arribar(float cargaDespacho) override;
};

#endif /* BARCOPESQUERO_H */
