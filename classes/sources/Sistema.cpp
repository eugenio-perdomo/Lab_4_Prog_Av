#include "./../headers/Sistema.h"
Sistema::Sistema()
{
    /*this->usuarios = new OrderedDictionary;
    this->fecha = new DtFecha(01, 01, 2022, 00, 00, 00);*/
}

void Sistema::imprimirTextoPrincipal(){}
void Sistema::imprimirMenuDesarrollador(){}
void Sistema::imprimirMenuJugador(){}

// Alta de usuario
void Sistema::menuCaso1()
{
    int opcionUsuario;
    bool bandera = true;
    while (bandera == true)
    {
        // Sistema::imprimirMenuJugador();
        std::cin >> opcionUsuario;
        std::cout << "\e[0m";
        std::cin.clear();
        try
        {
            switch (opcionUsuario)
            {
            case 1:
            {
                break;
            }
            case 2:
            {
                break;
            }
            case 3:
            {
                break;
            }
            case 4: // CASO SALIDA DE SISTEMA
            {
                bandera = false;
                break;
            }
            default:
                throw std::invalid_argument("\n\e[0;31mLa opcion ingresada no es correcta.\n\e[0m");
            }
        }
        catch (std::invalid_argument &e)
        {
            std::cerr << e.what() << std::endl;
        }
    }
}

// Iniciar sesión
void Sistema::menuCaso2()
{
    int opcionUsuario;
    std::string email, contrasenia;
    bool bandera = true;
    std::cout << "\nIngrese email: ";
    std::cin >> email;
    std::cout << "\nIngrese contraseña: ";
    std::cin >> contrasenia;
    try
    {
        InicioSesion(email, contrasenia, 2);
        while (bandera == true)
        {
            std::cin >> opcionUsuario;
            std::cout << "\e[0m";
            std::cin.clear();
            switch (opcionUsuario)
            {
            case 1:
            {
                break;
            }
            case 2:
            {
                break;
            }
            case 3:
            {
                break;
            }
            case 4:
            {
                break;
            }
            case 5:
            {
                break;
            }
            case 6: // CASO SALIDA DE SISTEMA
            {
                bandera = false;
                break;
            }
            default:
                throw std::invalid_argument("\n\e[0;31mLa opcion ingresada no es correcta.\n\e[0m");
            }
        }
    }
    catch (std::invalid_argument &e)
    {
        std::cerr << e.what() << std::endl;
    }
}

// Cargar datos de prueba
void Sistema::menuCaso3()
{
}

void Sistema::InicioSesion(std::string email, std::string contrasenia, int i)
{
/*    IKey *k = new String(email);
    if(i == 1)
    {
        if(!this->usuarios->member(k))
        {
            throw std::invalid_argument("\e[0;31mEl email ingresado no es correcto.\e[0m");
        }
        Usuario * u = (Usuario *)this->usuarios->find(k);
        if (dynamic_cast<Jugador *>(u))
        {
            Jugador *j = new Jugador;
            j = dynamic_cast<Jugador *>(u);
            if(j->getContrasenia().compare(contrasenia) != 0)
            {
                throw std::invalid_argument("\e[0;31mLa contraseña ingresada no es correcta.\e[0m");
            }
            this->actual = j;
        }
        else
        {
            throw std::invalid_argument("\e[0;31mEl Usuario ingresado no es un Jugador.\e[0m");
        }
    }
    if(i == 2)
    {
        if(!this->usuarios->member(k))
        {
            throw std::invalid_argument("\e[0;31mEl email ingresado no es correcto.\e[0m");
        }
        Usuario * u = (Usuario *)this->usuarios->find(k);
        if (dynamic_cast<Desarrollador *>(u))
        {
            Desarrollador *d = new Desarrollador;
            d = dynamic_cast<Desarrollador *>(u);
            if(d->getContrasenia().compare(contrasenia) != 0)
            {
                throw std::invalid_argument("\e[0;31mLa contraseña ingresada no es correcta.\e[0m");
            }
            this->actual = d;
        }
        else
        {
            throw std::invalid_argument("\e[0;31mEl Usuario ingresado no es un Desarrollador.\e[0m");
        }
    }
*/
}

Sistema::~Sistema() {}
