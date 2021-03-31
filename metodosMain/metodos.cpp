#include "Definiciones.h"

Puerto *obtenerPuerto(std::string id)
{
    for (int i = 0; i < cantidadPuertos; i++)
    {
        if (puertos[i]->getId() == id)
        {
            return puertos[i];
        }
    }
    return NULL;
}

void agregarPuerto(std::string id, std::string nombre, const DtFecha &fechaCreacion)
{

    Puerto *puerto = obtenerPuerto(id);

    if (puerto != NULL)
    {
        throw std::invalid_argument("Ya existe un puerto con la misma id ingresada");
    }
    std::time_t t = std::time(0);      // Obtener tiempo actual
    std::tm *now = std::localtime(&t); //

    puertos[cantidadPuertos] = new Puerto(id, nombre, DtFecha(now->tm_mday, now->tm_mon + 1, now->tm_year + 1900)); //Agregar dia, mes y anio actuales a DtFecha
    puertos[cantidadPuertos]->agregarPuerto();
    cantidadPuertos++;
}

//queda a modo de ejemplo para eliminar
void eliminarSocio(std::string ci)
{
    Socio *socio = obtenerSocio(ci);
    if (socio == NULL)
    {
        throw std::invalid_argument("No existe el socio que quiere eliminar");
    }
    delete socio;
    std::cout << "El Socio se ha eliminado efectivamente" << '\n';
}

//queda a modo de ejemplo para listar puertos y barcos
DtMascota **obtenerMascotas(std::string ci, int &cantMascotas)
{
    Socio *socio = obtenerSocio(ci);

    if (socio == NULL)
    {
        throw std::invalid_argument("No existe un socio con la ci ingresada");
    }

    DtMascota **retornoMascota = new DtMascota *[cantMascotas];
    Mascota **mascotasSocio = socio->getMascota();

    if (socio->getCantidadMascotas() < cantMascotas)
    {
        cantMascotas = socio->getCantidadMascotas();
    }
    int j = 0;
    for (int i = 0; i < socio->getCantidadMascotas() && j < cantMascotas; i++)
    {

        Perro *p = dynamic_cast<Perro *>(mascotasSocio[i]);
        if (p)
        {
            retornoMascota[j] = new DtPerro(
                p->getRaza(),
                p->getVacunaCachorro(),
                p->getNombre(),
                p->getGenero(),
                p->getPeso());
        }
        else
        {
            auto g = (DtGato *)mascotasSocio[i];
            retornoMascota[j] = new DtGato(
                g->getPelo(),
                g->getNombre(),
                g->getGenero(),
                g->getPeso());
        }
        j++;
    }

    return retornoMascota;
}

//queda a modo de ejemplo para crear los otros dt
//Auxiliares
DtMascota *crearDtMascota(std::string tipoMascota)
{
    std::string nombreMascota, generoMascota;
    float pesoMascota;

    DtMascota *mascota;
    if (tipoMascota == "Perro")
    {
        std::string raza, vacuna;
        cout << "Ingrese en orden el nombre, genero, peso, raza y si esta vacunada la mascota (Si/No): ";
        cin >> nombreMascota >> generoMascota >> pesoMascota >> raza >> vacuna;

        Genero genero;
        if (generoMascota == "Macho")
        {
            genero = Genero::Macho;
        }
        else
        {
            genero = Genero::Hembra;
        }

        RazaPerro razaPerro;
        if (raza == "Labrador")
        {
            razaPerro = RazaPerro::Labrador;
        }
        else
        {
            if (raza == "Ovejero")
            {
                razaPerro = RazaPerro::Ovejero;
            }
            else
            {
                if (raza == "Bulldog")
                {
                    razaPerro = RazaPerro::Bulldog;
                }
                else
                {
                    if (raza == "Collie")
                    {
                        razaPerro = RazaPerro::Collie;
                    }
                    else
                    {
                        if (raza == "Pekines")
                        {
                            razaPerro = RazaPerro::Pekines;
                        }
                        else
                        {
                            if (raza == "Otro")
                            {
                                razaPerro = RazaPerro::Otro;
                            }
                        }
                    }
                }
            }
        }

        bool vacunabool = false;
        if (vacuna == "Si")
        {
            vacunabool = true;
        }

        mascota = new DtPerro(razaPerro, vacunabool, nombreMascota, genero, pesoMascota);
    }
    else
    {
        std::string tipoPelo, vacuna;
        cout << "Ingrese en orden el nombre, genero, peso, y su tipo de pelo: ";
        cin >> nombreMascota >> generoMascota >> pesoMascota >> tipoPelo;

        Genero genero;
        if (generoMascota == "Macho")
        {
            genero = Genero::Macho;
        }
        else
        {
            genero = Genero::Hembra;
        }

        TipoPelo pelo;

        if (tipoPelo == "Corto")
        {
            pelo = TipoPelo::Corto;
        }
        else
        {
            if (tipoPelo == "Mediano")
            {
                pelo = TipoPelo::Mediano;
            }
            else
            {
                if (tipoPelo == "Largo")
                {
                    pelo = TipoPelo::Largo;
                }
            }
        }

        mascota = new DtGato(pelo, nombreMascota, genero, pesoMascota);
    }

    return mascota;
}

void imprimirTextoPrincipal()
{
    cout << "1) Agregar Puerto.\n";
    cout << "2) Agregar Barco.\n";
    cout << "3) Listar Puertos.\n";
    cout << "4) Agregar Arribo.\n";
    cout << "5) Obtener Informacion de Arribos en Puerto.\n";
    cout << "6) Eliminar Arribos.\n";
    cout << "7) Listar Barcos.\n";
    cout << "Pulse 0 para salir.\n";
}

void colorAlTexto()
{
    cout << "\e[1;92mBienvenido. Elija la opción\e[0m:";
}

void menuCaso4() // TODO Hacer las funciones de obtener id puerto / barco
{
    //void agregarArribo(string idPuerto, string idBarco, float cargaDespacho)
    std::string idPuerto;
    std::string idBarco;
    float carga;
    bool flag = true;

    while (flag == true)
    {
        std::cout << "Escriba el id de Puerto: ";
        std::cin >> idPuerto;
        try
        {
            if (obtenerIdPuerto(idPuerto) == NULL)
                throw std::invalid_argument("No existe un Puerto con esa id");
            else
            {
                // TODO agregar
                flag = false;
            }
        }
        catch (invalid_argument &e)
        {
            cerr << e.what() << endl;
            break;
        }

        std::cout << "Escriba el id de Barco: ";
        std::cin >> idBarco;
        try
        {
            if (obtenerIdBarco(idBarco) == NULL)
                throw std::invalid_argument("No existe un Barco con esa id");
            else
            {
                // TODO agregar
                flag = false;
            }
        }
        catch (invalid_argument &e)
        {
            cerr << e.what() << endl;
            break;
        }

        std::cout << "Escriba la carga: ";
        std::cin >> carga;
        try
        {
            if (carga <= 0 || carga >= 100) // TODO ver las cantidades
                throw std::invalid_argument("La cantidad de carga es incorrecta");
            else
            {
                Arribo arribo = new Arribo(carga);
                flag = false;
            }
        }
        catch (invalid_argument &e)
        {
            cerr << e.what() << endl;
            break;
        }
    }
    std::cout << "\nArribo añadido con exito\n";
}

Puerto *obtenerIdPuerto(std::string idPuerto) // TODO revisar los atributos y poner en .h
{
    for (int i = 0; i < cantidadPuertos; i++)
    {
        if (puerto[i]->getId() == id)
        {
            return puerto[i];
        }
    }
    return NULL;
}