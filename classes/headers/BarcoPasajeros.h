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
	    BarcoPasajeros(int cantPasajeros, TipoTamanio Tamanio);
	    BarcoPasajeros(int cantpasajeros, TipoTamanio tamanio, std::string nombre, std::string id);

	    int getcantPasajeros() const;
	    TipoTamanio getTamanio() const;

 	    void setcantPasajeros(int cantPasajeros);
	    void setTamanio(TipoTamanio Tamanio);

	    virtual ~BarcoPasajeros();
	    //virtual Arribar(float cargaDespacho) override;

	private:
		int cantPasajeros;
		TipoTamanio Tamanio;
		


	
};

#endif /* BARCOPASAJEROS_H */
