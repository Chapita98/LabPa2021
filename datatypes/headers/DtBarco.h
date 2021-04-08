#ifndef DTBARCO_H
#define DTBARCO_H
#include <string>

class DtBarco
{
protected:
    std::string nombre;
    std::string id;

public:
    DtBarco();
    DtBarco(std::string _id, std::string _nombre);

    std::string getNombre();
    std::string getId();

    void setNombre(std::string _nombre);
    void setId(std::string _id);

    virtual ~DtBarco();
    //friend std::ostream& operator<<(std::ostream&, DtBarco*);
    // virtual void print(std::ostream&)=0;
};

#endif /* BARCO_H */
