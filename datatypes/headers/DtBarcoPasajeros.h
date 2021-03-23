#ifndef DTBARCOPASAJEROS_H
#define DTBARCOPASAJEROS_H

class DtBarcoPasajeros {
    private:
        int cantPasajeros;
        TipoTamanio tamanio;
        bool isValid();

    public:
        DtBarcoPasajeros(int cantPasajeros, TipoTamanio tamanio);

        int getCantPasajeros() const;
        int getTamanio() const;
        bool operator<(DtBarcoPasajeros);
        
        virtual ~DtBarcoPasajeros();
};

#endif /* BARCOPASAJEROS_H */
