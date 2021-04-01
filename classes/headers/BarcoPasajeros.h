#ifndef BARCOPASAJEROS_H
#define BARCOPASAJEROS_H

//#include <string>

class BarcoPasajeros : public Barco {
	
	public:
	    enum TipoTamanio {
	    	bote,
	    	crucero,
	    	galeon,
	    	transatlantico
            };
	    BarcoPasajeros(int cantPasajeros,TipoTamanio Tamanio);

	    int getcantPasajeros() const;
	    BarcoPasajeros::TipoTamanio getTamanio() const;

 	    void setcantPasajeros(int cantPasajeros);
	    void setTamanio(BarcoPasajeros::TipoTamanio Tamanio);

	    virtual ~BarcoPasajeros();
	    //virtual Arribar(float cargaDespacho) override;

	private:
		int cantPasajeros;
		BarcoPasajeros:: TipoTamanio Tamanio;
		


	
};

#endif /* BARCOPASAJEROS_H */
