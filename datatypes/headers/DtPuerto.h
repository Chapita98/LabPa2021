#ifndef DTPUERTO_H
#define DTPUERTO_H
#include <string>

class DtPuerto {
    private:
        string id; 
        string nombre;
        DtFecha fechaCreacion; 
        int cantArribos;
        bool isValid();

    public:
        DtPuerto(string id, string nombre, DtFecha fechaCreacion, int cantArribos);

        int getId() const;
        string getNombre() const;
        DtFecha getfechaCreacion() const;
        int getCantArribos() const;
        bool operator<(DtPuerto);
        void agregarPuerto(std::string id, std::string nombre);

        virtual ~DtPuerto();
};

#endif /* PUERTO_H */
