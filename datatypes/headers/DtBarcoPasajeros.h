#ifndef DTBARCOPASAJEROS_H
#define DTBARCOPASAJEROS_H

class DtBarcoPasajeros {
    public:
        enum TipoTamanio {
	    	bote,
	    	crucero,
	    	galeon,
	    	transatlantico
        };
        DtBarcoPasajeros(int cantPasajeros, TipoTamanio tamanio);

        int getcantPasajeros();
	auto getTamanio();

 	void setcantPasajeros(int cantPasajeros);
	void setTamanio(TipoTamanio Tamanio);

        virtual ~DtBarcoPasajeros();

    private:
            int cantPasajeros;
            TipoTamanio Tamanio;

};
#endif /* BARCOPASAJEROS_H */


