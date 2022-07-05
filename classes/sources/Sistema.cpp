#include "../headers/Sistema.h"
#include <sstream>
#include <iomanip>
#include <ctime>

Sistema::Sistema()
{
    this->videojuegos = new OrderedDictionary;
    this->categorias = new OrderedDictionary;
    this->jugadores = new OrderedDictionary;
    this->desarrolladores = new OrderedDictionary;
    this->fechaDelSistema = new DtFecha(03, 07, 2022, 00, 30, 10);
    // this->listaJugadores = new List();
}

DtFecha *Sistema::obtenerFecha()
{

    auto t = time(nullptr);   // Auxiliar para obtener la fecha y hora del sistema
    auto tm = *localtime(&t); // Guarda todos los campos de fecha y hora

    fechaDelSistema->setAnio(tm.tm_year + 1900);
    fechaDelSistema->setMes(tm.tm_mon);
    fechaDelSistema->setDia(tm.tm_mday);
    fechaDelSistema->setHora(tm.tm_hour);
    fechaDelSistema->setMinuto(tm.tm_min);
    fechaDelSistema->setSegundo(tm.tm_sec);

    return fechaDelSistema;
}

int Sistema::calcularDiferenciaFecha(DtFecha *hora1)
{
    int resultado;

    int anio1, anio2, mes1, mes2, dia1, dia2, hor1, hor2, minuto1, minuto2, segundo1, segundo2;

    DtFecha *aux = obtenerFecha();

    // Se convierte todo en minuto.
    anio1 = hora1->getAnio() * 525600;
    anio2 = aux->getAnio() * 525600;

    mes1 = hora1->getMes() * 43800;
    mes2 = aux->getMes() * 43800;

    dia1 = hora1->getDia() * 1440;
    dia2 = aux->getDia() * 1440;

    hor1 = hora1->getHora() * 60;
    hor2 = aux->getHora() * 60;

    minuto1 = hora1->getDia();
    minuto2 = aux->getDia();

    segundo1 = hora1->getMinuto() / 60;
    segundo2 = aux->getMinuto() / 60;

    int fecha1, fecha2;
    fecha1 = anio1 + mes1 + dia1 + hor1 + minuto1 + segundo1;
    fecha2 = anio2 + mes2 + dia2 + hor2 + minuto2 + segundo2;

    resultado = fecha2 - fecha1;

    return resultado;
}

// Alta de usuario
void Sistema::menuCaso1()
{
    int tipo;
    bool bandera = true;
    while (bandera == true)
    {
        std::string email, contrasenia;
        std::cout << "\nIngresar email: \e[1;36m";
        std::cin >> email;
        clearDeDatosDeEntrada();

        std::cout << "Ingresar contrasenia: \e[1;36m";
        std::cin >> contrasenia;
        clearDeDatosDeEntrada();

        std::cout << "Indicar tipo de usuario \n1- Jugador \n2- Desarrollador\n\nOpcion: \e[0;92m";
        std::cin >> tipo;
        clearDeDatosDeEntrada();

        if (tipo == 1)
        {
            // AGREGAR JUGADOR
            std::string nick, descripcion;
            std::cout << "Ingresar nick: ";
            std::cin >> nick;
            clearDeDatosDeEntrada();

            std::cout << "Ingresar descripcion: ";
            std::cin >> descripcion;
            clearDeDatosDeEntrada();

            agregarJugador(email, contrasenia, nick, descripcion);
        }
        else
        {
            // AGREGAR DESARROLLADOR
            std::cout << "Ingresar empresa: ";
            std::string empresa;
            std::cin >> empresa;
            clearDeDatosDeEntrada();
            agregarDesarrollador(email, contrasenia, empresa);
        }
        break;
    }
}

void Sistema::agregarJugador(std::string email, std::string contrasenia, std::string nick, std::string desc)
{
    StringKey *key = new StringKey(email);
    if (jugadores->member(key) == 1)
    {
        std::cout << "\e[1;33mYa existe un Jugador con ese mail\n\e[0m";
    }
    else
    {
        Jugador *jug = new Jugador(email, contrasenia, nick, desc);
        jugadores->add(key, jug);
    }
}

void Sistema::agregarDesarrollador(std::string email, std::string contrasenia, std::string empresa)
{
    StringKey *key = new StringKey(email);
    if (desarrolladores->member(key) == 1)
    {
        std::cout << "\e[1;33mYa existe un Desarrollador con ese mail\n\e[0m";
    }
    else
    {
        Desarrollador *des = new Desarrollador(email, contrasenia, empresa);
        desarrolladores->add(key, des);
    }
}

