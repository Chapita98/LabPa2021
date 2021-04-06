#ifndef BARCOPASAJEROS_H
#define BARCOPASAJEROS_H

class BarcoPasajeros : public Barco
{
private:
	enum TipoTamanio
	{
		BOTE,
		CRUCERO,
		GALEON,
		TRANSATLANTICO
	};
	int cantPasajeros;
	TipoTamanio Tamanio;

public:
	BarcoPasajeros(int cantPasajeros, TipoTamanio Tamanio);
	BarcoPasajeros(int cantpasajeros, TipoTamanio tamanio, std::string nombre, std::string id);

	int getcantPasajeros() const;
	TipoTamanio getTamanio() const;

	void setcantPasajeros(int cantPasajeros);
	void setTamanio(TipoTamanio Tamanio);

	virtual ~BarcoPasajeros();
	//virtual Arribar(float cargaDespacho) override;
};

#endif /* BARCOPASAJEROS_H */
