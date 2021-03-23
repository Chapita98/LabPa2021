#ifndef DTBARCO_H
#define DTBARCO_H

class DtBarco {
    private:
        string nombre;
        string id;
        bool isValid();

    public:
        DtBarco(string nombre, string id);

        int getNombre() const;
        int getId() const;
        bool operator<(DtBarco);
        
        virtual ~DtBarco();
};

#endif /* BARCO_H */
