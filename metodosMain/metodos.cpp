#include "./Definiciones.h"

const int MAX_PUERTOS = 30;
const int MAX_BARCOS = 30;
Puerto **puertos = new Puerto *[MAX_PUERTOS];
int cantidadPuertos = 0;
Barco **barcos = new Barco *[MAX_BARCOS];
int cantidadBarcos = 0;

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
        std::cout << "Ingrese en orden el nombre, genero, peso, raza y si esta vacunada la mascota (Si/No): ";
        std::cin >> nombreMascota >> generoMascota >> pesoMascota >> raza >> vacuna;

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
        std::cout << "Ingrese en orden el nombre, genero, peso, y su tipo de pelo: ";
        std::cin >> nombreMascota >> generoMascota >> pesoMascota >> tipoPelo;

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
    colorAlTexto();
    std::cout << "\n\e[1;92m1)\e[0m Agregar Puerto.\n";
    std::cout << "\e[1;92m2)\e[0m Agregar Barco.\n";
    std::cout << "\e[1;92m3)\e[0m Listar Puertos.\n";
    std::cout << "\e[1;92m4)\e[0m Agregar Arribo.\n";
    std::cout << "\e[1;92m5)\e[0m Obtener Informacion de Arribos en Puerto.\n";
    std::cout << "\e[1;92m6)\e[0m Eliminar Arribos.\n";
    std::cout << "\e[1;92m7)\e[0m Listar Barcos.\n";
    std::cout << "Pulse \e[1;92m0\e[0m para salir.\n";
}

void colorAlTexto()
{
    std::cout << "\e[1;92mBienvenido. Elija una opción\e[0m:";
}

void menuCaso1()
{
    std::string id, nombre; //nota: agregar fecha de creacion al entrar al void.
    std::cout << "Ingrese en orden ci y nombre: ";
    std::cin >> id >> nombre;
    //const DtPuerto* puerto = crearDtPuerto();
    //crearDtPuerto se podria hacer sobreescribiendo el crearDtMascota que deje abajo del todo
    agregarPuerto(id, nombre); // + const DtFecha fechaCreacion
}

void menuCaso2()
{
    std::string nombre, id;
    std::cout << "Ingrese el nombre e id del barco: ";
    std::cin >> nombre >> id;
    agregarBarco(nombre, id);
}

void menuCaso4()
{
    //void agregarArribo(string idPuerto, string idBarco, float cargaDespacho)
    std::string idPuerto;
    std::string idBarco;
    float carga;
    bool flag = true;
    int dia, mes, anio;
    obtenerFechaDelSitema(dia, mes, anio);

    while (flag == true)
    {
        try
        {
            std::cout << "\nEscriba el id de Puerto: ";
            std::cin >> idPuerto;
            if (obtenerIdPuerto(idPuerto) == NULL)
                throw std::invalid_argument("\n\e[0;31mNo existe un Puerto con esa id\e[0m");

            std::cout << "\nEscriba el id de Barco: ";
            std::cin >> idBarco;
            if (obtenerIdBarco(idBarco) == NULL)
                throw std::invalid_argument("\n\e[0;31mNo existe un Barco con esa id\e[0m");

            std::cout << "\nEscriba la carga: ";
            std::cin >> carga;
            if (carga <= 0 || carga >= 100) // TODO ver las cantidades
                throw std::invalid_argument("\n\e[0;31mLa cantidad de carga es incorrecta\e[0m");

            Arribo arribo = new Arribo(carga); // TODO ver que agregar
            /* Ejemplo de uso de fecha
                usuarios[cantidadUsuarios] = new Usuario(nombre, cedula, DtFecha(dia, mes, anio));
            */
            std::cout << "\nArribo añadido con exito\n";
            flag = false;
        }
        catch (std::invalid_argument &e)
        {
            cerr << e.what() << endl;
            std::cout << "\nVolviendo al menu principal\n";
            flag = false;
            break;
        }
    }
}

Puerto *obtenerIdPuerto(std::string paramId) // TODO revisar los atributos y poner en .h
{
    for (int i = 0; i < cantidadPuertos; i++)
    {
        if (puerto[i]->getId() == paramId)
        {
            return puerto[i];
        }
    }
    return NULL;
}

Barco *obtenerIdBarco(std::string paramId) // TODO revisar los atributos y poner en .h
{
    for (int i = 0; i < cantidadBarco; i++)
    {
        if (barco[i]->getId() == paramId)
        {
            return barco[i];
        }
    }
    return NULL;
}

void obtenerFechaDelSitema(int &dia, int &mes, int &anio)
{
    std::time_t t = std::time(0); // get time now
    std::tm *now = std::localtime(&t);
    anio = (now->tm_year + 1900);
    mes = (now->tm_mon + 1);
    dia = now->tm_mday;
}

void agregarBarco(DtBarco barco, Barco barcos[]){
    int tamanio = sizeof(barcos)/sizeof(barcos[0]);
    int i=0;
   while (true){
        if(barco.getId()==barcos[i].getId()){
            throw std::invalid_argument("Ya existe un puerto con la misma id ingresada");
            break;


        }
        else if(i==tamanio){
                std::string id=barco.getId();
                    std::string nombre=barco.getNombre();
                if(i==0){
                    barcos[i] = Barco(nombre, id);
                }
                else{
                    barcos[i++] = Barco(nombre, id);
                }
                i++;
                break;
        }
        i++;
    }
}