// Iniciar sesion
void Sistema::menuCaso2()
{
    std::string email, contrasenia;
    bool bandera = true;
    int opcionUsuario;
    try
    {
        while (bandera == true)
        {
            std::cout << "\nIngrese email: \e[1;36m";
            std::cin >> email;
            clearDeDatosDeEntrada();
            std::cout << "Ingrese contrasenia: \e[1;36m";
            std::cin >> contrasenia;
            clearDeDatosDeEntrada();
            opcionUsuario = iniciarSesion(email, contrasenia);
            switch (opcionUsuario)
            {
            case 0:
            {
                int op;
                std::cout << "\e[1;33mLos datos de acceso son incorrectos.\e[0m\n";
                std::cout << "\e[1;35mDesea cancelar el inicio de sesion?\e[0m\n1- Si\n2- No\n\nOpcion: \e[0;92m";
                std::cin >> op;
                clearDeDatosDeEntrada();

                if (op != 2)
                {
                    bandera = false;
                }
                break;
            }
            case 1:
            {
                std::cout << "\e[1;33mSesion iniciada como Jugador.\e[0m\n";
                jugadorActual = obtenerJugadorActual(email);
                imprimirMenuJugador(jugadorActual);
                bandera = false;
                std::cout << std::endl;
                break;
            }
            case 2:
            {
                std::cout << "\e[1;33mSesion iniciada como Desarrollador.\e[0m\n";
                usuarioActual = obtenerDesarrolladorActual(email);
                desarrolladorActual = obtenerDesarrolladorActual(email);
                imprimirMenuDesarrollador();
                bandera = false;
                std::cout << std::endl;
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

int Sistema::iniciarSesion(std::string email, std::string contrasenia)
{
    StringKey *key = new StringKey(email);
    // Verifica si ese email pertenece a un jugador o a un desarrollador
    bool validarJugador = jugadores->member(key);
    bool validarDesarrollador = desarrolladores->member(key);
    if (validarJugador == 1)
    {
        Jugador *auxJugador = dynamic_cast<Jugador *>(jugadores->find(key));
        // Es usuario el que tiene contrasenia. Jugador debe tener constructor de todo entonces
        if (contrasenia == auxJugador->getContrasenia())
            return 1;
    }

    if (validarDesarrollador == 1)
    {
        Desarrollador *auxDesarrollador = dynamic_cast<Desarrollador *>(desarrolladores->find(key));
        if (contrasenia == auxDesarrollador->getContrasenia())
            return 2;
    }
    return 0;
}

Jugador *Sistema::obtenerJugadorActual(std::string email)
{
    StringKey *key = new StringKey(email);
    Jugador *auxJugador = dynamic_cast<Jugador *>(jugadores->find(key));
    return auxJugador;
}

Desarrollador *Sistema::obtenerDesarrolladorActual(std::string email)
{
    StringKey *key = new StringKey(email);
    Desarrollador *auxDesarrollador = dynamic_cast<Desarrollador *>(desarrolladores->find(key));
    return auxDesarrollador;
}

// Cargar datos de prueba
void Sistema::menuCaso3(int i)
{
    if (i == 0)
    {
        Desarrollador *d1 = new Desarrollador("ironhide@mail.com", "123", "Ironhide Game Studio");
        Desarrollador *d2 = new Desarrollador("epic@mail.com", "123", "Epic Games");
        Desarrollador *d3 = new Desarrollador("mojang@mail.com", "123", "Mojang Studios");
        Desarrollador *d4 = new Desarrollador("ea@mail.com", "123", "EA Sports");

        StringKey *key = new StringKey("ironhide@mail.com");
        desarrolladores->add(key, d1);
        key = new StringKey("epic@mail.com");
        desarrolladores->add(key, d2);
        key = new StringKey("mojang@mail.com");
        desarrolladores->add(key, d3);
        key = new StringKey("ea@mail.com");
        desarrolladores->add(key, d4);

        Jugador *j1 = new Jugador("gamer@mail.com", "123", "gamer", "descripcionJ1");
        Jugador *j2 = new Jugador("ari@mail.com", "123", "ari", "descripcionJ2");
        Jugador *j3 = new Jugador("ibai@mail.com", "123", "ibai", "descripcionJ3");
        Jugador *j4 = new Jugador("camila@mail.com", "123", "camila", "descripcionJ4");

        key = new StringKey("gamer@mail.com");
        jugadores->add(key, j1);
        key = new StringKey("ari@mail.com");
        jugadores->add(key, j2);
        key = new StringKey("ibai@mail.com");
        jugadores->add(key, j3);
        key = new StringKey("camila@mail.com");
        jugadores->add(key, j4);
        /*listaJugadores->add(j1);
        listaJugadores->add(j2);
        listaJugadores->add(j3);*/

        Categoria *c1 = new Categoria("PC", "Descripcion Categoria PC", "Plataforma");
        Categoria *c2 = new Categoria("PS4", "Descripcion Categoria PS4", "Plataforma");
        Categoria *c3 = new Categoria("Xbox One", "Descripcion Categoria Xbox", "Plataforma");
        Categoria *c4 = new Categoria("Deporte", "Descripcion Categoria Deporte", "Genero");
        Categoria *c5 = new Categoria("Supervivencia", "Descripcion Categoria Supervivencia", "Genero");
        Categoria *c6 = new Categoria("Estrategia", "Descripcion Categoria Estrategia", "Genero");
        Categoria *c7 = new Categoria("Teen", "Su contenido esta dirigido a jovenes de 13 anios en adelante.", "Otro");
        Categoria *c8 = new Categoria("E", "Su contenido esta dirigido para todo publico", "Otro");
        Categoria *c9 = new Categoria("Accion", "Descripcion Categoria Accion", "Genero");
        Categoria *c10 = new Categoria("Aventura", "Descripcion Categoria Aventura", "Genero");
        Categoria *c11 = new Categoria("Switch", "Descripcion Categoria Switch", "Plataforma");
        Categoria *c12 = new Categoria("Xbox", "Descripcion Categoria Xbox", "Plataforma");
        Categoria *c13 = new Categoria("PS5", "Descripcion Categoria PS5", "Plataforma");

        key = new StringKey("PC");
        categorias->add(key, c1);
        key = new StringKey("PS4");
        categorias->add(key, c2);
        key = new StringKey("Xbox One");
        categorias->add(key, c3);
        key = new StringKey("Deporte");
        categorias->add(key, c4);
        key = new StringKey("Supervivencia");
        categorias->add(key, c5);
        key = new StringKey("Estrategia");
        categorias->add(key, c6);
        key = new StringKey("Teen");
        categorias->add(key, c7);
        key = new StringKey("E");
        categorias->add(key, c8);
        key = new StringKey("Accion");
        categorias->add(key, c9);
        key = new StringKey("Aventura");
        categorias->add(key, c10);
        key = new StringKey("Switch");
        categorias->add(key, c11);
        key = new StringKey("Xbox");
        categorias->add(key, c12);
        key = new StringKey("PS5");
        categorias->add(key, c13);

        Estadistica *est1 = new Estadistica(4, 1); // TODO Hacer la cuenta de la duracionPartidaPorJugador
        Estadistica *est2 = new Estadistica(5, 1); // Revisar Los datos de prueba en "Puntajes a videojuegos"
        Estadistica *est3 = new Estadistica(5, 1);
        Estadistica *est4 = new Estadistica(3, 1);

        Videojuego *vj1 = new Videojuego("KingdomRush", "Descripcion KingdomRush", 1, 2, 7, 14, est1, d1);
        Videojuego *vj2 = new Videojuego("Fortnite", "Descripcion Fortnite", 3, 8, 30, 60, est2, d2);
        Videojuego *vj3 = new Videojuego("Minecraft", "Descripcion Minecraft", 2, 5, 20, 40, est3, d3);
        Videojuego *vj4 = new Videojuego("FIFA 21", "Descripcion FIFA 21", 3, 8, 28, 50, est4, d4);

        key = new StringKey("KingdomRush");
        videojuegos->add(key, vj1);
        key = new StringKey("Fortnite");
        videojuegos->add(key, vj2);
        key = new StringKey("Minecraft");
        videojuegos->add(key, vj3);
        key = new StringKey("FIFA 21");
        videojuegos->add(key, vj4);

        DtFecha *fecha1 = new DtFecha(01, 06, 2021, 0, 00, 9);
        DtFecha *fecha2 = new DtFecha(0, 0, 0, 0, 0, 0);
        Suscripcion *sus1 = new Suscripcion(fecha1, MetodoPago::Paypal, Valor::TresMeses, false, vj1, j1);
        fecha1 = new DtFecha(02, 06, 2021, 0, 00, 11);
        Suscripcion *sus2 = new Suscripcion(fecha1, MetodoPago::Tarjeta, Valor::TresMeses, false, vj2, j2);
        fecha1 = new DtFecha(04, 06, 2021, 0, 00, 9);
        Suscripcion *sus3 = new Suscripcion(fecha1, MetodoPago::Paypal, Valor::UnMes, false, vj2, j3);
        fecha1 = new DtFecha(11, 06, 2021, 0, 00, 9);
        Suscripcion *sus4 = new Suscripcion(fecha1, MetodoPago::Tarjeta, Valor::Anio, false, vj3, j4);
        fecha1 = new DtFecha(03, 06, 2021, 0, 00, 7);
        Suscripcion *sus5 = new Suscripcion(fecha1, MetodoPago::Tarjeta, Valor::UnMes, false, vj2, j1);
        fecha1 = new DtFecha(21, 12, 2020, 0, 00, 15);
        Suscripcion *sus6 = new Suscripcion(fecha1, MetodoPago::Tarjeta, Valor::Vitalicia, false, vj2, j2);

        j1->setSuscripcion(sus1);
        j2->setSuscripcion(sus2);
        j3->setSuscripcion(sus3);
        j4->setSuscripcion(sus4);
        j1->setSuscripcion(sus5);
        j2->setSuscripcion(sus6);

        // Ind
        fecha1 = new DtFecha(02, 06, 2021, 0, 00, 9);
        fecha2 = new DtFecha(02, 06, 2021, 0, 00, 10);
        Individual *pI1 = new Individual(false, "gamer", "1", "KingdomRush", true, 60, fecha1, fecha2);
        fecha1 = new DtFecha(03, 06, 2021, 0, 00, 15);
        fecha2 = new DtFecha(03, 06, 2021, 0, 00, 16);
        Individual *pI2 = new Individual(false, "gamer", "2", "KingdomRush", true, 60, fecha1, fecha2);
        fecha1 = new DtFecha(12, 06, 2021, 0, 00, 16);
        fecha2 = new DtFecha(0, 0, 0, 0, 0, 0);
        Individual *pI3 = new Individual(false, "gamer", "3", "Minecraft", true, 0, fecha1, fecha2);

        // MultiJ
        fecha1 = new DtFecha(05, 06, 2021, 0, 00, 17);
        fecha2 = new DtFecha(05, 06, 2021, 0, 00, 19);
        Multijugador *pM1 = new Multijugador(true, 2, "4", "Fortnite", true, 120, fecha1, fecha2 /*, listaJugadores*/);
        fecha1 = new DtFecha(06, 06, 2021, 0, 00, 17);
        fecha2 = new DtFecha(06, 06, 2021, 0, 00, 19);
        Multijugador *pM2 = new Multijugador(true, 2, "5", "Fortnite", true, 120, fecha1, fecha2 /*, listaJugadores*/);
        fecha1 = new DtFecha(12, 06, 2021, 0, 00, 20);
        fecha2 = new DtFecha(0, 0, 0, 0, 0, 0);
        Multijugador *pM3 = new Multijugador(false, 1, "6", "Minecraft", false, 0, fecha1, fecha2 /*, listaJugadores*/);

        IKey *keyDesarrollador = new StringKey("KingdomRush");
        d1->setVideoJuego(vj1, keyDesarrollador);
        keyDesarrollador = new StringKey("Fortnite");
        d2->setVideoJuego(vj2, keyDesarrollador);
        keyDesarrollador = new StringKey("Minecraft");
        d3->setVideoJuego(vj3, keyDesarrollador);
        keyDesarrollador = new StringKey("FIFA 21");
        d4->setVideoJuego(vj4, keyDesarrollador);

        vj1->setCategoria(c1);
        vj1->setCategoria(c2);
        vj1->setCategoria(c6);
        vj1->setCategoria(c8);
        vj2->setCategoria(c1);
        vj2->setCategoria(c2);
        vj2->setCategoria(c3);
        vj2->setCategoria(c5);
        vj2->setCategoria(c7);
        vj3->setCategoria(c1);
        vj3->setCategoria(c5);
        vj3->setCategoria(c8);
        vj4->setCategoria(c1);
        vj4->setCategoria(c2);
        vj4->setCategoria(c3);
        vj4->setCategoria(c4);
        vj4->setCategoria(c8);
        vj1->setSuscripcion(sus1);
        vj2->setSuscripcion(sus2);
        vj2->setSuscripcion(sus3);
        vj3->setSuscripcion(sus4);
        vj2->setSuscripcion(sus5);
        vj3->setSuscripcion(sus6);

        Partida *part = dynamic_cast<Partida *>(pI1);

        IKey *keyJuego = new StringKey("KingdomRush");
        vj1->setPartidaParaVideojuego(part, keyJuego);

        keyJuego = new StringKey("KingdomRush");
        vj1->setPartidaParaVideojuego((Partida *)pI2, keyJuego);

        keyJuego = new StringKey("Minecraft");
        vj3->setPartidaParaVideojuego((Partida *)pI3, keyJuego);

        keyJuego = new StringKey("Fortnite");
        vj2->setPartidaParaVideojuego((Partida *)pM1, keyJuego);

        keyJuego = new StringKey("Fortnite");
        vj2->setPartidaParaVideojuego((Partida *)pM2, keyJuego);

        keyJuego = new StringKey("Minecraft");
        vj3->setPartidaParaVideojuego((Partida *)pM3, keyJuego);
    }
}

// Publicar videojuego
void Sistema::publicarVideojuego(Desarrollador *d)
{
    std::string nom, desc;
    float cMensual, cTristral, cAnual, cVitalicio;
    bool deseaAgregar = true;
    int opcionUsuario;
    List *aux_categorias = new List();

    std::cout << "\nIngrese nombre: \e[0;92m";
    std::cin >> nom;
    clearDeDatosDeEntrada();
    StringKey *key = new StringKey(nom);
    if (videojuegos->member(key) == 1)
    {
        std::cout << "\n\e[0;31mEse nombre ya fue seleccionado anteriormente\n\n\e[0m";
    }
    else
    {
        std::cout << "\nIngrese descripcion: \e[0;92m";
        std::cin >> desc;
        clearDeDatosDeEntrada();
        std::cout << "\nIngrese costo menusal: \e[0;92m";
        std::cin >> cMensual;
        clearDeDatosDeEntrada();
        std::cout << "\nIngrese costo trimestral: \e[0;92m";
        std::cin >> cTristral;
        clearDeDatosDeEntrada();
        std::cout << "\nIngrese costo anual: \e[0;92m";
        std::cin >> cAnual;
        clearDeDatosDeEntrada();
        std::cout << "\nIngrese costo vitalicio: \e[0;92m";
        std::cin >> cVitalicio;
        clearDeDatosDeEntrada();

        mostrarCategorias();

        while (deseaAgregar)
        {
            std::string cat;
            std::cout << "\nSeleccione una categoria: ";
            std::cin >> cat;
            clearDeDatosDeEntrada();
            Categoria *aux = obtenerCategoria(cat);

            if (aux != 0)
            {
                if (aux_categorias->member(aux) != 1)
                    aux_categorias->add(aux);
                else // La categoria ya habia sido agregada a la lista auxiliar anteriormente
                    std::cout << "\n\e[0;31mEsa categoria ya fue seleccionada anteriormente\e[0m";
            }
            else
            {
                std::cout << "\n\e[0;31mLa categoria ingresada no es correcta.\n\e[0m";
            }

            std::cout << "\nDesea asignar otra categoria?\e[0m\n1- Si\n2- No\n\nOpcion: \e[0;92m";
            std::cin >> opcionUsuario;
            clearDeDatosDeEntrada();

            if (opcionUsuario == 2)
                deseaAgregar = false;
        }

        std::cout << "\n\e[0;35mDatos del videojuego:";
        std::cout << "\n\e[0;34mNombre: " << nom;
        std::cout << "\n\e[0;37mDescripcion: " << desc;
        std::cout << "\n\e[0;34mCosto Mensual: " << cMensual;
        std::cout << "\n\e[0;37mCosto Trimestral: " << cTristral;
        std::cout << "\n\e[0;34mCosto Anual: " << cAnual;
        std::cout << "\n\e[0;37mCosto Vitalicia: " << cVitalicio;

        mostrarListaCategorias(aux_categorias);

        std::cout << "\nDesea publicar el videojuego?\e[0m\n1- Si\n2- No\n\nOpcion: \e[0;92m";
        std::cin >> opcionUsuario;
        clearDeDatosDeEntrada();

        if (opcionUsuario == 1)
        {
            StringKey *key = new StringKey(nom);
            Videojuego *videojuegoAux = new Videojuego(nom, desc, cMensual, cTristral, cAnual, cVitalicio, aux_categorias);
            videojuegos->add(key, videojuegoAux);
            d->setVideoJuego(videojuegoAux, key);
            videojuegoAux->setDesarrollador(d);
            std::cout << "\n\e[0;35mVideojuego Publicado.\n\n\e[0m";
        }
        else
            delete aux_categorias;
    }
}

void Sistema::mostrarCategorias()
{
    IIterator *it = categorias->getIterator();
    std::cout << "\n\e[0;36mCategorias: \n";
    while (it->hasCurrent())
    {
        Categoria *aux = dynamic_cast<Categoria *>(it->getCurrent());
        std::cout << aux->Getnombre() << std::endl;
        it->next();
    }
    delete it;
    std::cout << "\e[0m\n";
}

Categoria *Sistema::obtenerCategoria(std::string categoria)
{
    StringKey *key = new StringKey(categoria);
    Categoria *aux = dynamic_cast<Categoria *>(categorias->find(key));
    return aux;
}

void Sistema::mostrarListaCategorias(List *lista)
{
    IIterator *it = lista->getIterator();
    std::cout << "\n\e[0;36mCategorias: \n";
    while (it->hasCurrent())
    {
        Categoria *aux = dynamic_cast<Categoria *>(it->getCurrent());
        std::cout << aux->Getnombre() << std::endl;
        it->next();
    }
    delete it;
    std::cout << "\e[0m\n";
}

// TODO: Funcion no es llamada ninguna vez
void Sistema::mostrarListaVideojuegos(List *lista)
{
    IIterator *it = lista->getIterator();

    while (it->hasCurrent())
    {
        Videojuego *aux = dynamic_cast<Videojuego *>(it->getCurrent());
        std::cout << aux->GetNombreVidJ();
        it->next();
    }
    delete it;
}

// Suscribirse a videojuego
void Sistema::suscribirseVideojuego()
{
    int op2, op3, op4, op5;
    bool bandera = true;
    Valor valor;
    MetodoPago metodo;
    mostrarVideojuegos();

    std::string nombreVideojuego;
    std::cout << "\n\e[0mIndicar el nombre del videojuego: \e[0;92m";
    std::cin >> nombreVideojuego;
    clearDeDatosDeEntrada();

    StringKey *key = new StringKey(nombreVideojuego);

    if (videojuegos->member(key) == 1)
    {

        if (jugadorActual->verificarSuscripcion(nombreVideojuego))
        {
            // Ya tiene una suscripcion activa para ese videojuego.

            if (jugadorActual->verificarEsVitalicia(nombreVideojuego))
            {
                // La suscripcion es vitalicia
                std::cout << "\n\e[1;31mLas suscripciones vitalicias no se pueden cancelar.\n\e[0m";
            }
            else
            {
                // La suscripcion no es vitalicia
                std::cout << "\n\e[1;33mDesea cancelar la suscripcion para el videojuego?\e[0m\n1- Si\n2- No\n\nOpcion: \e[0;92m";
                std::cin >> op2;
                clearDeDatosDeEntrada();

                if (op2 == 1)
                {
                    jugadorActual->cancelarSuscripcion(GetUnVideojuego(key));
                    // Avisar a videojuego:
                    Videojuego *auxVideojuego1 = dynamic_cast<Videojuego *>(videojuegos->find(key));
                    auxVideojuego1->cancelarSuscripcion(jugadorActual->Getnick());
                }
            }
        }
        else
        {
            // No tiene una suscripcion para ese videojuego.
            while (true)
            {
                std::cout << "\n\e[1;33mSeleccionar metodo de pago:\e[0m\n1- Tarjeta\n2- Paypal\n\nOpcion: \e[0;92m";
                std::cin >> op3;
                clearDeDatosDeEntrada();

                if (op3 == 1)
                {
                    metodo = Tarjeta;
                    break;
                }
                if (op3 == 2)
                {
                    metodo = Paypal;
                    break;
                }
            }

            while (bandera)
            {
                std::cout << "\n\e[1;33mSeleccionar renovacion:\e[0m\n1- Vitalicia\n2- Mensual\n3- Trimestral\n4- Anual\n\nOpcion: \e[0;92m";
                std::cin >> op4;
                clearDeDatosDeEntrada();

                switch (op4)
                {
                case 1:
                    valor = Vitalicia;
                    bandera = false;
                    break;

                case 2:
                    valor = UnMes;
                    bandera = false;
                    break;

                case 3:
                    valor = TresMeses;
                    bandera = false;
                    break;

                case 4:
                    valor = Anio;
                    bandera = false;
                    break;
                }
            }

            std::cout << "\n\e[1;33mDesea confirmar la suscripcion?\e[0m\n1- Si\n2- No\n\nOpcion: \e[0;92m";
            std::cin >> op5;
            clearDeDatosDeEntrada();

            if (op5 == 1)
            {
                Suscripcion *susAux = new Suscripcion(obtenerFecha(), metodo, valor, false, dynamic_cast<Videojuego *>(videojuegos->find(key)), jugadorActual);
                jugadorActual->setSuscripcion(susAux);

                // Avisar a videojuego:
                Videojuego *auxVideojuego2 = dynamic_cast<Videojuego *>(videojuegos->find(key));
                auxVideojuego2->setSuscripcion(susAux);
            }
        }
    }
    else
    {
        std::cout << "\n\e[1;31mEse videojuego no esta en la lista.\n\e[0m";
    }
}

void Sistema::mostrarVideojuegos()
{
    IIterator *it = videojuegos->getIterator();
    std::cout << "\e[0;35mVideojuegos: \n";
    while (it->hasCurrent())
    {
        Videojuego *aux = dynamic_cast<Videojuego *>(it->getCurrent());
        std::cout << aux->GetNombreVidJ() << std::endl;
        it->next();
    }
    std::cout << "\e[0m";
    delete it;
}

Videojuego *Sistema::GetUnVideojuego(StringKey *nombreVideojuego)
{
    Videojuego *aux = dynamic_cast<Videojuego *>(videojuegos->find(nombreVideojuego));
    return aux;
}

void Sistema::VerInfoVideoJuego()
{
    std::string nom, nombreempresa;
    mostrarVideojuegos();

    std::cout << "\nIngrese nombre del videojuego: \e[0;92m";
    std::cin >> nom;
    clearDeDatosDeEntrada();

    StringKey *key = new StringKey(nom);
    Videojuego *aux = GetUnVideojuego(key);

    if (aux != 0)
    {
        nombreempresa = aux->GetDesarrollador()->Getempresa();
        std::cout << "\n\e[0;34mNombre: " << aux->GetNombreVidJ();
        std::cout << "\n\e[0;37mDescripcion: " << aux->Getdescripcion();
        std::cout << "\n\e[0;34mCosto Mensual: " << aux->GetcostoMensual();
        std::cout << "\n\e[0;37mCosto Trimestral: " << aux->GetcostoTrimestral();
        std::cout << "\n\e[0;34mCosto Anual: " << aux->GetcostoAnual();
        std::cout << "\n\e[0;37mCosto Vitalicia: " << aux->GetcostoVitalicia();
        std::cout << "\n\e[0;34mEmpresa: " << nombreempresa << std::endl
                  << "\e[0m\n";
        aux->getCategorias();
    }
    else
    {
        std::cout << "\n\e[1;33mNombre del videojuego no esta en la lista.\e[1;33m\n";
    }
}

// Iniciar partida
void Sistema::iniciarPartida()
{
    jugadorActual->listarVideojuegosDeJugador();

    std::string nombreVideojuego;
    std::cout << "Indicar el nombre del videojuego: \e[0;92m";
    std::cin >> nombreVideojuego;
    clearDeDatosDeEntrada();

    if (jugadorActual->verificarSuscripcion(nombreVideojuego))
    {
        // Tiene una suscripcion activa para ese videojuego
        StringKey *keyVideojuego = new StringKey(nombreVideojuego);

        int tipoPartida;
        std::cout << "\nSelecciona el tipo de partida:\n1- Individual\n2- Multijugador\n\nOpcion: \e[0;92m";
        std::cin >> tipoPartida;
        clearDeDatosDeEntrada();

        if (tipoPartida == 1)
        {
            // Partida individual
            int esContinuacion;

            std::cout << "\nConfirmar si la partida es una continuacion:\n1- Si\n2- No\n\nOpcion: \e[0;92m";
            std::cin >> esContinuacion;
            clearDeDatosDeEntrada();

            if (esContinuacion == 1)
            {
                jugadorActual->listarPartidasIndividualesFinalizadas(nombreVideojuego);

                int IdPartida;
                std::cout << "\nIndicar ID de la partida a continuar: ";
                std::cin >> IdPartida;
                clearDeDatosDeEntrada();
                bool validacion = jugadorActual->comprobarContinuacion(IdPartida, nombreVideojuego);

                if (validacion == true)
                { // La partida finalizada es valida para continuar
                    int confirmar;
                    std::cout << "\nConfirmar partida:\n1- Si\n2- No\n\nOpcion: \e[0;92m";
                    std::cin >> confirmar;
                    clearDeDatosDeEntrada();

                    if (confirmar == 1)
                    {
                        Individual *partidaAux = new Individual(true, jugadorActual->Getnick(), generarIdPartida(), nombreVideojuego, false, 0, obtenerFecha());
                        jugadorActual->agregarIndividual(partidaAux);

                        Videojuego *videojuegoAux = dynamic_cast<Videojuego *>(videojuegos->find(keyVideojuego));
                        videojuegoAux->agregarIndividual(partidaAux);
                    }
                    else
                    {
                        std::cout << "\n\e[1;31mProceso Cancelado.\n\e[0m";
                    }
                }
                else
                {
                    std::cout << "\n\e[1;31mEl ID ingresado no es valido.\n\e[0m";
                }
            }
            else
            { // No es una continuacion

                int confirmar;
                std::cout << "\nConfirmar partida:\n1- Si\n2- No\n\nOpcion: \e[0;92m";
                std::cin >> confirmar;
                clearDeDatosDeEntrada();

                if (confirmar == 1)
                {
                    Individual *partidaAux = new Individual(false, jugadorActual->Getnick(), generarIdPartida(), nombreVideojuego, false, 0, obtenerFecha());
                    jugadorActual->agregarIndividual(partidaAux);

                    Videojuego *videojuegoAux = dynamic_cast<Videojuego *>(videojuegos->find(keyVideojuego));
                    videojuegoAux->agregarIndividual(partidaAux);
                }
                else
                {
                    std::cout << "\n\e[1;31mProceso Cancelado.\n\e[0m";
                }
            }
        }
        else
        {
            // Partida multijugador
            int seleccionEnVivo;
            bool enVivo;

            std::cout << "\nConfirmar si la partida sera transmitida en vivo:\n1- Si\n2- No\n\nOpcion: \e[0;92m";
            std::cin >> seleccionEnVivo;
            clearDeDatosDeEntrada();

            if (seleccionEnVivo == 1)
            {
                enVivo = true;
            }
            else
            {
                enVivo = false;
            }

            listarJugadoresPorSuscripcion(nombreVideojuego, jugadorActual->Getnick());

            List *listaJugadores = new List();
            int cantJugadores = 0;
            int dejarAgregarNicks = 1;

            while (dejarAgregarNicks == 1)
            {
                std::string nick;
                std::cout << "\nIndicar nick del jugador: \e[0;92m";
                std::cin >> nick;
                clearDeDatosDeEntrada();

                StringKey *key = new StringKey(nick);

                if (confirmarJugadoresPorSuscripcion(nick, nombreVideojuego))
                {
                    // Existe el jugador y tiene una suscripcion activa
                    Jugador *aux = dynamic_cast<Jugador *>(jugadores->find(key));

                    if (listaJugadores->member(aux))
                    {
                        std::cout << "\n\e[1;33mEl jugador ya se encuentra en la lista de seleccion\e[0m\n";
                    }
                    else
                    {
                        listaJugadores->add(aux);
                        cantJugadores = cantJugadores + 1;
                    }
                }
                else
                {
                    std::cout << "\n\e[1;31mEl jugador no existe o no cuenta con una suscripcion activa para el videojuego\n\e[0m";
                }

                std::cout << "\nDesea agregar otro jugador?\n1- Si\n2- No\n\nOpcion: \e[0;92m";
                std::cin >> dejarAgregarNicks;
                clearDeDatosDeEntrada();
            }
            DtFecha *fecha = new DtFecha(0, 0, 0, 0, 0, 0);
            Multijugador *partidaAux = new Multijugador(enVivo, cantJugadores, generarIdPartida(), nombreVideojuego, false, 0, obtenerFecha(), listaJugadores);
            jugadorActual->agregarMultijugador(partidaAux);

            Videojuego *videojuegoAux = dynamic_cast<Videojuego *>(videojuegos->find(keyVideojuego));
            videojuegoAux->agregarMultijugador(partidaAux);
        }
    }
    else
    {
        std::cout << "\n\e[0;31mEs necesario contar con una suscripcion activa para ese videojuego.\n\e[0m";
    }
}

void Sistema::listarJugadoresPorSuscripcion(std::string videojuego, std::string host)
{
    IIterator *it = jugadores->getIterator();

    while (it->hasCurrent())
    {
        Jugador *aux = dynamic_cast<Jugador *>(it->getCurrent());

        if (aux->Getnick() != host && aux->verificarSuscripcion(videojuego))
        {
            // Mostrar todos los jugadores que no sean host y tengan una suscripcion activa
            std::cout << aux->Getnick() << std::endl;
        }

        it->next();
    }
    delete it;
}

bool Sistema::confirmarJugadoresPorSuscripcion(std::string jugador, std::string videojuego)
{
    IIterator *it = jugadores->getIterator();
    bool resultado = false;

    while (it->hasCurrent())
    {
        Jugador *aux = dynamic_cast<Jugador *>(it->getCurrent());

        if (aux->Getnick() == jugador && aux->verificarSuscripcion(videojuego))
        {
            resultado = true;
        }

        it->next();
    }
    delete it;
    return resultado;
}

std::string Sistema::generarIdPartida()
{
    ultimaPartida = ultimaPartida + 1;
    std::stringstream ss;
    ss << ultimaPartida;
    std::string str = ss.str(); // Transforma ultima partida de INT a STRING
    return str;
}

// Eliminar Videojuego
void Sistema::EliminarVideojuego()
{
    std::string nom;
    desarrolladorActual->mostrarVideojuegosDesarrollador();
    std::cout << "\nIngrese nombre del videojuego a eliminar: \e[0;92m";
    std::cin >> nom;
    clearDeDatosDeEntrada();

   StringKey* key = new StringKey(nom);

   bool existeVideojuego = desarrolladorActual->existeEsteVideojuego(key);

   if (existeVideojuego==true){

       Videojuego *aux = desarrolladorActual->obtenerVideojuegodesarrollador(nom);

       if (aux != 0)
       {
           bool tiene = aux->tienepartidas();
           if (tiene == false)
           {
               int op3;
               std::cout << "\n\e[1;33mDesea eliminar el videojuego?\e[0m\n1- Si\n2- No\n\nOpcion: \e[0;92m";
               std::cin >> op3;
               clearDeDatosDeEntrada();
               if (op3 == 1)
               {
                      // Confirma eliminar el videojuego
                      StringKey *key = new StringKey(aux->GetNombreVidJ());
                      desarrolladorActual->EliminarEsteJuego(aux);
                      this->videojuegos->remove(key);
                      std::cout << "\n\e[1;31mVideojuego Eliminado.\e[1;33m\n\n";
                      delete key;
               }
           }
           else
               std::cout << "\n\e[1;33mEse Videojuego aun tiene partidas activas.\e[1;33m\n";
       }
       else
           std::cout << "\n\e[1;33mNombre del videojuego no esta en tu lista.\e[1;33m\n";
   } else {
      std::cout << "\n\e[1;33mNombre del videojuego no esta en tu lista.\e[1;33m\n";
   }
}

void Sistema::imprimirMenuDesarrollador()
{
    int opcionUsuario;
    bool bandera = true;
    while (bandera == true)
    {
        Sistema::imprimirTextoDelDesarrollador();
        std::cin >> opcionUsuario;
        clearDeDatosDeEntrada();

        try
        {
            switch (opcionUsuario)
            {
            case 1: // Publicar Videojuego
            {
                publicarVideojuego(desarrolladorActual);
                break;
            }
            case 2: // Eliminar Videojuego
            {
                EliminarVideojuego();
                break;
            }
            case 3: // Ver Info Juego
            {
                VerInfoVideoJuego();
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

void Sistema::imprimirMenuJugador(Jugador *jugadorActual)
{
    int opcionUsuario;
    bool bandera = true;

    while (bandera == true)
    {
        Sistema::imprimirTextoDelJugador();
        std::cin >> opcionUsuario;
        clearDeDatosDeEntrada();

        try
        {
            switch (opcionUsuario)
            {
            case 1: // Suscribirse a videojuego
            {
                suscribirseVideojuego();
                break;
            }
            case 2: // Iniciar partida
            {
                iniciarPartida();
                break;
            }
            case 3: // Finalizar partida
            {
                finalizarPartida();
                break;
            }
            case 4: // Ver informacion de videojuego
            {
                VerInfoVideoJuego();
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

void Sistema::finalizarPartida()
{
    string nom;
    std::cout << "\nSeleccione la partida a finalizar: \n\nOpcion: \e[0;92m";
    jugadorActual->mostrarPartidasNoFinalizadas();
    std::cin >> nom;
    clearDeDatosDeEntrada();

    StringKey *key = new StringKey(nom);

    if (jugadorActual->esMultiJugador(key)==true){
        //Es multijugador
	Multijugador *part = dynamic_cast<Multijugador *>(jugadorActual->getMultijugador(key));
	part->setFinalizado(true);
	part->setFechaFin(obtenerFecha());
	int duracion = calcularDiferenciaFecha(part->getFechaInicio());
	part->setDuracionPartida(duracion * part->getCantJugadores());
    }

    if (jugadorActual->esIndividual(key)==true){
        //Es individual
	Individual *part = dynamic_cast<Individual *>(jugadorActual->getIndividual(key));
	part->setFinalizado(true);
	part->setFechaFin(obtenerFecha());
	int duracion = calcularDiferenciaFecha(part->getFechaInicio());
	part->setDuracionPartida(duracion);
    }

}

void Sistema::imprimirTextoPrincipal()
{
    std::cout << "\n\e[0;92mBienvenido - Elija una opcion\e[0m:";
    std::cout << "\n\e[0;92m1)\e[0m Alta de usuario.\n";
    std::cout << "\e[0;92m2)\e[0m Iniciar sesion.\n";
    std::cout << "\e[0;92m3)\e[0m Cargar datos de prueba.\n";
    std::cout << "Pulse \e[0;92m4\e[0m para salir.\n\nOpcion: \e[0;92m";
}

void Sistema::imprimirTextoDelDesarrollador()
{
    std::cout << "\n\e[0;92mMenu de Desarrollador - Elija una opcion\e[0m:";
    std::cout << "\n\e[0;92m1)\e[0m Publicar videojuego.\n";
    std::cout << "\e[0;92m2)\e[0m Eliminar videojuego.\n";
    std::cout << "\e[0;92m3)\e[0m Ver Informacion de un videojuego.\n";
    std::cout << "Pulse \e[0;92m4\e[0m Para salir.\n\nOpcion: \e[0;92m";
}

void Sistema::imprimirTextoDelJugador()
{
    std::cout << "\n\e[0;92mMenu de Jugador - Elija una opcion\e[0m:";
    std::cout << "\n\e[0;92m1)\e[0m Suscribirse a videojuego.\n";
    std::cout << "\e[0;92m2)\e[0m Iniciar partida.\n";
    std::cout << "\e[0;92m3)\e[0m Finalizar partida.\n";
    std::cout << "\e[0;92m4)\e[0m Ver informacion de un videojuego.\n";
    std::cout << "Pulse \e[0;92m5\e[0m para salir.\n\nOpcion: \e[0;92m";
}

void Sistema::clearDeDatosDeEntrada()
{
    std::cin.clear();
    std::cin.ignore(10000, '\n');
    std::cout << "\e[0m";
}

Sistema::~Sistema() {}
