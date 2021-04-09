#include "./definiciones.h"

const int MAX_PUERTOS = 30;
const int MAX_BARCOS = 30;
const int MAX_ARRIBOS = 30;
//Puerto **puertos = new Puerto *[MAX_PUERTOS];
int cantidadPuertos = 0;
//Barco **barcos = new Barco *[MAX_BARCOS];
Puerto puertos[MAX_PUERTOS];
Barco barcos[MAX_BARCOS];
int cantidadBarcos = 0;
int dia, mes, anio;
obtenerFechaDelSistema(dia, mes, anio);

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
    bool flag = true;
    while (flag == true)
    {
        try
        {
            if (cantidadBarcos >= MAX_BARCOS)
                throw std::invalid_argument("e[0;31mLa cantidad maxima de Barcos a sido alcanzada.\e[0m");

            std::cout << "\nEscriba el id del Barco: ";
            std::cin >> id;

            if (id == obtenerIdBarco(id)->getId()) // Si ya existe envia error
                throw std::invalid_argument("\e[0;31mYa existe un Barco con esa id\e[0m");

            std::cout << "\nEscriba el nombre del Barco: ";
            std::cin >> nombre;

            agregarBarco(id, nombre, DtFecha(dia, mes, anio));
            //agregarBarco(barcos, b, cantBarcos); //barcos[], tiene que estar afuera del menu
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
    /*std::string nombre, id;
    std::cout << "Ingrese el nombre e id del barco: ";
    std::cin >> nombre >> id;
    DtBarco *b= new DtBarco(nombre, id);
    agregarBarco(b);*/
}

void menuCaso3()
{
    int cantPuertos; //contador de puertos, para agregar a agregarPuerto
    if (cantPuertos == 0)
    {
        std::cout << "No hay puertos registrados\n";
    }
    else
    {
        /*DtPuertos mostrarpuertos = listarPuertos(puertos, cantPuertos);
        for (int i = 0; i < cantPuertos; i++)
        {
            std::cout << "Nombre: " << mostrarPuertos[i].getNombre() << std::endl; //o hacerlo con std::ostream
        }*/
    }
}

void menuCaso4()
{
    //void agregarArribo(string idPuerto, string idBarco, float cargaDespacho)
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
            if (carga <= 0 || carga >= 100) // TODO ver las cantidades
                throw std::invalid_argument("\e[0;31mLa cantidad de carga es incorrecta\e[0m");

            //Arribo arribo = new Arribo(carga); // TODO ver que agregar
            /* Ejemplo de uso de fecha
                usuarios[cantidadUsuarios] = new Usuario(nombre, cedula, DtFecha(dia, mes, anio));
            */
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
    std::cout << "\nSin implementar\n";
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

            eliminarArribo(id);
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
        DtBarcos mostrarbarcos = listarBarcos(barcos, cantBarcos);
        for (int i = 0; i < cantBarcos; i++)
        {
            std::cout << "Nombre: " << mostrarBarcos[i].getNombre() << std::endl; //o hacerlo con std::ostream
        }
    }
}

Puerto *obtenerIdPuerto(std::string paramId)
{
    for (int i = 0; i < cantidadPuertos; i++)
    {
        if (puertos[i].getId() == paramId)
        {
            return puertos[i]();
        }
    }
    return NULL;
}

Barco *obtenerIdBarco(std::string paramId)
{
    for (int i = 0; i < cantidadBarcos; i++)
    {
        if (barcos[i].getId() == paramId)
        {
            return barcos[i];
        }
    }
    return NULL;
}

void agregarBarco(DtBarco *barco)
{
    int i = 0;
    while (true)
    {
        if (barco->getId() == barcos[i].getId())
        {
            throw std::invalid_argument("Ya existe un barco con la misma id ingresada");
            return;
        }
        else if (i == cantidadBarcos)
        {
            if (dynamic_cast<DtBarcoPasajeros *>(barco))
            {
                DtBarcoPasajeros *b = dynamic_cast<DtBarcoPasajeros *>(barco);
                if (i == 0)
                {

                    barcos[i] = BarcoPasajeros(b->getCantPasajeros(), b->getTamanio(), b->getNombre(), b->getId());
                    cantidadBarcos++;
                }
                else
                {
                    barcos[i++] = BarcoPasajeros(b->getCantPasajeros(), b->getTamanio(), b->getNombre(), b->getId());
                    cantidadBarcos++;
                }
                i++;
                break;
            }
            else
            {
                DtBarcoPesquero *b = dynamic_cast<DtBarcoPesquero *>(barco);
                if (i == 0)
                {
                    barcos[i] = BarcoPesquero(b->getCapacidad(), b->getCarga(), b->getNombre(), b->getId());
                    cantidadBarcos++;
                }
                else
                {
                    barcos[i++] = BarcoPesquero(b->getCapacidad(), b->getCarga(), b->getNombre(), b->getId());
                    cantidadBarcos++;
                }
                i++;
                break;
            }
        }
        i++;
    }
}

