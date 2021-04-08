#ifndef DTBARCO_H
#define DTBARCO_H
#include <string>

class DtBarco
{
private:
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
};

#endif /* BARCO_H */
