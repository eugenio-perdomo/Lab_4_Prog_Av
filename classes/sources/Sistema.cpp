#include "./../headers/Sistema.h"
Sistema::Sistema()
{
    this->videojuegos = new OrderedDictionary;
    this->categorias = new OrderedDictionary;
    this->jugadores = new OrderedDictionary;
    this->desarrolladores = new OrderedDictionary;
    this->fechaDelSistema = new DtFecha(03, 07, 2022, 00, 30, 10);
}

// Alta de usuario
void Sistema::menuCaso1()
{
    int opcionUsuario;
    bool bandera = true;
    while (bandera == true)
    {
        // Sistema::imprimirTextoPrincipal();
        std::cin >> opcionUsuario;
        std::cout << "\e[0m";
        std::cin.clear();
        std::cin.ignore(10000, '\n');
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
                std::cout.flush();
                throw std::invalid_argument("\n\e[0;31mLa opcion ingresada no es correcta.\n\e[0m");
                break;
            }
        }
        catch (std::invalid_argument &e)
        {
            std::cerr << e.what() << std::endl;
        }
    }
}

void Sistema::agregarJugador(std::string email, std::string contrasenia, std::string nick, std::string desc)
{
    StringKey *key = new StringKey(email);
    Jugador *jug = new Jugador(email, contrasenia, nick, desc);
    jugadores->add(key, jug);
}

void Sistema::agregarDesarrollador(std::string email, std::string contrasenia, std::string empresa)
{
    StringKey *key = new StringKey(email);
    Desarrollador *des = new Desarrollador(email, contrasenia, empresa);
    desarrolladores->add(key, des);
}

// Iniciar sesión
void Sistema::menuCaso2()
{
    int opcionUsuario;
    std::string email, contrasenia;
    bool bandera = true;
    std::cout << "\nIngrese email: ";
    std::cin >> email;
    std::cin.clear();
    std::cin.ignore(10000, '\n');
    std::cout << "\nIngrese contraseña: ";
    std::cin >> contrasenia;
    std::cin.clear();
    std::cin.ignore(10000, '\n');
    try
    {
        InicioSesion(email, contrasenia, 2);
        while (bandera == true)
        {
            std::cin >> opcionUsuario;
            std::cout << "\e[0m";
            std::cin.clear();
            std::cin.ignore(10000, '\n');
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
                std::cout.flush();
                throw std::invalid_argument("\n\e[0;31mLa opcion ingresada no es correcta.\n\e[0m");
            }
        }
    }
    catch (std::invalid_argument &e)
    {
        std::cerr << e.what() << std::endl;
    }
}

int Sistema::iniciarSesion(string email, string contrasenia)
{
    StringKey *key = new StringKey(email);
    // int validador=0;

    // Verifica si ese email pertenece a un jugador o a un desarrollador
    bool validarJugador = jugadores->member(key);
    bool validarDesarrollador = desarrolladores->member(key);

    if (validarJugador == true)
    {
        Jugador *auxJugador = dynamic_cast<Jugador *>(jugadores->find(key));
        // Es usuario el que tiene contrasenia. Jugador debe tener constructor de todo entonces
        if (contrasenia == auxJugador->getContrasenia())
        {
            return 1;
        }
    }

    if (validarDesarrollador == true)
    {
        Desarrollador *auxDesarrollador = dynamic_cast<Desarrollador *>(desarrolladores->find(key));
        if (contrasenia == auxDesarrollador->getContrasenia())
        {
            return 2;
        }
    }

    return 0;
}

Jugador *Sistema::obtenerJugadorActual(string email)
{
    StringKey *key = new StringKey(email);
    Jugador *auxJugador = dynamic_cast<Jugador *>(jugadores->find(key));
    return auxJugador;
}