void agregarPuerto(std::string id, std::string nombre, const DtFecha &fechaCreacion)
{
    int i = 0;
    while (true)
    {
        if (id == puertos[i].getId())
        {
            throw std::invalid_argument("Ya existe un barco con la misma id ingresada");
            return;
        }
        else if (i == cantidadPuertos)
        {
            if (i == 0)
            {
                puertos[i] = Puerto(id, nombre, fechaCreacion, 0);
                cantidadPuertos++;
                break;
            }
            else
            {
                puertos[i++] = Puerto(id, nombre, fechaCreacion, 0);
                cantidadPuertos++;
                break;
            }
        }
        i++;
    }
}

DtBarco *listarBarcos()
{
    DtBarco *dtbarcos = new DtBarco[cantidadBarcos];
    for (int i = 0; i < cantidadBarcos; i++)
    {
        if (!barcos[i].getId().empty())
        {
            BarcoPasajeros *b = (dynamic_cast<BarcoPasajeros *>(&barcos[i]));
            if (b)
            {
                dtbarcos[i] = DtBarcoPasajeros(b->getCantPasajeros(), b->getTamanio(), b->getNombre(), b->getId());
            }
            else
            {
                BarcoPesquero b;
                b.Barco::operator=(barcos[i]);
                dtbarcos[i] = DtBarcoPesquero(b.getCapacidad(), b.getCarga(), b.getNombre(), b.getId());
            }
        }
        else
        {
            i = cantidadBarcos;
        }
    }
    return dtbarcos;
}

DtPuerto *listarPuertos()
{
    DtPuerto *dtpuertos = new DtPuerto[cantidadPuertos];
    for (int i = 0; i < cantidadPuertos; i++)
    {
        if (!puertos[i].getId().empty())
        {
            dtpuertos[i] = DtPuerto(puertos[i].getId(), puertos[i].getNombre(), puertos[i].getFechaCreacion(), puertos[i].getCantArribos());
        }
        else
        {
            i = cantidadPuertos;
        }
    }
    mostrarPuertos();
    return dtpuertos;
}

/*void agregarArribo(std::string idPuerto, std::string idBarco, float cargaDespacho)
{
    Barco *b = new Barco;
    *b = obtenerIdBarco(idBarco);
    Puerto *p = new Puerto;
    *p = obtenerIdPuerto(idPuerto);
    DtFecha fecha = obtenerFechaDelSitema();
    if (p->getId().empty())
    {
        throw std::invalid_argument("\n\e[0;31mNo existe un Puerto con esa id\e[0m");
    }
    if (b->getId().empty())
    {
        throw std::invalid_argument("\n\e[0;31mNo existe un Barco con esa id\e[0m");
    }
    if((dynamic_cast<BarcoPasajeros*>(b)))
    {
        if(cargaDespacho!=0){

            throw std::invalid_argument("\n\e[0;31mLa cantidad de carga es incorrecta\e[0m");
        }
        else
        {
            for(int i=0; i < cantidadPuertos; i++)
            {
                if(p->getId()== puertos[i].getId())
                {
                    Arribo a(fecha, cargaDespacho);
                    puertos[i].setArribo(a);
                }
            }
        }

    }
    else
    {
        BarcoPesquero *b1;
        b1->Barco::operator=(*b);
        for(int i=0; i< cantidadPuertos; i++)
        {

            if(this->puertos[i].getId()==p->getId())
            {
                if(cargaDespacho<=0)
                {
                    cargaDespacho = b1->getCarga() + (cargaDespacho * (-1));
                }
                else
                {
                    cargaDespacho = b1->getCarga() - cargaDespacho;
                }
                Arribo a(fecha, cargaDespacho);
                puertos[i].setArribo(a);
            }
        }
    }

}*/

void eliminarArribo(std::string id)
{
    std::cout << "\nSin implementar\n";
}

void mostrarPuertos(){
    for (int i = 0; i < cantidadPuertos; i++){
        std::cout << puertos[i].getId() << puertos[i].getNombre() << puertos[i].getFechaCreacion << puertos[i].getCantArribos << std::endl;
    }
}