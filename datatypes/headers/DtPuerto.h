#ifndef DTPUERTO_H
#define DTPUERTO_H
#include <string>

class DtPuerto {
    private:
        std::string id; 
        std::string nombre;
        DtFecha fechaCreacion; 
        int cantArribos;
        bool isValid();

    public:
        DtPuerto(std::string id, std::string nombre, DtFecha fechaCreacion, int cantArribos);

        std::string getId() const;
        std::string getNombre() const;
        DtFecha getFechaCreacion() const;
        int getCantArribos() const;
        bool operator<(DtPuerto);
        void agregarPuerto(std::string id, std::string nombre);
        Puerto *obtenerIdPuerto(std::string paramId);
        virtual ~DtPuerto();
};

#endif /* PUERTO_H */