Desarrollador *Sistema::obtenerDesarrolladorActual(string email)
{
    StringKey *key = new StringKey(email);
    Desarrollador *auxDesarrollador = dynamic_cast<Desarrollador *>(desarrolladores->find(key));
    return auxDesarrollador;
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

void Sistema::imprimirMenuDesarrollador()
{
    int opcionUsuario;
    bool bandera = true;
    while (bandera == true)
    {
        Sistema::imprimirTextoDelDesarrollador();
        std::cin >> opcionUsuario;
        std::cout << "\e[0m";
        std::cin.clear();
        try
        {
            switch (opcionUsuario)
            {
            case 1: // Agregar categoría
            {
                break;
            }
            case 2: // Publicar videojuego
            {
                break;
            }
            case 3: // Eliminar videojuego
            {
                break;
            }
            case 4: // Seleccionar estadísticas
            {
                break;
            }
            case 5: // Consultar estadísticas
            {
                break;
            }
            case 6: // Ver información de videojuego
            {
                break;
            }
            case 7: // Modificar fecha del sistema
            {
                break;
            }
            case 8: // CASO SALIDA DE SISTEMA
            {
                bandera = false;
                break;
            }
            default:
                std::cout.flush();
                throw std::invalid_argument("\n\e[0;31mLa opcion ingresada no es correcta.\n\e[0m");
                break;
            }
        }
        catch (std::invalid_argument &e)
        {
            std::cerr << e.what() << std::endl;
        }
    }
}

void Sistema::imprimirMenuJugador()
{
    int opcionUsuario;
    bool bandera = true;
    while (bandera == true)
    {
        Sistema::imprimirTextoDelJugador();
        std::cin >> opcionUsuario;
        std::cout << "\e[0m";
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        try
        {
            switch (opcionUsuario)
            {
            case 1: // Suscribirse a videojuego
            {
                break;
            }
            case 2: // Asignar puntaje a videojuego
            {
                break;
            }
            case 3: // Iniciar partida
            {
                break;
            }
            case 4: // Abandonar partida multijugador
            {
                break;
            }
            case 5: // Finalizar partida
            {
                break;
            }
            case 6: // Ver información de videojuego
            {
                break;
            }
            case 7: // Modificar fecha del sistema
            {
                break;
            }
            case 8: // CASO SALIDA DE SISTEMA
            {
                bandera = false;
                break;
            }
            default:
                std::cout.flush();
                throw std::invalid_argument("\n\e[0;31mLa opcion ingresada no es correcta.\n\e[0m");
                break;
            }
        }
        catch (std::invalid_argument &e)
        {
            std::cerr << e.what() << std::endl;
        }
    }
}

void Sistema::imprimirTextoPrincipal()
{
    std::cout << "\e[0;92mBienvenido - Elija una opción\e[0m:";
    std::cout << "\n\e[0;92m1)\e[0m Alta de usuario.\n";
    std::cout << "\e[0;92m2)\e[0m Iniciar sesión.\n";
    std::cout << "\e[0;92m3)\e[0m Cargar datos de prueba.\n";
    std::cout << "Pulse \e[0;92m4\e[0m para salir.\n\nOpcion: \e[0;92m";
}

void Sistema::imprimirTextoDelDesarrollador()
{
    std::cout << "\e[0;92mMenú de Desarrollador - Elija una opción\e[0m:";
    std::cout << "\n\e[0;92m1)\e[0m Agregar categoría.\n";
    std::cout << "\e[0;92m2)\e[0m Publicar videojuego.\n";
    std::cout << "\e[0;92m3)\e[0m Eliminar videojuego.\n";
    std::cout << "\e[0;92m4)\e[0m Seleccionar estadísticas.\n";
    std::cout << "\e[0;92m5)\e[0m Consultar estadísticas.\n";
    std::cout << "\e[0;92m6)\e[0m Ver información de videojuego.\n";
    std::cout << "\e[0;92m7)\e[0m Modificar fecha del sistema.\n";
    std::cout << "Pulse \e[0;92m8\e[0m para salir.\n\nOpcion: \e[0;92m";
}

void Sistema::imprimirTextoDelJugador()
{
    std::cout << "\e[0;92mMenú de Jugador - Elija una opción\e[0m:";
    std::cout << "\n\e[0;92m1)\e[0m Suscribirse a videojuego.\n";
    std::cout << "\e[0;92m2)\e[0m Asignar puntaje a videojuego.\n";
    std::cout << "\e[0;92m3)\e[0m Iniciar partida.\n";
    std::cout << "\e[0;92m4)\e[0m Abandonar partida multijugador.\n";
    std::cout << "\e[0;92m5)\e[0m Finalizar partida.\n";
    std::cout << "\e[0;92m6)\e[0m Ver información de videojuego.\n";
    std::cout << "\e[0;92m7)\e[0m Modificar fecha del sistema.\n";
    std::cout << "Pulse \e[0;92m8\e[0m para salir.\n\nOpcion: \e[0;92m";
}

Sistema::~Sistema() {}
