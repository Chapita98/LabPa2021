#ifndef TIPOTAMANIO_H
#define TIPOTAMANIO_H

class TipoTamanio {
    private:
        string bote;
        string crucero;
        string galeon;
        string transatlantico;
        bool isValid();

    public:
        TipoTamanio(string bote, string crucero, string galeon, string transatlantico);

        int getBote() const;
        int getCrucero() const;
        int getGaleon() const;
        int getTransAtlantico() const;
        bool operator<(TipoTamanio);
        
        virtual ~TipoTamanio();
};

#endif /* TIPOTAMANIO_H */
