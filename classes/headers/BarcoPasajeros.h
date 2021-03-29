#ifndef BARCOPASAJEROS_H
#define BARCOPASAJEROS_H

//#include <string>

#include "../../datatypes/headers/TipoTamanio.h"

class BarcoPasajeros : Barco {
	public:
	    BarcoPasajeros();
		BarcoPasajeros(int cantPasajeros, const TipoTamanio & Tamanio);

		int getcantPasajeros() const;
		TipoTamanio getTamanio() const;
		void setcantPasajeros(int cantPasajeros);
		//TipoTamanio setTamanio(); ?????

		virtual ~BarcoPasajeros();
		virtual Arribar(float cargaDespacho) override;

	private:
		int cantPasajeros;
		TipoTamanio Tamanio;

};

#endif /* SOCIO_H */
