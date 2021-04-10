#include "./definiciones.h"

const int MAX_PUERTOS = 30;
const int MAX_BARCOS = 30;
int cantidadPuertos = 0;
DtPuerto *dtPuertos = new DtPuerto();
//DtBarco *dtBarcos = new DtBarco();
Puerto *puertos[MAX_PUERTOS];
Barco *barcos[MAX_BARCOS];
int cantidadBarcos = 0;
int dia, mes, anio = 0;

void obtenerFechaDelSistema(int &dia, int &mes, int &anio)
{
    std::time_t t = std::time(0);
    std::tm *now = std::localtime(&t);
    anio = (now->tm_year + 1900);
    mes = (now->tm_mon + 1);
    dia = now->tm_mday;
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

void fechaAutomatica()
{
    obtenerFechaDelSistema(dia, mes, anio);
}

void menuCaso1()
{
    std::string id;
    std::string nombre;
    bool flag = true;

    while (flag == true)
    {
        try
        {
            if (cantidadPuertos >= MAX_PUERTOS)
                throw std::invalid_argument("e[0;31mLa cantidad maxima de Puertos a sido alcanzada.\e[0m");

            std::cout << "\nEscriba el id del Puerto: ";
            std::cin >> id;
            if (id == obtenerIdPuerto(id)->getId()) // Si ya existe envia error
                throw std::invalid_argument("\e[0;31mYa existe un Puerto con esa id\e[0m");

            std::cout << "\nEscriba el nombre del Puerto: ";
            std::cin >> nombre;

            agregarPuerto(id, nombre, DtFecha(dia, mes, anio));
            flag = false;
        }
        catch (std::invalid_argument &e)
        {
            std::cout << "\nError: " << e.what() << std::endl;
            std::cout << "\nVolviendo al menu principal\n\n";
            flag = false;
            break;
        }
    }
}

void menuCaso2()
{
    std::string id;
    std::string nombre;
    int tipo;
    int capacidad;
    int carga;
    int cantpas;
    int tam;
    TipoTamanio tamanio;
    bool flag = true;
    while (flag == true)
    {
        try
        {
            if (cantidadBarcos >= MAX_BARCOS)
                throw std::invalid_argument("e[0;31mLa cantidad maxima de Barcos a sido alcanzada.\e[0m");

            std::cout << "\nEscriba el id del Barco: ";
            std::cin >> id;

            if (obtenerIdBarco(id)!=NULL) // Si ya existe envia error
                throw std::invalid_argument("\e[0;31mYa existe un Barco con esa id\e[0m");

            std::cout << "\nEscriba el nombre del Barco: ";
            std::cin >> nombre;

            std::cout << "\nElija una opcion: ";
            std::cout << "\n1)Barco de Pasajeros ";
            std::cout << "\n2)Barco Pesquero ";
            std::cin >> tipo;

            switch (tipo)
            {

                case 1:
                {
                    std::cout << "\nIngrese cantidad de pasajeros: ";
                    std::cin >> cantpas;
                    std::cout << "\nElija un tamaño: ";
                    std::cout << "\n1)Bote ";
                    std::cout << "\n2)Crucero ";
                    std::cout << "\n3)Galeon ";
                    std::cout << "\n4)Transatlantico ";
                    std::cin >> tam;
                    switch(tam)
                    {
                        case BOTE:
                            tamanio= TipoTamanio::BOTE;
                            break;
                        case CRUCERO:
                            tamanio= TipoTamanio::CRUCERO;
                            break;
                        case GALEON:
                            tamanio= TipoTamanio::GALEON;
                            break;
                        case TRANSATLANTICO:
                            tamanio= TipoTamanio::TRANSATLANTICO;
                            break;
                        default:
                            throw std::invalid_argument("Ingrese tamanio valido");
                            break;
                    }
                    DtBarcoPasajeros *b= new DtBarcoPasajeros(cantpas, tamanio, id, nombre);
                    agregarBarco(b);
                    break;
                }
                case 2:
                {
                    std::cout << "\nIngrese capacidad: ";
                    std::cin >> capacidad;
                    std::cout << "\nIngrese carga: ";
                    std::cin >> carga;
                    DtBarcoPesquero *b= new DtBarcoPesquero(capacidad, carga, nombre, id);
                    agregarBarco(b);
                    break;
                }
                default:
				throw std::invalid_argument("\nLa opcion ingresada no es correcta.\n");
				break;
            }
            flag = false;
        }
        catch (std::invalid_argument &e)
        {
            std::cout << "\nError: " << e.what() << std::endl;
            std::cout << "\nVolviendo al menu principal\n\n";
            flag = false;
            break;
        }
    }
}

void menuCaso3()
{
    if (cantidadPuertos == 0)
    {
        std::cout << "No hay puertos registrados\n";
    }
    else
    {
        // TODO DtPuertos mostrarpuertos = listarPuertos(puertos, cantidadPuertos);
        for (int i = 0; i < cantidadPuertos; i++)
        {
            // std::cout << "Nombre: " << mostrarPuertos[i].getNombre() << std::endl; //o hacerlo con std::ostream
        }
    }
}

void menuCaso4()
{
    std::string idPuerto;
    std::string idBarco;
    float carga;
    bool flag = true;

    while (flag == true)
    {
        try
        {
            std::cout << "\nEscriba el id de Puerto: ";
            std::cin >> idPuerto;
            if (obtenerIdPuerto(idPuerto) == NULL)
                throw std::invalid_argument("\e[0;31mNo existe un Puerto con esa id\e[0m");

            std::cout << "\nEscriba el id de Barco: ";
            std::cin >> idBarco;
            if (obtenerIdBarco(idBarco) == NULL)
                throw std::invalid_argument("\e[0;31mNo existe un Barco con esa id\e[0m");

            std::cout << "\nEscriba la carga: ";
            std::cin >> carga;

            agregarArribo(idPuerto, idBarco, carga);
            std::cout << "\nArribo añadido con exito\n";
            flag = false;
        }
        catch (std::invalid_argument &e)
        {
            std::cout << "\nError: " << e.what() << std::endl;
            std::cout << "\nVolviendo al menu principal\n\n";
            flag = false;
            break;
        }
    }
}

void menuCaso5()
{
    std::string id;
    bool flag = true;
    while (flag == true)
    {
        try
        {
            std::cout << "\nEscriba el id del Puerto: ";
            std::cin >> id;

            if (obtenerIdPuerto(id) == NULL)
                throw std::invalid_argument("\e[0;31mNo existe un Arribo con esa id\e[0m");

            DtArribo *dtarribos= obtenerInfoArribosEnPuerto(id);

            flag = false;
        }
        catch (std::invalid_argument &e)
        {
            std::cout << "\nError: " << e.what() << std::endl;
            std::cout << "\nVolviendo al menu principal\n\n";
            flag = false;
            break;
        }
    }
}

void menuCaso6()
{
    std::string id;
    bool flag = true;
    while (flag == true)
    {
        try
        {
            std::cout << "\nEscriba el id del Arribo: ";
            std::cin >> id;

            if (obtenerIdBarco(id) == NULL)
                throw std::invalid_argument("\e[0;31mNo existe un Arribo con esa id\e[0m");

            eliminarArribo(id, DtFecha(dia, mes, anio));
            flag = false;
        }
        catch (std::invalid_argument &e)
        {
            std::cout << "\nError: " << e.what() << std::endl;
            std::cout << "\nVolviendo al menu principal\n\n";
            flag = false;
            break;
        }
    }
}

void menuCaso7()
{
    if (barcos == 0)
    {
        std::cout << "No hay Barcos registrados\n";
    }
    else
    {
        DtBarco **dtbarcos = listarBarcos();
        for (int i = 0; i < cantidadBarcos; i++)
        {
            std::cout << dtbarcos[i];
        }
    }
}

Puerto *obtenerIdPuerto(std::string paramId)
{
    for (int i = 0; i < cantidadPuertos; i++)
    {
        if (puertos[i]->getId() == paramId)
        {
            return puertos[i];
        }
    }
    return NULL;
}

Barco *obtenerIdBarco(std::string paramId)
{
    for (int i = 0; i < cantidadBarcos; i++)
    {
        if (barcos[i]->getId() == paramId)
        {
            return barcos[i];
        }
    }
    return NULL;
}

void agregarBarco(DtBarco *barco)
{
    if (dynamic_cast<DtBarcoPasajeros *>(barco))
    {
        DtBarcoPasajeros *b = dynamic_cast<DtBarcoPasajeros *>(barco);
        BarcoPasajeros *bp = new BarcoPasajeros(b->getCantPasajeros(), b->getTamanio(), b->getNombre(), b->getId());
        barcos[cantidadBarcos] = bp;
        cantidadBarcos++;
    }
    else
    {
        DtBarcoPesquero *b = dynamic_cast<DtBarcoPesquero *>(barco);
        BarcoPesquero *bp = new BarcoPesquero(b->getCapacidad(), b->getCarga(), b->getNombre(), b->getId());
        barcos[cantidadBarcos] = bp;
        cantidadBarcos++;
    }
}


void agregarPuerto(std::string id, std::string nombre, const DtFecha &fechaCreacion)
{
    int i = 0;
    while (true)
    {
        if (cantidadPuertos == 0)
        {
            ///Puerto *p = new Puerto(id, nombre, fechaCreacion, 0);
            ///puertos[i] = p;
            cantidadPuertos++;
            break;
        }
        else
        {
            if (i < cantidadPuertos)
            {
                if (id == puertos[i]->getId())
                {
                    throw std::invalid_argument("Ya existe un barco con la misma id ingresada");
                    break;
                }
                i++;
            }
            else if (i == cantidadPuertos)
            {
                ///Puerto *p = new Puerto(id, nombre, fechaCreacion, 0);
                ///puertos[i] = p;
                cantidadPuertos++;
                break;
            }
        }
    }
}

DtBarco **listarBarcos()
{
    DtBarco **dtbarcos = new DtBarco *[cantidadBarcos];
    for (int i = 0; i < cantidadBarcos; i++)
    {
        if (dynamic_cast<BarcoPasajeros *>(barcos[i]))
        {
            BarcoPasajeros *b = dynamic_cast<BarcoPasajeros *>(barcos[i]);
            dtbarcos[i] = new DtBarcoPasajeros(b->getCantPasajeros(), b->getTamanio(), b->getNombre(), b->getId());
        }
        else
        {
            BarcoPesquero *b = dynamic_cast<BarcoPesquero *>(barcos[i]);
            dtbarcos[i] = new DtBarcoPesquero(b->getCapacidad(), b->getCarga(), b->getNombre(), b->getId());
        }
    }
    return dtbarcos;
}

DtPuerto *listarPuertos()
{
    DtPuerto *dtpuertos = new DtPuerto[cantidadPuertos];
    for (int i = 0; i < cantidadPuertos; i++)
    {
        // TODO dtpuertos[i] = DtPuerto(puertos[i]->getId(), puertos[i]->getNombre(), puertos[i]->getFechaCreacion(), puertos[i]->getCantArribos());
    }
    return dtpuertos;
}

void agregarArribo(std::string idPuerto, std::string idBarco, float cargaDespacho)
{
    Barco *b = obtenerIdBarco(idBarco);
    Puerto *p = obtenerIdPuerto(idPuerto);
    if (p == NULL)
    {
        throw std::invalid_argument("\n\e[0;31mNo existe un Puerto con esa id\e[0m");
    }
    if (b == NULL)
    {
        throw std::invalid_argument("\n\e[0;31mNo existe un Barco con esa id\e[0m");
    }
    if ((dynamic_cast<BarcoPasajeros *>(b)))
    {
        if (cargaDespacho != 0)
        {
            throw std::invalid_argument("\n\e[0;31mLa cantidad de carga es incorrecta\e[0m");
        }
        else
        {
            for (int i = 0; i < cantidadPuertos; i++)
            {
                if (p->getId() == puertos[i]->getId())
                {
                    Arribo *a = new Arribo(DtFecha(dia, mes, anio), cargaDespacho, *b);
                    puertos[i]->setArribo(a);
                    int cant = puertos[i]->getCantArribos() + 1;
                    puertos[i]->setCantArribos(cant);
                }
            }
        }
    }
    else
    {
        BarcoPesquero *b1 = (dynamic_cast<BarcoPesquero *>(b));
        b1->Barco::operator=(*b);
        for (int i = 0; i < cantidadPuertos; i++)
        {
            if (puertos[i]->getId() == p->getId())
            {
                if (cargaDespacho <= 0)
                {
                    cargaDespacho = b1->getCarga() + (cargaDespacho * (-1));
                }
                else
                {
                    if (cargaDespacho > b1->getCarga())
                    {
                        throw std::invalid_argument("\n\e[0;31mLa cantidad de carga es incorrecta\e[0m");
                    }
                    else
                    {
                        if (cargaDespacho > b1->getCapacidad())
                        {
                            throw std::invalid_argument("\n\e[0;31mNo existe un Barco con esa id\e[0m");
                        }
                        cargaDespacho = b1->getCarga() - cargaDespacho;
                    }
                }
                Arribo *a = new Arribo(DtFecha(dia, mes, anio), cargaDespacho, *b1);
                puertos[i]->setArribo(a);
                int cant = puertos[i]->getCantArribos() + 1;
                puertos[i]->setCantArribos(cant);
            }
        }
    }
}

DtArribo *obtenerInfoArribosEnPuerto(std::string idpuerto)
{
    Puerto *p = obtenerIdPuerto(idpuerto);
    if (p == NULL)
    {
        throw std::invalid_argument("\n\e[0;31mNo existe un Puerto con esa id\e[0m");
    }
    else
    {
        Arribo *a;
        int cant = p->getCantArribos();
        DtArribo *dtarribos = new DtArribo[cant];
        for (int i = 0; i < p->getCantArribos(); i++)
        {
            a = p->getArribo(i);
            Barco *b = a->getBarco();
            if (dynamic_cast<BarcoPasajeros *>(b))
            {
                BarcoPasajeros *b = new BarcoPasajeros;
                b = dynamic_cast<BarcoPasajeros *>(b);
                DtBarcoPasajeros *bp = new DtBarcoPasajeros(b->getCantPasajeros(), b->getTamanio(), b->getNombre(), b->getId());
                dtarribos[i] = DtArribo(bp, a->getFechaDeArribo(), a->getCarga());
            }
            else
            {
                BarcoPesquero *b = new BarcoPesquero;
                b = dynamic_cast<BarcoPesquero *>(b);
                DtBarcoPesquero *bp = new DtBarcoPesquero(b->getCapacidad(), b->getCarga(), b->getNombre(), b->getId());
                dtarribos[i] = DtArribo(bp, a->getFechaDeArribo(), a->getCarga());
            }
        }
        return dtarribos;
    }
}

void eliminarArribo(std::string id, const DtFecha &fecha)
{
    Puerto *p = obtenerIdPuerto(id);
    if (p == NULL)
    {
        throw std::invalid_argument("El puerto ingresado no existe");
    }
    for (int i = 0; i <= p->getCantArribos(); i++)
    {
        if (p->getArribo(i)->getFechaDeArribo() == fecha)
        {
            if (p->getCantArribos() == 1)
            {
                delete p->getArribo(i);
                p->setCantArribos(0);
            }
            else
            {
                int ultimo = p->getCantArribos() - 1;
                delete p->getArribo(i);
                memmove(p->getArribo(i), p->getArribo(ultimo), ultimo);
                p->setCantArribos(ultimo);
            }
        }
    }
}

void mostrarListaPuertos()
{ // TODO Mejorar si es posible
    for (int i = 0; i < cantidadPuertos; i++)
    {
        std::cout << puertos[i]->getId() << std::endl;
        std::cout << puertos[i]->getNombre() << std::endl;
        //std::cout << puertos[i]->getFechaCreacion() << std::endl;
        //std::cout << puertos[i]->getCantArribos() << std::endl;
    }
}
