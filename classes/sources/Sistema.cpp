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
    Sistema *s = new Sistema();
    int opcionUsuario;
    bool bandera = true;
    while (bandera == true)
    {
        string email, contrasenia;
            std::cout << "Ingresar email: ";
            std::cin.ignore();
            getline(std::cin, email);
            std::cout << "Ingresar contrasenia: ";
            std::cin.ignore();
            getline(std::cin, contrasenia);

            int tipo;

            std::cout << "Indicar tipo (1-jugador 2-desarrollador)" << std::endl;
            std::cin >> tipo;

            if (tipo == 1)
            {
                // AGREGAR JUGADOR
                string nick;
                std::cout << "Ingresar nick: ";
                std::cin.ignore();
                getline(std::cin, nick);

                string descripcion;
                std::cout << "Ingresar descripcion: ";
                std::cin.ignore();
                getline(std::cin, descripcion);
                s->agregarJugador(email, contrasenia, nick, descripcion);
            }
            else
            {
                // AGREGAR DESARROLLADOR
                std::cout << "Ingresar empresa: ";
                string empresa;
                std::cin.ignore();
                getline(std::cin, empresa);
                s->agregarDesarrollador(email, contrasenia, empresa);
            }

            break;
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
    Sistema *s = new Sistema();
    std::string email, contrasenia;
    bool bandera = true;
    int salir = 1;
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
        int opcionUsuario = iniciarSesion(email, contrasenia);
        InicioSesion(email, contrasenia, opcionUsuario);
        while (bandera == true)
        {
            
            switch (opcionUsuario && salir !=0)
            {
                case 0:
                {
                    std::cout << "Los datos de acceso son incorrectos" << std::endl;
                    int op;
                    std::cout << "Desea cancelar el inicio de sesion?" << std::endl;
                    std::cout << "1- Si" << std::endl;
                    std::cout << "2- No" << std::endl;
                    std::cin >> op;

                    if (op == 1)
                    {
                        salir = 0;
                        bandera = false;
                    }
                    break;
                }
            case 1:
            {
                std::cout << "Sesion iniciada como Jugador" << std::endl;
                usuarioActual = s->obtenerJugadorActual(email);
                imprimirMenuJugador();
            }
            case 2:
            {
                std::cout << "Sesion iniciada como Desarrollador" << std::endl;
                usuarioActual = s->obtenerDesarrolladorActual(email);
                imprimirMenuDesarrollador();
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

//Publicar videojuego
void menuCaso4(){
    Sistema *s = new Sistema();

    std::string nom, desc;
    float cMensual, cTristral, cAnual;

    std::cout << "\nIngrese nombre: ";
    std::cin >> nom;
    std::cin.clear();
    std::cin.ignore(10000, '\n');
    std::cout << "\nIngrese descripcion: ";
    std::cin >> desc;
    std::cin.clear();
    std::cin.ignore(10000, '\n');

    std::cout << "\nIngrese costo menusal: ";
    std::cin >> cMensual;
    std::cout << "\nIngrese costo trimestral: ";
    std::cin >> cTristral;
    std::cout << "\nIngrese costo anual: ";
    std::cin >> cAnual;

    bool deseaAgregar=true;
    int op2 = 1;
    List* aux_categorias = new List();

    while(deseaAgregar==true){

        s->mostrarCategorias(); //Sin implementar

        std::string cat;
        std::cout << "\nSeleccione una categoria: ";
        std::cin >> cat;
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        Categoria* aux = s->obtenerCategoria(cat);
        
        if (aux_categorias->member(aux)){
            //La categoria ya habia sido agregada a la lista auxiliar anteriormente
            std::cout << "\nEsa categoria ya fue seleccionada anteriormente";
        } else {
            aux_categorias->add(aux);
        }  

        std::cout << "\nDesea asignar otra categoria?";
        std::cout << "1- Si";
        std::cout << "2- No";
        std::cin >> op2;

        if (op2==1){
            deseaAgregar=false;
        }
    
    } 

    //MOSTRAR LOS DATOS:

    //CONFIRMAR:

} 


void Sistema::mostrarCategorias(){

}

Categoria* Sistema::obtenerCategoria(std::string categoria){
    StringKey* key = new StringKey(categoria);
    Categoria* aux = dynamic_cast<Categoria*>(categorias->find(key));
    return aux;
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
            case 1: //Publicar Videojuego
            {
                break;
            }
            case 2: //Eliminar Videojuego
            {
                break;
            }
            
            case 3: // CASO SALIDA DE SISTEMA
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
            case 2: // Iniciar partida
            {
                break;
            }
            case 3: // Finalizar partida
            {
                break;
            }
            case 4: // Ver información de videojuego
            {
                break;
            }
        
            case 5: // CASO SALIDA DE SISTEMA
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
    std::cout << "\e[0;92m2)\e[0m 1: Publicar videojuego.\n";
    std::cout << "\e[0;92m3)\e[0m 2: Eliminar videojuego.\n";
    std::cout << "Pulse \e[0;92m8\e[0m 3: Para salir.\n\nOpcion: \e[0;92m";
}

void Sistema::imprimirTextoDelJugador()
{
    std::cout << "\e[0;92mMenú de Jugador - Elija una opción\e[0m:";
    std::cout << "\n\e[0;92m1)\e[0m 1: Suscribirse a videojuego.\n";
    std::cout << "\e[0;92m3)\e[0m 2: Iniciar partida.\n";
    std::cout << "\e[0;92m5)\e[0m 3: Finalizar partida.\n";
    std::cout << "\e[0;92m6)\e[0m 4: Ver información de videojuego.\n";
    std::cout << "Pulse \e[0;92m8\e[0m 5: para salir.\n\nOpcion: \e[0;92m";
}

Sistema::~Sistema() {}
