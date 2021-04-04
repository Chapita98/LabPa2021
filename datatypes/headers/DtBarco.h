#ifndef DTBARCO_H
#define DTBARCO_H

class DtBarco {
    private:
        std::string Nombre;
        std::string Id;
        bool isValid();

    public:
        DtBarco(std::string nombre, std::string id);

        std::string getNombre() const;
        std::string getId() const;
        bool operator<(DtBarco);
        void setId(std::string id);
        void setNombre(std::string nombre);

        virtual ~DtBarco();
};



#endif /* BARCO_H */
