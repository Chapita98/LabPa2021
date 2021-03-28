#ifndef DTARRIBO_H
#define DTARRIBO_H

class DtArribo{
    private:
        DtBarco barcoQueArriba;
        DtFecha fechaDeArribo;
        float cantidadDespachada;

    public:
        DtArribo(DtBarco barcoQueArriba, DtFecha fechaDeArribo, float cantidadDespachada);

        DtBarco barcoQueArriba() const;
        DtFecha fechaDeArribo() const;
        float cantidadDespachada() const;

        virtual ~DtArribo();
};

#endif /* ARRIBO_H */
